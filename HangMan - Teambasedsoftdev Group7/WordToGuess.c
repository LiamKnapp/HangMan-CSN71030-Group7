//Nihchal
//Group 7
//HangMan
#include "Header.h"


int Dash(char* wordtoguess) {
    
    int m;
    int charcount;

    charcount = 0;
    for (m = 0; wordtoguess[m]; m++) {
        if (wordtoguess[m] != ' ') {
            charcount++;
        }
    }

    printf("%s", wordtoguess);

 

    for (int n = 0; n < charcount; n++) {

        printf("-");
    }
    printf("Enter a word to guess: ");
    printf("Entrer un mot a deviner: ");
    userInput(wordtoguess);

}

int userInput(char* wordtoguess) {

    char c;

    printf("\n");

   
    scanf("%c", &c);

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= "Z"))
    {
        printf("Entrer un mot a deviner: \n");
        printf("Enter a word to guess: \n");
        GuessCheck(c, wordtoguess);
    }
    else {
        printf("Veuillez saisir un caractère valide: %c", c);
        printf("Please enter a valid character: %c", c);
        scanf_s("%*c", &c);
    }

}

int GuessCheck(char guess, char* wordtoguess) {

    int mistake = 0;
    int charcount = 0;
    int m;
    for (m = 0; wordtoguess[m]; m++) {
        if (wordtoguess[m] != ' ') {
            charcount++;
        }
    }

    if (strchr(wordtoguess, guess) != NULL) {
        printf("%c is in the word.\n", guess);
        
        userInput(wordtoguess);
    }
    else {
        mistake++;
        printBody(mistake);
        
    }
    if (mistake == 6) {
        printf("You Lose.\n");

        return 0;
    }

    userInput(wordtoguess);
}
