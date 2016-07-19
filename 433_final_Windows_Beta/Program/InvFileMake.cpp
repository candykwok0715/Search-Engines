///////////////////////////////////////////////////////////////////////////////////////
//
// Author: Robert Luk
// Year: 2010
// Robert Luk (c) 2010 
//
// Convert data into inverted file format using the Integrated Inverted Index class:
// This software is made available only to students studying COMP433 (Information
// Retreieval). It should not be used or distributed without consent by the author.
//
////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include "IInvFile.h"

// Integrated Inverted Index (see lecture notes on Implementation)
IInvFile InvFile;

int main(int argc, char *argv[]) {
	FILE * fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Cannot open %s\r\n", argv[1]);
		return 0;
	}

	// Initialize the Hash Table
	InvFile.MakeHashTable(13023973);
	char tmp[10000], str[1000];
	int docid, loc;
	while (fgets(tmp, 1000, fp) != NULL) {
		// Get the stem, the document identifier and the location
		sscanf(tmp, "%s %d %d", &(str[0]), &docid, &loc);

		// Add posting into the Integrated Inverted index
		// See lecture notes on Implementation
		InvFile.Add(str, docid, 1);
	}

	InvFile.Save(argv[2]);
	printf("Saved %\s\r\n", argv[2]);
	InvFile.Clear();
	fclose(fp);
	return 0;
}

