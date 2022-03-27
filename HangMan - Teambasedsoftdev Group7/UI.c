////Minh
////Group 7
////HangMan
//

#include "Header.h"

//Private Variables
static link root;           //Root of this file, only to this file
static GameInfor NullItem = { "This is the end of the list" };     //Indicate that a leaf is reached
static GameInfor NullItemFR = { "c'est la fin de la liste" };

//Function implemenmtaion

link NEW(GameInfor item, link left, link right) {  //Creates a New BST Node
	link pNew = (link)malloc(sizeof(Node));   //Creates the node
	pNew->msg = item;						  //Puts the node into the item
	pNew->pLeft = left;						  //set left link of node to be equal to the node inputed into function
	pNew->pRight = right;					  //set right link of node to be equal to the node inputed into function
	return(pNew);							  //return the node
}

void BSTInit(int lang) {                           //Initialize the BST Node
	if (lang == 1) {
		root = NEW(NullItem, NULL, NULL);		  //define the static root to be the first node
	}
	if (lang == 2) {
		root = NEW(NullItemFR, NULL, NULL);		  //define the static root to be the first node
	}
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

void BSTPrint(link h, int lang) {         //Private Print function called by 'Print()'

	if (h == NULL)return;

	//Recursive SubCalls


	BSTPrint(h->pRight, lang);                    //Right
	if (lang == 1) {
		printf("\nScore: %d\n", h->msg.Score);	//Center
		printf("Word: %s\n", h->msg.word);
		printf("Player: %s\n", h->msg.Player_1);
		printf("Time played : % lf secs\n", h->msg.time_count);
		printf("Time: %s\n\n", h->msg.time);
	}
	if (lang == 2) {
		printf("\nMarquer des points: %d\n", h->msg.Score);	//Center
		printf("Le mot devine: %s\n", h->msg.word);
		printf("Prenom du joueur: %s\n", h->msg.Player_1);
		printf("Temps joue: % lf secs\n", h->msg.time_count);
		printf("Temps: %s\n\n", h->msg.time);
	}
	BSTPrint(h->pLeft, lang);						//Left
}

void Printnode(int lang) {		//Public print function
	BSTPrint(root, lang);			//Calls the private print - this is for security
}


link getRoot(void) {         //Returns a pointer to the root of the BST
	return(root);			 //the root is static for this file - it's the root of the tree
}


//// Function 1: Display the menu of the program
void menu(int lang)
{
mark2:
	printf("--------------------------------\n");
	printf("*    Welcome to Hangman Game   *\n");
	printf("*    Choose the option below   *\n");
	printf("* 1. Single PLayer Mode        *\n");
	printf("* 2. Team Mode (Future Update) *\n");
	printf("* 3. Math Game-Mode            *\n");
	printf("* 4. History board             *\n");
	printf("* 5. Exit                      *\n");
	printf("--------------------------------\n");
	int tmp;
	while (scanf("%d", &tmp) != 1) {
		//making sure the user inputs a whole number
		printf("\nError Input try again:\n");
		printf("--------------------------------\n");
		printf("*    Welcome to Hangman Game   *\n");
		printf("*    Choose the option below   *\n");
		printf("* 1. Single PLayer Mode        *\n");
		printf("* 2. Team Mode (Future Update) *\n");
		printf("* 3. Math Game-Mode            *\n");
		printf("* 4. History board             *\n");
		printf("* 5. Exit                      *\n");
		printf("--------------------------------\n");
		while (getchar() != '\n');
	}

	if (tmp < 1 || tmp > 6)
	{
		printf("\nError Input try again:\n");
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
		printf("\nThis will be included in version 2.0\n\n");
		menu(lang);
		break;
	case 3:
		MathtoGuess(lang);
		break;
	case 4:
		Printnode(lang);
		int tmp_1;
		printf("\nDo you want to play again\n");
		printf("1. Yes\n");
		printf("2. No\n");
	mark5:
		while (scanf("%d", &tmp_1) != 1) {
			//making sure the user inputs a whole number
			printf("\nError input try again:\n");
			printf("Do you want to play again\n");
			printf("1. Yes\n");
			printf("2. No\n");
			while (getchar() != '\n');
		}

		if (tmp_1 < 1 || tmp_1 > 2)
		{
			printf("\nError input try again:\n");
			printf("Do you want to play again\n");
			printf("1. Yes\n");
			printf("2. No\n");
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
mark1:

	printf("------------------------------------    \n");
	printf("  Bienvenue dans le jeu du pendu       *\n");
	printf("  Choisissez l'option ci-dessous       *\n");
	printf("* 1. Jeu unique                        *\n");
	printf("* 2. Jeu d'equipe (future mise a jour) *\n");
	printf("* 3. Mode de jeu mathematique          *\n");
	printf("* 4. Tableau d'histoire                *\n");
	printf("* 5. Sortir                            *\n");
	printf("------------------------------------    \n");
	int tmp;

	while (scanf("%d", &tmp) != 1) {
		//making sure the user inputs a whole number
		printf("\nentree d'erreur reessayer:\n");
		printf("------------------------------------    \n");
		printf("  Bienvenue dans le jeu du pendu       *\n");
		printf("  Choisissez l'option ci-dessous       *\n");
		printf("* 1. Jeu unique                        *\n");
		printf("* 2. Jeu d'equipe (future mise a jour) *\n");
		printf("* 3. Mode de jeu mathematique          *\n");
		printf("* 4. Tableau d'histoire                *\n");
		printf("* 5. Sortir                            *\n");
		printf("------------------------------------    \n");
		while (getchar() != '\n');
	}

	if (tmp < 1 || tmp > 6)
	{
		printf("\nentree d'erreur reessayer:\n");
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
		printf("\nCela sera inclus dans la version 2.0\n\n");
		menu_French(lang);
		break;
	case 3:
		MathtoGuess(lang);
		break;
	case 4:
		Printnode(lang);
		int tmp_1;
	mark4:
		printf("veux-tu rejouere?\n");
		printf("1. Oui\n");
		printf("2. Non\n");
		while (scanf("%d", &tmp_1) != 1) {
			//making sure the user inputs a whole number
			printf("\nentree d'erreur reessayer:\n");
			printf("veux-tu rejouere?\n");
			printf("1. Oui\n");
			printf("2. Non\n");
			while (getchar() != '\n');
		}

		if (tmp_1 < 1 || tmp_1 > 2)
		{
			printf("\nentree d'erreur reessayer:\n");
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