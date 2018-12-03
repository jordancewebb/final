// CSCI 2530
// Assignment: 8
// Author:     Jordance Webb
// File:       trace.cpp
// Tab stops:  2

// This program is a tracer, that is, it is used to help keep track of
// events in memory for the huffman program.

#include <cstdio>
#include <string.h>
#include <cctype>
#include "trace.h"
using namespace std;


int tracelevel = 0;

void setTrace(int argc, char* argv[])
{
	for(int count = 0; count < argc; count++)
	{
	printf("%s \n", argv[count]);
	if(strcmp(argv[count], "-t"))
	{
	tracelevel = 1;
	}
	else
	{
	tracelevel = 0;
	}
	}	
}

//printDescription(character) prints the description of character to the
//standard output in a format comprehensible to the user.
void printDescription(unsigned character)
{
	if(isprint(character))
	{
	printf("%c, ", character);
	}
	else
	{
	switch(character)
	{
	case '\n':	
		printf("newLine,\n");
		break;
	case ' ':
		printf("space, ");
		break;
	case '\t':
		printf("tab, ");
		break;
	default:
		printf("/%i", character);
		}
	}
}

//showFreq(charArray) prints to the standard output the frequency of 
//characters that appear once or more in a file;
void showFreq(int* charArray)
{
	if(tracelevel == 1)
	{
	for(int i = 0; i < 256; i++)
	{
	if(charArray[i] > 0)
	{
	printf("%c\t:\t%i\n",i + 'o', charArray[i]);
	}
	}
	} 
}

//printTree(tree) prints a tree to the standard output
void printTree(Tree tree)
{
if(tree -> node != NULL)
{
	if(tree -> nodekind == "leaf")
	{
	printDescription(tree -> ch);
	}
	else
	{
	printf("(");
	printTree(tree -> left);
	printf(",");
	printTree(tree -> right);
	printf(")");
	}
}

//showCode(Code) prints to the standard output the code from the code
//array
void showCode(String* Code)
{
for(int i == 0; i < 256; i++)
{
	for(int j = 0; j < strlen(Code[i]); j++)
	{
	printDesccription(j[i]);
	}
}
}
