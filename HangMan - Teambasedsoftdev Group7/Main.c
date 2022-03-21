//Liam, Will, Nihchal, Minh
//Group 7
//HangMan

#include "DataPackages.h"
#include "Header.h"

int main() {

	/* Liam & Minh: */	
	/* language selection stuff: */
	menu_language();
	
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

	/* uncomment the code below to use the file stuff*/

	char* wordtoguess = malloc(sizeof(char*)); // saves the random word the user will be guessing
	//FileDecrypt(lang);                       // this must always go first because the file starts as encrypted
	//wordtoguess = FileGetWord(lang);         // get random word and save it to wordtoguess
	
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