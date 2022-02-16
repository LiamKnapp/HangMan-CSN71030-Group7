//Liam , Will, Nihchal, Minh
//Group 7
//HangMan
#define _CRT_SECURE_NO_WARNINGS

#include "DataPackages.h"
#include "Header.h"

int main() {
	/* Liam: */	

	/* This is language selection stuff */
	int lang;
mark:									
	menu_language();
	scanf("%d", &lang);
	switch (lang)
	{
	case 1:
		menu();
		break;
	case 2:
		menu_French();
		break;
	case 3:
		break;
	default:
		printf("Error Input. Do you want to input again\n");
		int temp;
		printf("1. Yes\n");
		printf("2. No\n");
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
			goto mark;
		case 2:
			break;
		default:
			break;
		}
		break;
	}
	
	/* THIS IS THE RANDOM WORD THE USER WILL BE TRYING TO GUESS */
	char *wordtoguess = malloc(sizeof (char*));

	/* THIS IS ALL THE FUNCTIONS FOR FILE STUFF */
	//FileDecrypt(lang);//decrypt the word file
	//wordtoguess = FileGetWord(lang); // get random word

	//REMOVE THIS WHEN COMPLETED THIS IS TO TEST IF WORD IS BEING RETURNED
	/*
	if (lang == 1) {
		printf("\nRandom word: %s\n", wordtoguess);
	}
	else {
		printf("\nMot aleatoire: %s\n", wordtoguess);
	}

	FileRemoveWord(wordtoguess, lang); // remove word
	*/
	//FileEncrypt(lang); // encrypt the word file


	//// Minh: Create the trees for the program to store the data and sort it from highest to lowest
	//BSTInit();									//Initialize the BST
	//GameInfor* p = NULL;						//Define node p as null
	//p = (GameInfor*)malloc(sizeof(GameInfor));


	return 0;
}