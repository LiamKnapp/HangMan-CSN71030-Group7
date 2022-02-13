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

int FileGetWord() {

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
		line[i][strlen(line[i]) - 1] = '\0';
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

	return(line[RNG]);

}


int FileRemoveWord(char delword[]) {

	FILE* fp, *fpt;

	int i = 1;
	char temp[WRDPRLN];
	
	//Open word file as read
	fp = fopen("Words.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//find what line the word is on
	while (fgets(temp, WRDPRLN, fp) != NULL) {
		if ((strstr(temp, delword)) != NULL) {
			printf("A match found on line: %d\n", i);
			printf("\n%s\n", temp);
			break;
		}
		i++;
	}

	int del = i;

	//save files and reset position
	fseek(stdin, 0, SEEK_END);
	fclose(fp);

	//set the line needed to be deleted
	i = 1;
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

	//remove the line
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