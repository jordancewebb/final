// CSCI 2530
// Assignment: 8
// Author:     Jordance Webb
// File:       unhuffman.cpp
// Tab stops:  2

// This program takes information from a binary file compressed using 
// huffman's algorithm, decompresses it, and prints the result to a
// separate file

#include <cstdio>
#include "trace.h"
#include "tree.h"
#include "pqueue.h"
#include "binary.h"
using namespace std;

//unHuffTree(file) returns the tree who's description is given in the structure 
//to which file points.
Tree unHuffTree(BFILE* file)
{
	if(readBit(file) == 1)
	{
	return new Node(readByte(file));
	}
	else
	{
	Node left = new Node(unHuffTree(file -> left));
	Node right = new Node(unHuffTree(file -> right));
	return new Node(left, right);	
	}
} 

//readCode(tree, file) reads the code for a character from binary file 'file'
//and returns the character as an integer. If EOF is encountered in the 
//binary file, readCode will return EOF
int readCode(Tree tree, BFILE* file)
{
	if(tree -> kind == "leaf")
	{
	return tree -> ch;
	}
	else
	{
		int bit = readbit(file);
		if(bit == 0)
		{
		return readCode(tree -> left, file);
		}
		else if(bit == 1)
		{
		return readCode(tree -> right, file);
		}
		else if(bit == -1)
		{
		return EOF;
		}
	}
}

//writeUncompression(readFile, writefile, tree) uncompresses the character
//codes from binary file readFile and writes them to uncompressed file 
//writefile 
void writeUncompression(BFILE* readFile, const char* writeFile, Tree tree)
{
	while(readCode(tree, readFile != EOF))
	{
	putc(readCode(tree, readFile), writeFile);
	}
}
int main(int argc, char* argv[])
{
	setTrace(argc, argv);
	BFILE* file = openBinaryFileRead(argv[argc - 1]);
	Tree tree = unHuffTree(file);
	if(tracelevel == 1)
	{
	printTree(tree);
	}
  return 0;
}
