#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* Liam */
// File System Functions
int FileEncrypt(int);
int FileDecrypt(int);
char* FileGetWord(int);
int FileRemoveWord(char[], int);
int FileReuseWords(int);

/* Will */
// Math Gamemode Functions
void MathtoGuess(int);
int getGuess(int);
int checkGuess(int, int, int);
void printEquation(int, char, int, int, int);

/* Nihchal */
// Word Gamemode Functions
int Dash(char*, int);
int GuessCheck(char*, int);

/* Minh */
// UI Menu Functions
void menu(int);
void printBody(int mistakes);
void menu_language();
void menu_French(int);

// New change to merge two header files

// Declare for The Data Organization
typedef struct BSTNode Node;
typedef struct BSTNode* link;
typedef struct playerinfor GameInfor;

struct playerinfor
{
	char Player_1[150];					// name of player 
	int Score;							// Score of player 
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
link BSTInsert(link h, GameInfor item);          //Private Insert function called by 'Insert()'
void Insert(GameInfor item);                     //Public insert function
void BSTPrint(link h);                      //Private Print function called by 'Print()'
void Printnode(void);						//Prints the node
link getRoot(void);							//Returns a pointer to the root of the BST
