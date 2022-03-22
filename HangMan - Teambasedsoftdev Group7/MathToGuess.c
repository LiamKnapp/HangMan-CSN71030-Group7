//Will
//Group 7
//HangMan
#include "Header.h"

void MathtoGuess(int lang) {
	int oper = rand() % 3;
	int leftnum = rand() % 100;
	int midnum = rand() % 100;
	int rightnum;
	int pos = rand() % 2;
	char displayOper;
	int correct;

	switch (oper) {
	case 0:
		displayOper = '+';
		rightnum = leftnum + midnum;
		break;
	case 1:
		displayOper = '-';
		rightnum = leftnum - midnum;
		break;
	case 2:
		displayOper = 'x';
		rightnum = leftnum * midnum;
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
	if (pos == 0) {
		correct = leftnum;
	} else {
		correct = midnum;
	}
	for (int i = 0; i < 6; i++) {
		printBody(i);
		printEquation(pos, displayOper, leftnum, midnum, rightnum);
		int guess = getGuess(lang);
		if (checkGuess(guess, correct, lang)) {
			return;
		}
	}
	if (lang == 1) {
		printf("GAME OVER!!!\n");
		printf("Correct answer was: %d\n", correct);
	}
	else if (lang == 2) {
		printf("JEU TERMINE!!!\n");
		printf("La bonne reponse etait: %d\n", correct);
	}
}

int getGuess(int lang) {
	int ans;
	while (1) {
		if (lang == 1) { // for english
			printf("Please enter your answer (as an integer)\n");
		}
		if (lang == 2) { // for french
			printf("Veuillez entrer un nombre entre 1 et 100\n");
		}

		if (scanf_s("%d", &ans)) {
			if (ans > -10000 && ans < 10000) {
				return ans;
			}
			else {
				if (lang == 1) { // for english
					printf("number must be between -10000 and 10000\n");
				}
				if (lang == 2) { // for french
					printf("le nombre doit etre compris entre -10000 et 10000\n");
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

int checkGuess(int guess, int correct, int lang) {
	
	if (guess == correct) {
		if(lang == 1) // for english
			printf("Correct!!!\n");
		else if (lang == 2) // for french
			printf("Bonne reponse!!!\n");

		return 1;
	}
	else if (guess < correct) {
		if (lang == 1) // for english
			printf("Too low!\n");
		else if (lang == 2) // for french
			printf("Trop bas!\n");
	}
	else if (guess > correct) {
		if (lang == 1) // for english
			printf("Too high!\n");
		else if (lang == 2) // for french
			printf("Trop haut!\n");
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
