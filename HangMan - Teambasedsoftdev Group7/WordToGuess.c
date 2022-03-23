//Nihchal
//Group 7
//HangMan
#include "Header.h"


int Dash(char* wordtoguess, int lang) {

    int m;
    int charcount;

    //check to see the length of the word
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
    userInput(wordtoguess, lang);

}

int userInput(char* wordtoguess, int lang) {

    char input;

    if (lang == 1) { // for english
        printf("\nEnter a word to guess: ");
    }
    if (lang == 2) { //for french
        printf("\nEntrer un mot a deviner: ");
    }

    scanf("%c", &input);

    //check input is good
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

    //check if the input is in the word
    GuessCheck(input, wordtoguess, lang);

    }
}

int mistake = 0;

int GuessCheck(char guess, char* wordtoguess, int lang) {

mark:
    //if the letter is in the word
        if (strchr(wordtoguess, guess) != NULL) {
            if (lang == 1) { // for english
                printf("%c is in the word.\n", guess);
            }
            if (lang == 2) { // for french
                printf("%c est dans le mot. \n", guess);
            }
        }

        //if the letter is not in the word
        if (strchr(wordtoguess, guess) == NULL) {
            mistake++;
            printf("Mistake = %d", mistake);
            printBody(mistake);
        }

        //if the user runs out of guesses
        if (mistake == 6) {
            if (lang == 1) { // for english
                printf("You Lose.\n\n");
                menu(lang);
               // break;
            }
            if (lang == 2) { // for french
                printf("Tu as perdu.\n\n");
                menu_French(lang);
               // break;
            }

        }
        userInput(wordtoguess, lang);

        goto mark;
}
