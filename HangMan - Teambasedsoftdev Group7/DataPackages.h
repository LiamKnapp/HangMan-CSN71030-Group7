////Liam, Will, Nihchal, Minh
////Group 7
////HangMan
//#pragma once
//// Declare for The Data Organization
//typedef struct BSTNode Node;
//typedef struct BSTNode* link;
//typedef struct playerinfor GameInfor;
//
//struct playerinfor
//{
//	char Words[150];					// The Key Words of the game
//	char Player_1[150];					// name of player 
//	int Score;							// Score of player 
//
//};
//
//#pragma once
//
//struct BSTNode {
//	GameInfor msg;		//Msg.buff contains the key which is a quote from the fortune cookies file
//	link pLeft;			//left subtree
//	link pRight;		//right subtree
//};
//
//// BSTree function to store the data of the history of the game
//// Declare function of the tree
//
//link NEW(GameInfor item, link left, link right); //Creates a new BST Node
//void BSTInit(void);							//Initialize a BST
//link BSTInsert(link h, GameInfor item);          //Private Insert function called by 'Insert()'
//void Insert(GameInfor item);                     //Public insert function
//void BSTPrint(link h);                      //Private Print function called by 'Print()'
//void Printnode(void);						//Prints the node
///link getRoot(void);							//Returns a pointer to the root of the BST
void menu();
void printBody(int mistakes, char* body);