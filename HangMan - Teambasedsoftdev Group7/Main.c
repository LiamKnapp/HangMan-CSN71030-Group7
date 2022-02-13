//Liam , Will, Nihchal, Minh
//Group 7
//HangMan
#define _CRT_SECURE_NO_WARNINGS

#include "DataPackages.h"
#include "Header.h"

int main() {

	//char delword = { "at" };
	//FileDecrypt();//decrypt the word file
	char* a = FileGetWord();
	printf("%s",a); // get random word

	//FileRemoveWord(delword); // remove word
	//FileEncrypt(); // encrypt the word file

	//printf("%s", &wordguess);

	//// Minh: Create the trees for the program to store the data and sort it from highest to lowest
	//BSTInit();									//Initialize the BST
	//GameInfor* p = NULL;						//Define node p as null
	//p = (GameInfor*)malloc(sizeof(GameInfor));

	return 0;
}