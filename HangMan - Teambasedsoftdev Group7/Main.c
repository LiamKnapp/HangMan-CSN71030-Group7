//Liam , Will, Nihchal, Minh
//Group 7
//HangMan
#define _CRT_SECURE_NO_WARNINGS
#include "DataPackages.h"
#include "Header.h"

int main() 
{
	FileDecrypt();//decrypt the word file

	//// Minh: Create the trees for the program to store the data and sort it from highest to lowest
	//BSTInit();									//Initialize the BST
	//GameInfor* p = NULL;						//Define node p as null
	//p = (GameInfor*)malloc(sizeof(GameInfor));

	FileEncrypt(); // encrypt the word file

	return 0;
}