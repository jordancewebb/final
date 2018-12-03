// CSCI 2530
// Assignment: 8
// Author:     Jordance Webb
// File:       trace.h
// Tab stops:  2

// This is a header file for trace.cpp. It stores prototypes for
// the functions setTrace(argc, argv), showFreq(charArray), and 
// showCode(Code).It stores, as well, public integer tracelevel
// which controls whether or not the user wishes to use the
// functions prototyped here. 


#include <cstdio>
#include <cctype>
using namespace std;

extern int tracelevel;
void setTrace(int argc, char* argv[]);
void showFreq(int* charArray);
void showCode(String* Code);

