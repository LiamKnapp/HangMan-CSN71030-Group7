//Nihchal
//Group 7
//HangMan
#include "Header.h"

//global int declarations
int mistake = 0;
int saved = 0;

int Dash(char* wordtoguess, int lang) {

    int charcount = 0;

    //check to see the length of the word
    for (int i = 0; wordtoguess[i]; i++) {
        if (wordtoguess[i] != ' ') {
            charcount++;
        }
    }

    printf("%s\n", wordtoguess); //remove this after we finish the function

    //print the amount of dashs that corresponds with teh random word
    for (int i = 0; i < charcount; i++) {

        printf("-");
    }

    //call the function to get input and guess checking (main gamemode run code)
    GuessCheck(wordtoguess, lang);

}

int GuessCheck(char* wordtoguess, int lang) {
    char input;
    char savedinput[6];
    //the size of this array will need to be the same size as the wordtoguess this is temp
    //array might be wrong approach. should explore possibility of dynamic allocation and string
mark:
    if (lang == 1) { // for english
        printf("\nEnter a word to guess: ");
    }
    if (lang == 2) { //for french
        printf("\nEntrer un mot a deviner: ");
    }

    scanf("%c", &input); // to get the user input for there guess

    //check to see if the input is valid
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

    //if the letter is in the word
        if (strchr(wordtoguess, input) != NULL) {
            if (lang == 1) { // for english
                printf("%c is in the word. \n", input);
            }
            if (lang == 2) { // for french
                printf("%c est dans le mot. \n", input);
            }
            savedinput[saved] = input; // save the guess in an element
            saved++;
        }

        /*      THIS IS THE NEXT STATEMENT NEEDED TO BE MADE
                THIS IS A ROUGH GUESS ON HOW IT SHOULD BE MADE  
                THIS IS FOR THE WIN CONDITION TO END THE PROGRAM    */  

        //if the saved char array is the same size as the word to guess
            //if each char at each element in the saved char array is in the wordtoguess
            //the player wins display the word
            //return to the main menu so they can play the game again
        //else
            // the player hasnt won yet so continue the program

        //if the letter is not in the word
        if (strchr(wordtoguess, input) == NULL) {
            mistake++;
            printBody(mistake);
            if (lang == 1) {
                printf("%c : is not in the word\n", input);
            }
            if (lang == 2) {
                printf("%c : n'est pas dans le mot\n", input);
            }
        }

        //if the user runs out of guesses
        if (mistake == 6) {
            if (lang == 1) { // for english
                printf("You Lose.\n\n");
                menu(lang);
            }
            if (lang == 2) { // for french
                printf("Tu as perdu.\n\n");
                menu_French(lang);
            }
        }
    } 
    //if the input is invalid
    else {
        if (lang == 1) {//for english
            printf("\nPlease enter a valid character!");
        }
        if (lang == 2) {//for french
            printf("Veuillez saisir un caractere valide!");
        }
    }

    goto mark;
}
