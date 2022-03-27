////Minh
////Group 7
////HangMan
//

#include "Header.h"

//Private Variables
static link root;           //Root of this file, only to this file
static GameInfor NullItem = { "This is the end of the list" };     //Indicate that a leaf is reached

//Function implemenmtaion

link NEW(GameInfor item, link left, link right) {  //Creates a New BST Node
	link pNew = (link)malloc(sizeof(Node));   //Creates the node
	pNew->msg = item;						  //Puts the node into the item
	pNew->pLeft = left;						  //set left link of node to be equal to the node inputed into function
	pNew->pRight = right;					  //set right link of node to be equal to the node inputed into function
	return(pNew);							  //return the node
}

void BSTInit(void) {                           //Initialize the BST Node
	root = NEW(NullItem, NULL, NULL);		  //define the static root to be the first node
}

link BSTInsert(link h, GameInfor item) {			//Private Insert function called by 'Insert()' 										
	if (h == NULL)
	{
		return(NEW(item, NULL, NULL));
	}   //Terminal Condition

	if (item.Score < h->msg.Score)
	{
		h->pLeft = BSTInsert(h->pLeft, item);		//inserts on the left side of tree - recurses to check if at end of tree
	}
	else
	{
		h->pRight = BSTInsert(h->pRight, item);		//inserts on the right side of tree - recurses to check if at end of tree
	}
	return(h);												//returns a pointer to the new node created


}

void Insert(GameInfor item) {							//Public insert function
	root = BSTInsert(root, item);					//Call the private insert - this is for security
}

link BSTSearch(link h, char* szkey) {	//Private Search function called by 'Search()'
	int rc;								//For recursive function
	if (h == NULL) {
		return(NULL);
	}
	if (szkey == h->msg.Player_1)
	{
		return(h);
	}
	else if (szkey < h->msg.Player_1)
	{
		h->pLeft = BSTSearch(h->pLeft, szkey);
	}
	else
	{
		h->pRight = BSTSearch(h->pRight, szkey);
	}
}

link Search(char* szkey) {				//Public Search
	return(BSTSearch(root, szkey));		//Call the private search - this is for security
}

void BSTPrint(link h) {         //Private Print function called by 'Print()'

	if (h == NULL)return;

	//Recursive SubCalls


	BSTPrint(h->pRight);                    //Right
	printf("\nScore: %d\t", h->msg.Score);	//Center
	printf("\tPlayer: %s\n", h->msg.Player_1);
	BSTPrint(h->pLeft);						//Left
}

void Printnode(void) {		//Public print function
	BSTPrint(root);			//Calls the private print - this is for security
}


link getRoot(void) {         //Returns a pointer to the root of the BST
	return(root);			 //the root is static for this file - it's the root of the tree
}





void printWord(char* guess, int len) {
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", guess[i]);
	}
	printf("\n\n");
}

//// Function 1: Display the menu of the program
void menu(int lang)
{
	char* wordtoguess = malloc(sizeof(char*)); // saves the random word the user will be guessing
mark2:
	printf("--------------------------------\n");
	printf("*    Welcome to Hangman Game   *\n");
	printf("*    Choose the option below   *\n");
	printf("* 1. Single PLayer Mode        *\n");
	printf("* 2. Team Mode                 *\n");
	printf("* 3. Math Game-Mode            *\n");
	printf("* 4. History board             *\n");
	printf("* 5. Exit                      *\n");
	printf("--------------------------------\n");
	int tmp;
	while (scanf("%d", &tmp) != 1) {
		//making sure the user inputs a whole number
		printf("\nPlease enter an interger from 1 to 5 or Press 5 to exit the program\n");
		while (getchar() != '\n');
	}

	if (tmp < 0 || tmp > 6)
	{
		printf("\nPlease enter an interger from 1 to 5 or Press 5 to exit the program\n\n");
		goto mark2;
	}

	// The function to direct the flow of the program due to the choosen of the player
	switch (tmp)
	{
	case 1:
		FileDecrypt(lang);
		FileGetWord(lang);
		//FileRemoveWord(g.word, lang); 
		//FileReuseWords(lang);
		FileEncrypt(lang);
		Dash(g.word, lang);
		break;
	case 2:
		FileDecrypt(lang);
		FileGetWord(lang);
		//FileRemoveWord(g.word, lang); 
		//FileReuseWords(lang);
		FileEncrypt(lang);
		Dash(g.word, lang);
		break;
	case 3:
		MathtoGuess(lang);
		break;
	case 4:
		Printnode();
		int tmp_1;
		printf("\nDo you want to play again\n");
		printf("\n1. Yes\n");
		printf("\n2. No\n");
	mark5:
		while (scanf("%d", &tmp_1) != 1) {
			//making sure the user inputs a whole number
			printf("\nPlease enter an interger 1 or 2 or Press 2 to exit the program\n");
			while (getchar() != '\n');
		}

		if (tmp_1 < 0 || tmp_1 > 2)
		{
			printf("\nPlease enter an interger 1 or 2 or Press 2 to exit the program\n");
			goto mark5;
		}
		switch (tmp_1)
		{
		case 1:
			menu(lang);
		case 2:
			break;
		default:
			break;
		}

	case 5:
		break;
	default:
		break;
	}
}

