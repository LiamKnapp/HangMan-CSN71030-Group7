//Minh
//Group 7
//HangMan

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "DataPackages.h"
#include <time.h>
#include <stdbool.h>

//Private Variables
static link root;           //Root of this file, only to this file
static GameInfor NullItem = { "Not found - Leaf has been reached" };     //Indicate that a leaf is reached

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

GameInfor BSTSearch(link h, char* szkey) {	//Private Search function called by 'Search()'
	int rc;								//For recursive function
	if (h == NULL) return(NullItem);	//Check if the pointer is the leaf of a tree
	rc = strcmp(szkey, h->msg.Words);    //Compares the strings in the tree
	if (rc == 0) return(h->msg);		//If the strings are the same return the struct Item (msg) from node h

	//Recursive Subcalls
	if (rc < 0) return(BSTSearch(h->pLeft, szkey));		//if szkey has a smaller ASCII value then the h->msg.buff ASCII value then recurse with the connected left node
	else		return(BSTSearch(h->pRight, szkey));	//if szkey has a larger ASCII value then the h->msg.buff ASCII value then recurse with the connected right node
}

GameInfor Search(char* szkey) {				//Public Search
	return(BSTSearch(root, szkey));		//Call the private search - this is for security
}

link BSTInsert(link h, GameInfor item) {					//Private Insert function called by 'Insert()'
	int rc;											//Variable used to compare the strings
	if (h == NULL) return(NEW(item, NULL, NULL));   //Terminal Condition
	rc = strcmp(item.Words, h->msg.Words);			//Compares the strings that we want to insert

	//Recursive Subcalls for traversing the tree to get to the leaf
	if (rc < 0) h->pLeft = BSTInsert(h->pLeft, item);		//inserts on the left side of tree - recurses to check if at end of tree
	else		h->pRight = BSTInsert(h->pRight, item);		//inserts on the right side of tree - recurses to check if at end of tree

	return(h);												//returns a pointer to the new node created

}

void Insert(GameInfor item) {							//Public insert function
	root = BSTInsert(root, item);					//Call the private insert - this is for security
}

void BSTPrint(link h) {         //Private Print function called by 'Print()'

	if (h == NULL) return;		//If node is the Leaf return

	//Recursive SubCalls


	BSTPrint(h->pRight);                    //Right
	printf("\nKey: %s\n", h->msg.Words);		//Center
	printf("\nKey: %s\n", h->msg.Player_1);
	printf("\nKey: %s\n", h->msg.Player_2);
	printf("\nKey: %s\n", h->msg.LocalTime);
	printf("\nKey: %d\n", h->msg.Score_1);
	printf("\nKey: %d\n", h->msg.Score_2);
	BSTPrint(h->pLeft);						//Left
}

void Printnode(void) {		//Public print function
	BSTPrint(root);			//Calls the private print - this is for security
}

int height(link h) {                            //Returns the height of the BST
	int iLeftH, iRightH;						//Create variables for the left and right height

	if (h == NULL) return(-1);					//Base terminal condition - reached leaf

	//Recursive Subcalls
	iLeftH = height(h->pLeft);					//left tree height is equal to the number of times the function is called recursively
	iRightH = height(h->pRight);				//right tree height is equal to the number of times the function is called recursively

	if (iLeftH > iRightH) return(iLeftH + 1);	//if the left height is larger then the right height add 1 to the left height
	else return(iRightH + 1);					//otherwise add 1 to the right height
}

int count(link h) {									//Returns number of nodes in the BST
	if (h == NULL) return(0);						//Base Case/Terminal condition
	return(count(h->pLeft) + count(h->pRight) + 1); //recursive call - add the total number of times we recurse for each branch, this totals to the total number of nodes in the BST
}

link getRoot(void) {         //Returns a pointer to the root of the BST
	return(root);			 //the root is static for this file - it's the root of the tree
}

// Export tree to file if needed
/*
void BSTExport(FILE* fp, link h)
{
	if (h != NULL)
	{
		BSTExport(fp, h->pRight);
		fprintf(fp, h->msg.buff);
		fprintf(fp, h->msg.Score);
		BSTExport(fp, h->pLeft);
	}
}
void Export(void)
{
	time_t curtime;
	time(&curtime);
	FILE* fp;
	fp = fopen("Names.txt", "a");
	char str[100] = "History board\n";
	char line[100] = "__________________";
	fprintf(fp, "%s\n", str);
	fprintf(fp, "%s\n", ctime(&curtime));
	BSTExport(fp, root);
	fprintf(fp, "%s\n", line);
	fclose(fp);
}
*/

// Function 1: Display the menu of the program
void menu()
{
	printf("--------------------------------\n");
	printf("*    Welcome to Hangman Game   *\n");
	printf("* 1. Single PLayer Mode        *\n");
	printf("* 2. Solo PLay Mode            *\n");
	printf("* 3. History board             *\n");
	printf("* 4. Exit                      *\n");
	printf("--------------------------------\n");
}

void printBody(int mistakes, char* body) {
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
