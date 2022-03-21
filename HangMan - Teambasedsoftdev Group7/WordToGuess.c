//Nihchal
//Group 7
//HangMan
#include "Header.h"

#define MAX_LEN 10

int Dash(char* wordtoguess) {

	int sizeofword = sizeof(wordtoguess);

	for (int n = 0; n < sizeofword; n++) {

		printf("-");
	}
	userInput(wordtoguess); 

}

int userInput(char* wordtoguess) {
	char c;

	printf("\n");

	printf("Enter a word to guess: \n");
	scanf("%c", c);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= "Z"))
	{
		Guesscheck(c); 
	}
	else {
		printf("Please enter a valid character: %c", c);
	}

}

int GuessCheck(char guess, char* wordtoguess) {

	int mistake = 0;
	char savedLetters[sizeof(wordtoguess)];
	
	if (strchr(wordtoguess, guess) != NULL){
		printf("%c is in the word.\n");
		savedLetters[0] = guess;
		userInput(wordtoguess);
	}
	else{
	mistake++;
	printBody;
	}
	if (mistake == 6) {
		printf("You Lose.\n");

		return 0;
	}


}



int guessAmount() {
	int guess;

}

void printResults() {

}