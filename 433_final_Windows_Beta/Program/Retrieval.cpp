///////////////////////////////////////////////////////////////////////////////////////
//
// Author: Robert Luk
// Year: 2010
// Robert Luk (c) 2010 
//
// Interactive Retrieval using the Integrated Inverted Index Class:
// This software is made available only to students studying COMP433 (Information
// Retreieval). It should not be used or distributed without consent by the author.
//
////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "IInvFile.h"
// Integrated Inverted Index (see lecture notes on Implementation)
IInvFile InvFile;

int main(int argc, char *argv[]) {
	char cmd[10000];
	int id[10000];
	int count = 0;
	FILE * fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Cannot open argv[1]\r\n", argv[1]);
		return 0;
	}
	FILE * fp2 = fopen(argv[5], "wb+");
	if (fp == NULL) {
		printf("Cannot open argv[1]\r\n", argv[1]);
		return 0;
	}
	// Initialize the Hash Table
	InvFile.MakeHashTable(13023973);
	InvFile.Load(argv[2]);
	InvFile.LoadDocRec(argv[3]);
	InvFile.ReadTRECID(argv[4]);

	while (fgets(cmd, 1000, fp) != NULL) {
		if (cmd[0] == '\r' || cmd[0] == '\n') {
			continue;
		}
		sscanf(cmd, "%d", &(id[count]));
		for (int i = 0; i < 3; i++) {
			if (cmd[i] >= '0' && cmd[i] <= '9') {
				cmd[i] = ' ';
			} else {
				break;
			}
		}
		// Start interactive retrieval
		InvFile.Search(cmd, id[count], fp2);
		count++;
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
