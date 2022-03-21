////Minh
////Group 7
////HangMan
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "DataPackages.h"
#include <time.h>
#include <stdbool.h>

////Private Variables
//static link root;           //Root of this file, only to this file
//static GameInfor NullItem = { "Not found - Leaf has been reached" };     //Indicate that a leaf is reached
//
////Function implemenmtaion
//
//link NEW(GameInfor item, link left, link right) {  //Creates a New BST Node
//	link pNew = (link)malloc(sizeof(Node));   //Creates the node
//	pNew->msg = item;						  //Puts the node into the item
//	pNew->pLeft = left;						  //set left link of node to be equal to the node inputed into function
//	pNew->pRight = right;					  //set right link of node to be equal to the node inputed into function
//	return(pNew);							  //return the node
//}
//
//void BSTInit(void) {                           //Initialize the BST Node
//	root = NEW(NullItem, NULL, NULL);		  //define the static root to be the first node
//}

//link BSTInsert(link h, GameInfor item) {			//Private Insert function called by 'Insert()' 										
//	if (h == NULL) return(NEW(item, NULL, NULL));   //Terminal Condition
//	
//	// Demo code to fix it
//	
//	if (item.Score < h->msg.Score)
//	{
//		h->pLeft = BSTInsert(h->pLeft, item);		//inserts on the left side of tree - recurses to check if at end of tree
//	}
//	else
//	{
//		h->pRight = BSTInsert(h->pRight, item);		//inserts on the right side of tree - recurses to check if at end of tree
//	}
//	return(h);												//returns a pointer to the new node created
//	*/
//
//}
//
//void Insert(GameInfor item) {							//Public insert function
//	root = BSTInsert(root, item);					//Call the private insert - this is for security
//}
//
//void BSTPrint(link h) {         //Private Print function called by 'Print()'
//
//	if (h == NULL) return;		//If node is the Leaf return
//
//	//Recursive SubCalls
//
//
//	BSTPrint(h->pRight);                    //Right
//	printf("\nKey: %s\n", h->msg.Words);	//Center
//	printf("\nKey: %s\n", h->msg.Player_1);
//
//	BSTPrint(h->pLeft);						//Left
//}
//
//void Printnode(void) {		//Public print function
//	BSTPrint(root);			//Calls the private print - this is for security
//}
//
//
//link getRoot(void) {         //Returns a pointer to the root of the BST
//	return(root);			 //the root is static for this file - it's the root of the tree
//}
//
//// Function 1: Display the menu of the program
void menu()
{
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
	scanf("%d", &tmp);
	if (tmp > 5 || tmp < 1)
	{
		printf("Error Input. Do you want to input again\n");
		int temp;
		printf("1. Yes\n");
		printf("2. No\n");
		scanf("%d", &temp);
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
	return tmp; // remove it // MInh
}

void menu_French()
{
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
	scanf("%d", &tmp);
	if (tmp > 5 || tmp < 1)
	{
		printf("Erreur, veuillez saisir a nouveau l'entree\n");
		int temp;
		printf("1. Oui\n");
		printf("2. Non\n");
		scanf("%d", &temp);
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
	return tmp;
}

void menu_language()
{
	printf("---------------------------------------\n");
	printf("*       Choose the option below       *\n");
	printf("*   Choisissez l'option ci-dessous    *\n");
	printf("* 1. English (Anglais)                *\n");
	printf("* 2. French  (Francais)               *\n");
	printf("* 3. Exit    (sortir)                 *\n");
	printf("---------------------------------------\n");
}

void printBody(int mistakes, char* body) { // (The number of the mistakes , and an empty dynamic (malloc) array to store the address of each character compare with each number of mistakes )
	printf("Mistakes :%d\n", mistakes);
	switch (mistakes) {

	case 6: body[6] = '\\'; break;
	case 5: body[5] = '/'; break;
	case 4: body[4] = '\\'; break;
	case 3: body[3] = '|'; break;
	case 2: body[2] = '/'; break;
	case 1: body[1] = ')', body[0] = '('; break;
	default: break;

	}

	printf("\t _________\n"
		"\t|         |\n"
		"\t|        %c %c\n"
		"\t|        %c%c%c\n"
		"\t|        %c %c\n"
		"\t|             \n"
		"\t|             ", body[0], body[1], body[2],
		body[3], body[4], body[5], body[6]);
}


void printWord(char* guess, int len) {
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
	printf("%c ", guess[i]);
	}
	printf("\n\n");
}
