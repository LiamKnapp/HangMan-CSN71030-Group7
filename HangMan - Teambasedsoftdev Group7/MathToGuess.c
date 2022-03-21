//Will
//Group 7
//HangMan
#include "Header.h"

int MathtoGuess(int lang) {
	int oper = rand() % 4;
	int num1 = rand() % 100;
	int num2 = rand() % 100;
	int ans;
	int pos = rand() % 2;
	char displayOper;

	switch (oper) {
	case 0:
		displayOper = '+';
		ans = num1 + num2;
		break;
	case 1:
		displayOper = '-';
		ans = num1 - num2;
		break;
	case 2:
		displayOper = 'x';
		ans = num1 * num2;
		break;
	default:
		if (lang == 1) { // for english
			printf("random operator number error\n");
		}
		if (lang == 2) { // for french
			printf("erreur de numero d'operateur aleatoire\n");
		}
		break;
	}
	
	for (int i = 0; i < 6; i++) {
		int guess = getGuess(lang);
		if (!checkGuess(guess, lang)) {
			printEquation(pos, oper, num1, num2, ans);
			printBody(i);
		}
		else {
			return;
		}
	}


}

int getGuess(int lang) {
	int ans;
	while (1) {
		if (lang == 1) { // for english
			printf("Please enter a number between 1 and 100\n");
		}
		if (lang == 2) { // for french
			printf("Veuillez entrer un nombre entre 1 et 100\n");
		}

		if (scanf_s("%d", &ans)) {
			if (ans > 0 && ans < 101) {
				return ans;
			}
			else {
				if (lang == 1) { // for english
					printf("number must be between 1 and 100\n");
				}
				if (lang == 2) { // for french
					printf("le nombre doit etre compris entre 1 et 100\n");
				}
			}
		}
		else {
			if (lang == 1) { // for english
				printf("number must be an integer\n");
			}
			if (lang == 2) { // for french
				printf("le nombre doit etre un entier\n");
			}
		}
		char c[2];
		fgets(c, 2, stdin);
		return ans;
	}
}

int checkGuess(int correct, int lang) {
	int guess = getGuess(lang);
	if (lang == 1) { // for english
		if (guess == correct) {
			printf("Correct!!!\n");
			return 1;
		}
		else if (guess < correct) {
			printf("Too low!\n");
		}
		else if (guess > correct) {
			printf("Too high!\n");
		}
	}

	if (lang == 2) { // for french
		if (guess == correct) { 
			printf("Bonne reponse!!!\n");
			return 1;
		}
		else if (guess < correct) {
			printf("Trop bas!\n");
		}
		else if (guess > correct) {
			printf("Trop haut!\n");
		}
	}
	return 0;
}

void printEquation(int pos, char oper, int num1, int num2, int ans) {
	if (pos == 0) {
		printf("___ %c %d = %d\n", oper, num2, ans);
	}
	else if (pos == 1) {
		printf("%d %c ___ = %d\n", num1, oper, ans);
	}
}
