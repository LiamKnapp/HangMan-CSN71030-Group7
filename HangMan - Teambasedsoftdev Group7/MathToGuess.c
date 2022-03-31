//Will
//Group 7
//HangMan
#include "Header.h"

void MathtoGuess(int lang) {

	time_t t;
	srand((unsigned)time(&t));

	int oper = rand() % 3;
	
	int leftnum = rand() % 101;
	if (leftnum < 0 || leftnum > 100) randNumError(lang);
	int midnum = rand() % 101;
	if (midnum < 0 || midnum > 100) randNumError(lang);
	
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
		randNumError(lang);
		break;
	}
	if (pos == 0) {
		correct = leftnum;
	}else if (pos == 1) {
		correct = midnum;
	} else {
		randNumError(lang);
	}
	for (int i = 0; i < 6; i++) {
		printBody(i);
		printEquation(pos, displayOper, leftnum, midnum, rightnum);

		int guess = getGuess(lang);
		if (checkGuess(guess, correct, lang)) {
			return;
		}
	}
	printBody(6);
	if (lang == 1) {
		printf("GAME OVER!!!\n");
		printf("Correct answer was: %d\n\n", correct);
		menu(lang,0);
	} else if (lang == 2) {
		printf("JEU TERMINE!!!\n");
		printf("La bonne reponse etait: %d\n\n", correct);
		menu_French(lang,0);
	}
}

int getGuess(int lang) {
	int ans;
	int ret;
	int valid = -2;

	while(valid != 0){
		if (lang == 1) { // for english
			printf("Please enter your answer (as an integer)\n");
		}
		else if (lang == 2) { // for french
			printf("Veuillez entrer un nombre entre 1 et 100\n");
		}

		ret = scanf_s("%d", &ans);
		valid = verifyGuess(ans, ret, lang);

		char c[50];
		fgets(c, 50, stdin);
	}
	return ans;
}
int verifyGuess(int user, int ret, int lang) {
	if (ret == 0) {
		if (lang == 1) { // for english
			printf("number must be an integer\n");
		}
		else if (lang == 2) { // for french
			printf("le nombre doit etre un entier\n");
		}
		return -1;
	}
	if (user < -10000) {
		if (lang == 1) { // for english
			printf("number must be between -10000 and 10000\n");
		}
		else if (lang == 2) { // for french
			printf("le nombre doit etre compris entre -10000 et 10000\n");
		}
		return 1;
	}
	if (user > 10000) {
		if (lang == 1) { // for english
			printf("number must be between -10000 and 10000\n");
		}
		else if (lang == 2) { // for french
			printf("le nombre doit etre compris entre -10000 et 10000\n");
		}
		return 2;
	}
	return 0;
}
int checkGuess(int guess, int correct, int lang) {
	
	if (guess == correct) {
		if (lang == 1) { // for english
			printf("Correct!!!\n\n");
			menu(lang,0);
		}
		if (lang == 2) { // for french
			printf("Bonne reponse!!!\n\n");
			menu_French(lang,0);
		}
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

void randNumError(int lang) {
	if (lang == 1) { // for english
		printf("random operator number error\n");
	}
	else if (lang == 2) { // for french
		printf("erreur de numero d'operateur aleatoire\n");
	}
}

