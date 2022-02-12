//Liam
//Group 7
//HangMan
#define _CRT_SECURE_NO_WARNINGS
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
		fclose(fp);
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
		fclose(fp);
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
	fclose(fp);
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
	fclose(fp);
	fclose(fpt);

}