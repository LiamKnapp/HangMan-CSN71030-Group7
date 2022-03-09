//Will
//Group 7
//HangMan

MathtoGuess() {
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
		printf("random operator number error\n");
		break;
	}
	
	for (int i = 0; i < 6; i++) {
		int guess = getGuess();
		if (!checkGuess(guess)) {
			printEquation(pos, oper, num1, num2, ans);
			printBody(i);
		}
		else {
			return;
		}
	}


}

int getGuess() {
	int ans;
	while (1) {
		printf("Please enter a number between 1 and 100\n");

		if (scanf_s("%d", &ans)) {
			if (ans > 0 && ans < 101) {
				return ans;
			}
			else {
				printf("number must be between 1 and 100\n");
			}
		}
		else {
			printf("number must be an integer\n");
		}
		fgets("");
		return ans;
	}
}

int checkGuess(int correct) {
	int guess = getGuess();
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
