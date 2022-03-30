//Liam, Will, Nihchal, Minh
//Group 7
//HangMan

#include "DataPackages.h"
#include "Header.h"

int main() {


mark:
	printf("---------------------------------------\n");
	printf("*       Choose the option below       *\n");
	printf("*   Choisissez l'option ci-dessous    *\n");
	printf("* 1. English (Anglais)                *\n");
	printf("* 2. French  (Francais)               *\n");
	printf("* 3. Exit    (sortir)                 *\n");
	printf("---------------------------------------\n");

	int lang;
	while (scanf("%d", &lang) != 1) {
		//making sure the user inputs a whole number
		printf("\nentree d'erreur reessayer:");
		printf("\nerror input try again:\n");
		printf("---------------------------------------\n");
		printf("*       Choose the option below       *\n");
		printf("*   Choisissez l'option ci-dessous    *\n");
		printf("* 1. English (Anglais)                *\n");
		printf("* 2. French  (Francais)               *\n");
		printf("* 3. Exit    (sortir)                 *\n");
		printf("---------------------------------------\n");
		while (getchar() != '\n');
	}

	if (lang > 0 && lang < 4)
	{
		menu_language(lang);
	}
	else
	{
		printf("\nentree d'erreur reessayer:");
		printf("\nerror input try again:\n");
		goto mark;
	}
	
	BSTInit(lang);

	return 0;
}

int menu_language(int lang)
{
	/* Liam & Minh: */
	/* language selection stuff: */
	int test = 0;				// Variable for test not damage the program
		switch (lang)
		{
		case 1:
			//return 1;						//Return value for the test cases 
			menu(lang,test);
			break;
		case 2:
			//return 2;						//Return value for the test cases
			menu_French(lang,test);
			break;
		default:
			//return 3;						//Return value for the test cases
			break;
		}
}