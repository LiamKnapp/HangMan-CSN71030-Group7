//Liam , Will, Nihchal, Minh
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

int main() 
{
	// Minh: Create the trees for the program to store the data and sort it from highest to lowest
	BSTInit();									//Initialize the BST
	GameInfor* p = NULL;						//Define node p as null
	p = (GameInfor*)malloc(sizeof(GameInfor));


	return 0;
}