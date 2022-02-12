//Liam, Will, Nihchal, Minh
//Group 7
//HangMan
#pragma once
// Declare for The Data Organization
typedef struct BSTNode Node;
typedef struct BSTNode* link;
typedef struct gameinfor GameInfor;

struct gameinfor
{
	char Words[150];					// The Key Word of the game
	char Player_1[150];					// name of player 1
	char Player_2[150];					// name of player 2
	char LocalTime[150];				// Time of the game over
	int Score_1;						// Score of player 1
	int Score_2;						// Score of player 2
};

#pragma once

struct BSTNode {
	GameInfor msg;		//Msg.buff contains the key which is a quote from the fortune cookies file
	link pLeft;			//left subtree
	link pRight;		//right subtree
};

// BSTree function to store the data of the history of the game
// Declare function of the tree

link NEW(GameInfor item, link left, link right); //Creates a new BST Node
void BSTInit(void);							//Initialize a BST
GameInfor BSTSearch(link h, char* szkey);		//Private Search function called by 'Search()'
GameInfor Search(char* szkey);                   //Public Search
link BSTInsert(link h, GameInfor item);          //Private Insert function called by 'Insert()'
void Insert(GameInfor item);                     //Public insert function
void BSTPrint(link h);                      //Private Print function called by 'Print()'
void Printnode(void);						//Prints the node
int height(link h);                         //Returns the height of the BST
int count(link h);							//Returns number of nodes in the BST
link getRoot(void);							//Returns a pointer to the root of the BST
void BSTExport(FILE* fp, link h);	        //Private export function to write the history of the game to file
void Export(void);							//Public export function 