void menu_French(int lang)
{
	char* wordtoguess = malloc(sizeof(char*));
mark1:

	printf("------------------------------------\n");
	printf("  Bienvenue dans le jeu du pendu   *\n");
	printf("  Choisissez l'option ci-dessous   *\n");
	printf("* 1. Jeu unique                    *\n");
	printf("* 2. Jeu d'equipe                  *\n");
	printf("* 3. Mode de jeu mathematique      *\n");
	printf("* 4. Tableau d'histoire            *\n");
	printf("* 5. Sortir                        *\n");
	printf("------------------------------------\n");
	int tmp;

	while (scanf("%d", &tmp) != 1) {
		//making sure the user inputs a whole number
		printf("\nPlease enter an interger from 1 to 5 or Press 5 to exit the program\n");
		while (getchar() != '\n');
	}

	if (tmp < 0 || tmp > 6)
	{
		printf("Please enter an interger from 1 to 5 or Press 5 to exit the program\n");
		goto mark1;
	}

	// The function to direct the flow of the program due to the choosen of the player
	switch (tmp)
	{
	case 1:
		FileDecrypt(lang);
		FileGetWord(lang);
		//FileRemoveWord(g.word, lang); 
		//FileReuseWords(lang);
		FileEncrypt(lang);
		Dash(g.word, lang);
		break;
	case 2:
		FileDecrypt(lang);
		FileGetWord(lang);
		//FileRemoveWord(g.word, lang); 
		//FileReuseWords(lang);
		FileEncrypt(lang);
		Dash(g.word, lang);
		break;
	case 3:
		MathtoGuess(lang);
		break;
	case 4:
		Printnode();
		int tmp_1;
	mark4:
		printf("Erreur, veuillez saisir a nouveau l'entree\n");
		printf("1. Oui\n");
		printf("2. Non\n");
		while (scanf("%d", &tmp_1) != 1) {
			//making sure the user inputs a whole number
			printf("\nPlease enter an interger 1 or 2 or Press 2 to exit the program\n");
			while (getchar() != '\n');
		}

		if (tmp_1 < 0 || tmp_1 > 2)
		{
			printf("\nPlease enter an interger 1 or 2 or Press 2 to exit the program\n");
			goto mark4;
		}
		switch (tmp_1)
		{
		case 1:
			menu_French(lang);
		case 2:
			break;
		default:
			break;
		}
	case 5:
		break;
	default:
		break;
	}
}

void menu_language()
{
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
		printf("\nPlease enter an interger from 1 to 3\n");
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
		printf("Please enter an interger from 1 to 3 or Press 3 to exit the program\n");
		goto mark;
	}
}

void printBody(int mistakes)
{

	char* platform[] = {

		"_____________\n",

		"_____________\n"
		"      |   	  \n"
		"      |      \n"
		"      |      \n"
		"    _____    \n"
		"   |     |   \n"
		"   |     |   \n"
		"    -----	  \n",

		"_____________\n"
		"      |   	  \n"
		"      |      \n"
		"      |      \n"
		"    _____    \n"
		"   |     |   \n"
		"   |     |   \n"
		"    -----	  \n"
		"      |      \n"
		"      |      \n"
		"      |      \n"
		"      |      \n"
		"      |      \n",

		"_____________\n"
		"      |      \n"
		"      |      \n"
		"      |      \n"
		"    _____    \n"
		"   |     |   \n"
		"   |     |   \n"
		"    -----	  \n"
		"      |      \n"
		"     /|      \n"
		"    / |      \n"
		"   /  |      \n"
		"      |      \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n",

		"_____________\n"
		"      |   	  \n"
		"      |      \n"
		"      |      \n"
		"    _____    \n"
		"   |     |   \n"
		"   |     |   \n"
		"    -----	  \n"
		"      |      \n"
		"     /|\\     \n"
		"    / | \\    \n"
		"   /  |  \\   \n"
		"      |      \n"
		"             \n"
		"             \n"
		"             \n"
		"             \n",

		"_____________\n"
		"      |   	  \n"
		"      |      \n"
		"      |      \n"
		"    _____    \n"
		"   |     |   \n"
		"   |     |   \n"
		"    -----	  \n"
		"      |      \n"
		"     /|\\     \n"
		"    / | \\    \n"
		"   /  |  \\   \n"
		"      |      \n"
		"     /       \n"
		"    /        \n"
		"   /         \n"
		"             \n",

		"_____________\n"
		"      |   	  \n"
		"      |      \n"
		"      |      \n"
		"    _____    \n"
		"   |     |   \n"
		"   |     |   \n"
		"    -----	  \n"
		"      |      \n"
		"     /|\\     \n"
		"    / | \\	  \n"
		"   /  |  \\   \n"
		"      |      \n"
		"     / \\     \n"
		"    /   \\    \n"
		"   /     \\   \n"
		"             \n"
	};

	switch (mistakes)
	{
	case 6:
		printf("\n\n%s\n", platform[6]);
		break;
	case 5:
		printf("\n\n%s\n", platform[5]);
		break;
	case 4:
		printf("\n\n%s\n", platform[4]);
		break;
	case 3:
		printf("\n\n%s\n", platform[3]);
		break;
	case 2:
		printf("\n\n%s\n", platform[2]);
		break;
	case 1:
		printf("\n\n%s\n", platform[1]);
		break;
	case 0:
		printf("\n\n%s\n", platform[0]);
		break;
	}
}