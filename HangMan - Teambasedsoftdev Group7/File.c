//Liam
//Group 7
//HangMan
#define _CRT_SECURE_NO_WARNINGS
#define MAXLNS 100
#define WRDPRLN 128

#include "Header.h"

int FileEncrypt() {
		char ch;
		FILE* fp, * fpt;

		// open read file as read
		fp = fopen("Words.txt", "r");
		if (fp == NULL) {
			printf("error");
			exit(0);
		}

		// open temp file as write
		fpt = fopen("Temp.txt", "w");
		if (fpt == NULL) {
			printf(" error ");
			fclose(fp);
			exit(0);
		}

		//read the file and put the encrypted words into temp
		while (1) {
			ch = fgetc(fp);
			if (ch == EOF) {
				break;
			} else {
				ch = ch + 100; // change the ascii value of the letter
				fputc(ch, fpt);
			}
		}

		//save the files
		fseek(stdin, 0, SEEK_END);
		fclose(fp);
		fseek(stdin, 0, SEEK_END);
		fclose(fpt);

		//reopen the word file as write
		fp = fopen("Words.txt", "w");
		if (fp == NULL)	{
			printf("error");
			exit(0);
		}

		//reopen the temp file as read
		fpt = fopen("Temp.txt", "r");
		if (fpt == NULL) {
			printf("error");
			fclose(fp);
			exit(0);
		}

		//move the encrypted text from temp to word file
		while (1) {
			ch = fgetc(fpt);
			if (ch == EOF) {
				break;
			} else {
				fputc(ch, fp);
			}
		}

		//save the files
		fseek(stdin, 0, SEEK_END);
		fclose(fp);
		fseek(stdin, 0, SEEK_END);
		fclose(fpt);

}



int FileDecrypt() {
	char ch;
	FILE* fp, * fpt;

	// open read file as read
	fp = fopen("Words.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	// open temp file as write
	fpt = fopen("Temp.txt", "w");
	if (fpt == NULL) {
		printf(" error ");
		fclose(fp);
		exit(0);
	}

	//read the file and put the encrypted words into temp
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) {
			break;
		}
		else {
			ch = ch - 100; // change the ascii value of the symbol
			fputc(ch, fpt);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fp);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

	//reopen the word file as write
	fp = fopen("Words.txt", "w");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//reopen the temp file as read
	fpt = fopen("Temp.txt", "r");
	if (fpt == NULL) {
		printf("error");
		fclose(fp);
		exit(0);
	}

	//move the encrypted text from temp to word file
	while (1) {
		ch = fgetc(fpt);
		if (ch == EOF) {
			break;
		}
		else {
			fputc(ch, fp);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fp);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

}

char FileGetWord() {

	FILE* fp;

	//2d array where MAXLNS is the max lines the file can have
	//2d array where WRDLNS is the max chars per line on the file
	char line[MAXLNS][WRDPRLN];

	//open the file as read
	fp = fopen("Words.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//start at line 0 and go through all the words on the line
	int i = 0;
	while (fgets(line[i], WRDPRLN, fp)) {
		// save the contents of that line up until the next line
		line[i][strlen(line[i]) -1] = '\0'; 
		i++;
	}


	int nlines = i; // total number of lines

	//reset the line the program is on and save file
	fseek(stdin, 0, SEEK_END);
	fclose(fp);

	//create the random generator to find pick a word from the array

	srand(time(0)); // seed the RNG

	int RNG = rand() % nlines;

	/* NOW I NEED TO RETURN THE 2D ARRAY BACK TO MAIN */

	printf("Random Word: %s\n", line[RNG]);

}


char FileRemoveWord() {

	FILE* fp, *fpt;

	int line_num = 1;
	int find_result = 0;
	char temp[512];

	char *delword;
	char word = { "a" };

	//Open word file as read
	fp = fopen("Words.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	// find what line the word is on
	int i = 0;

	//save files and reset position
	fseek(stdin, 0, SEEK_END);
	fclose(fp);

	//set the line needed to be deleted
	int del = i;
	i = 0; // reset the loop
	char ch;

	//Open word file as read
	fp = fopen("Words.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//open Temp file as write
	fpt = fopen("Temp.txt", "w");
	if (fpt == NULL) {
		printf("error");
		fclose(fp);
		exit(0);
	}

	ch = getc(fp);
	if (ch != EOF) { 
		i = 1;
	}

	while (1) {

		ch = getc(fp);

		if (del != i) { // if the line to delete is not i copy the file
			putc(ch, fpt);
		}

		if (ch == '\n') { // keep track of new lines
			i++;
		}

		if (ch == EOF) {
			break;
		}
	}

	//save files and reset position
	fseek(stdin, 0, SEEK_END);
	fclose(fp);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

	//reopen the word file as write
	fp = fopen("Words.txt", "w");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//reopen the temp file as read
	fpt = fopen("Temp.txt", "r");
	if (fpt == NULL) {
		printf("error");
		fclose(fp);
		exit(0);
	}

	//move the updated text from temp to word file
	while (1) {
		ch = fgetc(fpt);
		if (ch == EOF) {
			break;
		}
		else {
			fputc(ch, fp);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fp);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

}