//Liam, Will, Nihchal, Minh
//Group 7
//HangMan

#include "DataPackages.h"
#include "Header.h"

int main() {

	/* Liam & Minh: */	
	/* language selection stuff: */
	

mark:
	printf("---------------------------------------\n");
	printf("*       Choose the option below       *\n");
	printf("*   Choisissez l'option ci-dessous    *\n");
	printf("* 1. English (Anglais)                *\n");
	printf("* 2. French  (Francais)               *\n");
	printf("* 3. Exit    (sortir)                 *\n");
	printf("---------------------------------------\n");

	int lang;
	while (scanf("%d", &lang) != 1) {
		//making sure the user inputs a whole number
		printf("\nentree d'erreur reessayer:");
		printf("\nerror input try again:\n");
		printf("---------------------------------------\n");
		printf("*       Choose the option below       *\n");
		printf("*   Choisissez l'option ci-dessous    *\n");
		printf("* 1. English (Anglais)                *\n");
		printf("* 2. French  (Francais)               *\n");
		printf("* 3. Exit    (sortir)                 *\n");
		printf("---------------------------------------\n");
		while (getchar() != '\n');
	}
	if (lang > 0 && lang < 4)
	{
		switch (lang)
		{
		case 1:
			menu(lang);
			break;
		case 2:
			menu_French(lang);
			break;
		default:
			break;
		}
	}
	else
	{
		printf("\nentree d'erreur reessayer:");
		printf("\nerror input try again:\n");
		goto mark;
	}
	BSTInit(lang);
	// ----------------------------------------------------------------------------------------------------------------------

	/* Liam: */
	/* Everything related to files: */

	/* All file function names and description for quick access (do not uncomment):
	
	FileEncrypt(lang);                 // encrypts the file that gets specified by the language the user selected
	FileDecrypt(lang);                 // decrypts the file that gets specified by the language the user selected
	FileGetWord(lang);                 // calls the function that randomly selects a word from the file specified by the users language
	FileRemoveWord(wordtoguess, lang); // removes the word the user guessed from the file and stores it into the save word file
	FileReuseWords(lang);              // amends the save words file with the words file to reuse all the words previously guessed
	
	*/

	// ----------------------------------------------------------------------------------------------------------------------

	/* Minh: */
	/* Create the trees for the program to store the data and sort it from highest to lowest: */
	
	//BSTInit();								//Initialize the BST
	//GameInfor* p = NULL;						//Define node p as null
	//p = (GameInfor*)malloc(sizeof(GameInfor));

	// ----------------------------------------------------------------------------------------------------------------------

	return 0;
}