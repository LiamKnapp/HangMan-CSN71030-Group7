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
	scanf_s("%d", &tmp);
	if (tmp > 5 || tmp < 1)
	{
		printf("Error Input. Do you want to input again\n");
		int temp;
		printf("1. Yes\n");
		printf("2. No\n");
		scanf_s("%d", &temp);
		switch (temp)
		{
		case 1:
			goto mark2;
		case 2:
			break;
		default:
			break;
		}
	}

	// The function to direct the flow of the program due to the choosen of the player
	switch (tmp)
	{
	case 1:
		FileDecrypt(lang);
		wordtoguess = FileGetWord(lang);
		//FileRemoveWord(wordtoguess, lang); 
		//FileReuseWords(lang);
		FileEncrypt(lang);
		Dash(wordtoguess, lang);
		break;
	case 2:
		FileDecrypt(lang);
		wordtoguess = FileGetWord(lang);
		//FileRemoveWord(wordtoguess, lang); 
		//FileReuseWords(lang);
		FileEncrypt(lang);

		Dash(wordtoguess, lang);
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
		scanf_s("%d", &tmp_1);
		switch (tmp_1)
		{
		case 1:
			menu(lang);
		case 2:
			break;
		default:
			break;
		}
		break;
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
	scanf_s("%d", &tmp);
	if (tmp > 5 || tmp < 1)
	{
		printf("Erreur, veuillez saisir a nouveau l'entree\n");
		int temp;
		printf("1. Oui\n");
		printf("2. Non\n");
		scanf_s("%d", &temp);
		switch (temp)
		{
		case 1:
			goto mark1;
		case 2:
			break;
		case 3:
		default:
			break;
		}
	}
	// The function to direct the flow of the program due to the choosen of the player
	switch (tmp)
	{
	case 1:
		FileDecrypt(lang);                       // this must always go first because the file starts as encrypted
		wordtoguess = FileGetWord(lang);         // get random word and save it to wordtoguess
		//FileRemoveWord(wordtoguess, lang); // remove word that getword function selects and save to savefile
		//FileReuseWords(lang);
		FileEncrypt(lang);

		Dash(wordtoguess, lang);
		break;
	case 2:
		FileDecrypt(lang);
		wordtoguess = FileGetWord(lang);
		//FileRemoveWord(wordtoguess, lang);
		//FileReuseWords(lang);
		FileEncrypt(lang);

		Dash(wordtoguess, lang);
		break;
	case 3:
		MathtoGuess(lang);
		break;
	case 4:
		Printnode();

		break;
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
	scanf_s("%d", &lang);
	switch (lang)
	{
	case 1:
		menu(lang);
		break;
	case 2:
		menu_French(lang);
		break;
	case 3:
		break;
	default:
		printf("Error Input. Do you want to input again\n");
		int temp;
		printf("1. Yes\n");
		printf("2. No\n");
		scanf_s("%d", &temp);
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

}


void printWord(char* guess, int len) {
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", guess[i]);
	}
	printf("\n\n");
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