// CSCI 2530
// Assignment: 8
// Author:     Jordance Webb
// File:       huffman.cpp
// Tab stops:  2

// This program uses huffman's algorithm to compress information from a 
//file and saves it to a separate binary file


#include <cstdio>
#include "trace.h"
#include "tree.h"
#include "pqueue.h"
#include "binary.h"
using namespace std;
typedef char* String;


// openInFile(fileName) opens fileName for reading and returns
//open file fileName
FILE* openInfile(const char* fileName)
{
  FILE* file = fopen(fileName, "r");

  if(file == NULL)
  {
    printf("Cannot open file %s\n", fileName);
  }  
  return file;
}

//openOutfile(fileName) opens fileName for writing and returns
//open file fileName
FILE* openOutfile(const char* fileName)
{
  FILE* file = fopen(fileName, "w");
 
  if(outf == NULL)
  {
    printf("Cannot open file %s\n", fileName);
  }
  return file;
}

//zeroOut(charArray) sets all elements of charArray to 0 and returns charArray.
int* zeroOut(int* charArray)
{
	for(int count = 0; count < 256; count++)
	{
	charArray[count] = 0;
	}
	return charArray;
}

//getCharFreq(file, charArray) scans each character in file and records the
//frequencies of each character that appears into an array of 256 corresponding
//integer values. If file contains no characters,the function will return 
//false.
bool getCharFreq(char* file, int* charArray)
{
	charArray = zeroOut(charArray);
	FILE* f = fopen(file, "r");
	int letter = getc(f);
	
	if(f == NULL)
	{
	return false;
	}
	else
	{
		while(letter != -1)
		{
		charArray[letter]++;
		letter = getc(f);
		}
	fclose(f);\
	return true;
	}
}

//initializeQueue(Queue, charArray) populates priority queue Queue with trees
//containing a single node: a character represented by the indices of 
//charArray with a frequency exceeding 0.
void initializeQueue(PriorityQueue Queue, int* charArray)
{
for(int count = 0; count < 256; count++)
	{
		if(charArray[count] > 0)
		{
		Tree t = new Node(count + '0');
		insert(Queue, t, charArray[count]);
		}
	}
}

//oneTree(Queue) is a helper function that returns true if priority queue
//Queue contains only one tree and false otherwise.
bool oneTree(PriorityQueue Queue)
{
	if(Queue.first -> next != NULL)
	{
	return true;	
	}
	return false;
}

//combine(Queue) is a helper function that combines all trees in priority Queue 
//Queue based on the huffman algorithm until a single tree remains

void combine(PriorityQueue Queue)
{
	PQCell* pointL = Queue.First;
	PQCell* pointR = Queue.First -> next;

	while(pointL -> next != NULL)
	{
	Tree t = new Node(pointL -> Tree, point -> Tree);
	insert(Queue, t, pointL->priority + pointR->priority);
	if(pointR -> next != NULL)
	{
	PQCell* DPointL = pointL;
	PQCell* DPointR = pointR;
	PointL = PointL -> next -> next;
	PointR = PointR -> next -> next;	
	delete DPointL;
	delete DPointR;
	} 
	delete pointL;
	delete pointR;
	}
	}
}

//buildCode(tree, Code, prefix) adds the 'code' of all leaves as a null-
//terminated string to array 'Code'.
void buildCode(Tree tree, String* Code, String prefix)
{
	if(tree -> kind == "leaf")
	{
	for(int i = 0; i < 256; i++)
	{
	if(tree -> ch == i + '0')
	{
	Code[i] = prefix;
	strcat(Code[i], tree -> ch);
	strcat(Code[i], "\0");
	}
	}
	else{
	String preL = prefix;
	String preR = prefix;
	strcat(preL, "0");
	strcat(preR, "1");
	buildCode(tree -> right, Code, preR);
	buildCode(tree -> left, Code, preL);
	}
}
//buildTree(charArray)returns a huffman tree based on the array of character
// frequencies
Tree buildTree(int* charArray)
{
	PriorityQueue Queue = new priorityQueue();
	initializeQueue(Queue, charArray);
	if(!oneTree)
	{
	combine(Queue);
	}
	return Queue -> first -> Tree;
}

//writeBinaryTree(tree, file) prints Tree tree's description to open binary 
//file 'file'
void writeBinaryTree(Tree tree, BFILE* file)
{
	if(tree -> kind == "leaf")
	{
	writeBit(file,1);
	writeByte(file, tree -> ch);
	}
	else
	{
	writeBit(file,0);
	writeBinaryTree(file, tree -> left);
	writeBinaryTree(file, tree -> right);
	}
}

//writeCode(Code, readFile, writeFile) reads from file readFile and 
//writes the corresponding code to binary file writeFile
void writeCode(String* Code, const* readFile, BFILE* writeFile)
{
	FILE* file = openInFile(readFile);
	int* characters = new int [256];
	bool charFreq = getCharFreq(file, charArray);

	for(int i = 0; i < 256; i++)
	{
		if(characters[i] > 0)
		{
		String currCode = Code[i];
		for(int j = 0; currCode[j] != '\0'; j++)
		{
			if(currCode[j] == '1')
			{
			writebit(writeFile, 1);
			}
			else if(currCode[j] == '0')
			{
			writebit(writeFile, 0);
			}
		}
		}
	}
}
int main(int argc, char* argv[])
{
	setTrace(argc, argv);
	
	int* charArray = new int[256];
	FILE* fileA = openInFile(argv[argc-2]);
	FILE* fileB = openOutFile(argv[argc-1]);
	
	bool charFreq = getCharFreq(fileA, charArray);
	if(charFreq == false)
	{
	printf("file %s could not be read", fileA);
	}
	else{
	Tree priorityTree = buildTree(charArray);
	String* Code = new String [256];
	buildCode(priorityTree, Code, priorityTree -> ch);
	if(tracelevel == 1)
	{
	showFreq(charArray);
	}
	}
	fclose(fileA);
	fclose(fileB);
  return 0;
}

