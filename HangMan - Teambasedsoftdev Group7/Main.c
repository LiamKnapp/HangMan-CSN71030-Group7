//Liam , Will, Nihchal, Minh
//Group 7
//HangMan
#define _CRT_SECURE_NO_WARNINGS

#include "DataPackages.h"
#include "Header.h"

int main() {

	/* Liam & Minh: */	
	/* language selection stuff: */

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

	// ----------------------------------------------------------------------------------------------------------------------

	/* Liam: */
	/* Everything related to files: */

	/* Cautions and Safety:
		caution: decrypting a file that is already decrypted will result error
		caution: encrypting a file that is already encrypted will result error
		caution: if error happens contact Liam for support (error will not happen when user use program due to automation)
		caution: do not reformat the file! simply removing the space left at the end of file will result error due to amendment
		caution: do not try to add more words or replace words without Liam
		caution: do not try to change the file settings (words per line, amount of lines per file) without Liam
		caution: do not remove any files (this is commonsense but im noteing it anyways)
		caution: do not uncomment anything that specifies "do not uncomment"
		caution: always encrypt a file if the file ever gets decrypted
		caution: do not reformat the order of operations (any change in order will result in automation failure)
			1. decrypt
			2. get word
			3. remove word (if user gueses correct if not skip this step)
			4. reuse word (only do this step if the file has run out of words)
			5. encrypt
		caution: if error happens contact Liam for support (error will not happen when user use program due to automation)
	*/

	/* All file function names and description for quick access (do not uncomment):
	
	FileEncrypt(lang);                 // encrypts the file that gets specified by the language the user selected
	FileDecrypt(lang);                 // decrypts the file that gets specified by the language the user selected
	FileGetWord(lang);                 // calls the function that randomly selects a word from the file specified by the users language
	FileRemoveWord(wordtoguess, lang); // removes the word the user guessed from the file and stores it into the save word file
	FileReuseWords(lang);              // amends the save words file with the words file to reuse all the words previously guessed
	
	*/

	/* uncomment the code below to use the file stuff*/

	char* wordtoguess = malloc(sizeof(char*)); // saves the random word the user will be guessing
	//FileDecrypt(lang);                       // this must always go first because the file starts as encrypted
	//wordtoguess = FileGetWord(lang);         // get random word and save it to wordtoguess

	/* Remove the code between star line when complete. this is to test the word is being returned from file: */
	// ********************************************************************

	/*if (lang == 1) {
		printf("\nRandom word: %s\n", wordtoguess);
	}
	else {
		printf("\nMot aleatoire: %s\n", wordtoguess);
	}*/

	// ********************************************************************
	
	//FileRemoveWord(wordtoguess, lang); // remove word that getword function selects and save to savefile
	//FileReuseWords(lang);              // only use this file if all words in the normal word file have run out
	//FileEncrypt(lang);                 // only do this at the end of the program if files were decrypted

	// ----------------------------------------------------------------------------------------------------------------------

	/* Minh: */
	/* Create the trees for the program to store the data and sort it from highest to lowest: */
	
	//BSTInit();								//Initialize the BST
	//GameInfor* p = NULL;						//Define node p as null
	//p = (GameInfor*)malloc(sizeof(GameInfor));

	// ----------------------------------------------------------------------------------------------------------------------

	return 0;
}