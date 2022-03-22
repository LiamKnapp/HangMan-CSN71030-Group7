//Nihchal
//Group 7
//HangMan
#include "Header.h"


int Dash(char* wordtoguess, int lang) {

    int m;
    int charcount;

    charcount = 0;
    for (m = 0; wordtoguess[m]; m++) {
        if (wordtoguess[m] != ' ') {
            charcount++;
        }
    }

    printf("%s\n", wordtoguess);



    for (int n = 0; n < charcount; n++) {

        printf("-");
    }
    if (lang == 1) {
        printf("\nEnter a word to guess: ");
    }
    if (lang == 2) {
        printf("\nEntrer un mot a deviner: ");
    }
    userInput(wordtoguess, lang);

}

int userInput(char* wordtoguess, int lang) {

    char c;

    printf("\n");

   
    scanf("%c", &c);

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= "Z"))
    {
        if (lang == 1) {
            printf("Enter a word to guess: \n");
        }
        if (lang == 2) {
            printf("Entrer un mot a deviner: \n");
        }
        GuessCheck(c, wordtoguess,lang);
    }
    else {
        if (lang == 1) {
            printf("Please enter a valid character: %c", c); printf("Enter a word to guess: \n");
        }
        if (lang == 2) {
            printf("Veuillez saisir un caractere valide: %c", c);
        }
        
        scanf_s("%*c", &c);
    }

}

int GuessCheck(char guess, char* wordtoguess, int lang) {

    int mistake = 0;
    int charcount = 0;
    int m;
    for (m = 0; wordtoguess[m]; m++) {
        if (wordtoguess[m] != ' ') {
            charcount++;
        }
    }

    if (strchr(wordtoguess, guess) != NULL) {
        if (lang == 1) {
            printf("%c is in the word.\n", guess); printf("Enter a word to guess: \n");
        }
        if (lang == 2) {
            printf("%c est dans le mot. \n", guess);
        }
        
        userInput(wordtoguess, lang);
    }
    else {
        mistake++;
        printBody(mistake);
        
    }
    if (mistake == 6) {
        if (lang == 1) {
            printf("You Lose.\n");
        }
        if (lang == 2) {
            printf("Tu as perdu. \n");
        }

        return 0;
    }

    userInput(wordtoguess, lang);
}
