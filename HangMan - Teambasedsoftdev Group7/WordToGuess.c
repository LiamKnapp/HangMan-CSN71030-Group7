//Nihchal
//Group 7
//HangMan
#include "Header.h"

int mistake = 0;

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

    GuessCheck(wordtoguess, lang);

}

int GuessCheck(char* wordtoguess, int lang) {

    char input;
mark:
    
    if (lang == 1) { // for english
        printf("\nEnter a word to guess: ");
    }
    if (lang == 2) { //for french
        printf("\nEntrer un mot a deviner: ");
    }

    scanf("%c", &input);

    //if valid
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

    //if the letter is in the word
        if (strchr(wordtoguess, input) != NULL) {
            if (lang == 1) { // for english
                printf("%c is in the word.\n", input);
            }
            if (lang == 2) { // for french
                printf("%c est dans le mot. \n", input);
            }
        }

        //if the letter is not in the word
        if (strchr(wordtoguess, input) == NULL) {
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
    }
    goto mark;
}
