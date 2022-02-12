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