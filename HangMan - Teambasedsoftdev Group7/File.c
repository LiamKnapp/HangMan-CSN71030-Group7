//Liam
//Group 7
//HangMan
#define MAXLNS 100
#define WRDPRLN 128

#include "Header.h"

int FileEncrypt(int lang) {

	char ch;
	FILE* fp, * fpt, * fps;

	// predefine the file names so we can use the lang efficently
	char* filename[3] = { "NA", "Words.txt", "FrenchWords.txt" };
	char* filesavewords[3] = { "NA", "SaveWords.txt", "SaveFrenchWords.txt" };

	// open read file as read in english
	fp = fopen(filename[lang], "r");
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
			ch = ch + 100; // change the ascii value of the letter
			fputc(ch, fpt);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fp);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

	// open word file as write
	fp = fopen(filename[lang], "w");
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

	//open the savewords file as read
	fps = fopen(filesavewords[lang], "r");
	if (fps == NULL) {
		printf("error");
		exit(0);
	}

	// open temp file as write
	fpt = fopen("Temp.txt", "w");
	if (fpt == NULL) {
		printf(" error ");
		fclose(fps);
		exit(0);
	}

	//read the file and put the encrypted words into temp
	while (1) {
		ch = fgetc(fps);
		if (ch == EOF) {
			break;
		}
		else {
			ch = ch + 100; // change the ascii value of the letter
			fputc(ch, fpt);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fps);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

	// open saveword file as write
	fps = fopen(filesavewords[lang], "w");
	if (fps == NULL) {
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

	//move the encrypted text from temp to saveword file
	while (1) {
		ch = fgetc(fpt);
		if (ch == EOF) {
			break;
		}
		else {
			fputc(ch, fps);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fps);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);
}



int FileDecrypt(int lang) {

	char ch;
	FILE* fp, * fpt, * fps;

	// predefine the file names so we can use the lang efficently
	char* filename[3] = { "NA", "Words.txt", "FrenchWords.txt" };
	char* filesavewords[3] = { "NA", "SaveWords.txt", "SaveFrenchWords.txt" };

	// open read file as read
	fp = fopen(filename[lang], "r");
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
	fp = fopen(filename[lang], "w");
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

	//open the savewords file as read
	fps = fopen(filesavewords[lang], "r");
	if (fps == NULL) {
		printf("error");
		exit(0);
	}

	// open temp file as write
	fpt = fopen("Temp.txt", "w");
	if (fpt == NULL) {
		printf(" error ");
		fclose(fps);
		exit(0);
	}

	//read the file and put the encrypted words into temp
	while (1) {
		ch = fgetc(fps);
		if (ch == EOF) {
			break;
		}
		else {
			ch = ch - 100; // change the ascii value of the letter
			fputc(ch, fpt);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fps);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);

	// open saveword file as write
	fps = fopen(filesavewords[lang], "w");
	if (fps == NULL) {
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

	//move the encrypted text from temp to saveword file
	while (1) {
		ch = fgetc(fpt);
		if (ch == EOF) {
			break;
		}
		else {
			fputc(ch, fps);
		}
	}

	//save the files
	fseek(stdin, 0, SEEK_END);
	fclose(fps);
	fseek(stdin, 0, SEEK_END);
	fclose(fpt);
}

char* FileGetWord(int lang) {

	FILE* fp;

	// predefine the file names so we can use the lang efficently
	char* filename[3] = { "NA", "Words.txt", "FrenchWords.txt" };

	//2d array where MAXLNS is the max lines the file can have
	//2d array where WRDLNS is the max chars per line on the file
	char line[MAXLNS][WRDPRLN];

	//open the file as read
	fp = fopen(filename[lang], "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//start at line 0 and go through all the words on the line
	int i = 0;
	char ch;

	while (fgets(line[i], WRDPRLN, fp)) {
		//check to see if it is the end of the file
		if (line[i][strlen(line[i])] == EOF) {
			break;
		}

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

	return(line[RNG]);
}

int FileRemoveWord(char delword[], int lang) {

	FILE* fp, * fpt, * fps;

	// predefine the file names so we can use the lang efficently
	char* filename[3] = { "NA", "Words.txt", "FrenchWords.txt" };
	char* filesavewords[3] = { "NA", "SaveWords.txt", "SaveFrenchWords.txt" };

	int i = 1;
	char temp[WRDPRLN];

	//Open word file as read
	fp = fopen(filename[lang], "r");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	//find what line the word is on
	while (fgets(temp, WRDPRLN, fp) != NULL) {
		if ((strstr(temp, delword)) != NULL) {
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
	fp = fopen(filename[lang], "r");
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

	fps = fopen(filesavewords[lang], "a");
	if (fps == NULL) {
		printf("error");
		fclose(fp);
		fclose(fpt);
		exit(0);
	}

	//remove the line
	while (1) {

		ch = getc(fp);

		if (del != i) { // if the line to delete is not i copy the file
			putc(ch, fpt);
		}

		if (del == i) {
			putc(ch, fps);
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
	fseek(stdin, 0, SEEK_END);
	fclose(fps);

	//reopen the word file as write
	fp = fopen(filename[lang], "w");
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


int FileReuseWords(int lang) {
	FILE* fp, * fps;

	// predefine the file names so we can use the lang efficently
	char* filename[3] = { "NA", "Words.txt", "FrenchWords.txt" };
	char* filesavewords[3] = { "NA", "SaveWords.txt", "SaveFrenchWords.txt" };
	char ch;

	//open main word file as append
	fp = fopen(filename[lang], "a");
	if (fp == NULL) {
		printf("error");
		exit(0);
	}

	fps = fopen(filesavewords[lang], "r");
	if (fps == NULL) {
		printf("error");
		fclose(fp);
		exit(0);
	}

	while (1) {
		ch = fgetc(fps);
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
	fclose(fps);

	fps = fopen(filesavewords[lang], "w");
	if (fps == NULL) {
		printf("error");
		exit(0);
	}

	while (1) {
		ch = fgetc(fps);
		if (ch == EOF) {
			break;
		}
		else {
			fputc('\n', fps);
		}
	}
	fseek(stdin, 0, SEEK_END);
	fclose(fps);

}