// CSCI 2530
// Assignment: 6
// Author:     Jordance Webb
// File:       pqueue.h
// Tab stops:  2

// **Say what this program does here.  (replace this comment)**


#include <cstdio>
#include <cstdlib>
using namespace std;

 #include "tree.h"
  typedef Tree ItemType;
  typedef int  PriorityType;

struct PQCell;

//PriorityQueue is a sturcture that holds the first ponter to a
//linked list of PQCells
struct PriorityQueue
{
	PQCell* First;

		PriorityQueue()
		{
			First = NULL;
		}
};

bool isEmpty(const PriorityQueue& pQueue);
void insert(PriorityQueue& pQueue, ItemType thisItem, PriorityType priority);

typedef void (*ItemPrinter)(ItemType);
typedef void (*PriorityPrinter)(PriorityType);

void printPriorityQueue(const PriorityQueue& pQueue, ItemPrinter pi,
PriorityPrinter pp);
void remove(PriorityQueue& q, ItemType& x, PriorityType& p);
  
