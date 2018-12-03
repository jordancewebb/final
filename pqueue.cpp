// CSCI 2530
// Assignment: 6
// Author:     Jordance Webb
// File:       pqueue.cpp
// Tab stops:  2
// This program is a module containing an interface of operations to be
//performed on a linked list.

#include <cstdlib>
#include <cstdio>
#include "pqueue.h"

using namespace std;

//PQCell is a structure to be useds as a cell in a linked list, it 
//contains a priority, an item, and a PQCell pointer.
struct PQCell
{
	ItemType item;
	PriorityType priority;
	PQCell* next;
};

//isEmpty(pQueue) returns true if PriorityQueue pQueue points to
//an empty list
bool isEmpty(const PriorityQueue& pQueue)
{
	return pQueue.First == NULL;
}

//insertCell(List, item, priority) inserts item x with priority p into linked
//list List in the correct spot.
void insertCell(PQCell*& List, ItemType item, PriorityType thisPriority)
{
	if(List == NULL || List -> priority <= thisPriority)
	{
	PQCell* newList = new PQCell;
	newList -> item = item;
        newList -> priority = thisPriority;
        newList -> next = List;
        List = newList -> next;
	
	}
	else
	{
		insertCell(List -> next, item, thisPriority);
	}
}

//insert(pQueue, thisItem, priority) inserts Item thisItem into PriorityQueue
//pQueue with PriorityType priority
void insert(PriorityQueue& pQueue, ItemType thisItem, PriorityType priority)
{
	insertCell(pQueue.First, thisItem, priority);
}

//printPriorityQueue(pQueue, pi, pp) is a method used for debugging which
//prints the contents of priority queue pq to the standard output.
void printPriorityQueue(const PriorityQueue& pQueue, ItemPrinter pi,
PriorityPrinter pp)
{
	if(!isEmpty(pQueue))
	{
	return;
	}

	PQCell* pointer = pQueue.First;
	while(pointer != NULL)
	{	
	pi(pointer ->next -> item);
	printf("\t");
	pp(pointer ->next -> priority);
	printf("\n");
	pointer = pointer -> next;
	}
}

  void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
  {
		if(!isEmpty(q))
		{
     x = q.First -> item;
     p = q.First -> priority;

		PQCell toBeDeleted = *q.First;
		q.First = q.First -> next;
		delete [] &toBeDeleted;
		}
	else
	{
	exit(0);	
	}
  }
