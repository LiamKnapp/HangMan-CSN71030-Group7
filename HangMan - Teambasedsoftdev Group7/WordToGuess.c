//Nihchal & Liam
//Group 7
//HangMan
#include "Header.h"

//global int declarations
int mistake = 0;
int saved = 0;

int Dash(char* wordtoguess, int lang) {
    mistake = 0;
    int charcount = 0;
    saved = 0;

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
    GuessCheck(wordtoguess, lang, charcount);

}

int GuessCheck(char* wordtoguess, int lang, int charcount) {
    char input;
    char savedinput[30];
    char* userguess = malloc(sizeof(char*));

mark:
    if (lang == 1) { // for english
        printf("\nType '1' to try and guess the word if you are ready!\nEnter a letter to guess: ");
    }
    if (lang == 2) { //for french
        printf("\nTapez '1' pour essayer de deviner le mot si vous etes pret!\nEntrer un lettre a deviner: ");
    }

    scanf("%c", &input); // to get the user input for there guess
    char c[2];
    fgets(c, 2, stdin);

    //check to see if the input is valid
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

        //if the letter is in the word
        if (strchr(wordtoguess, input) != NULL) {
            if (lang == 1) { // for english
                printf("%c : is in the word. \n", input);
                savedinput[saved] = input; // save the guess in an element
                for (int i = 0; i < charcount; i++) {
                    printf("%c, ", savedinput[i]);
                }
                printf(" : are all in the word\n");
                saved++;
            }
            if (lang == 2) { // for french
                printf("%c : est dans le mot\n", input);
                savedinput[saved] = input; // save the guess in an element
                for (int i = 0; i < charcount; i++) {
                    printf("%c, ", savedinput[i]);
                }
                printf(" : sont tous dans le mot\n");
                saved++;
            }
        }

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
    else {
        //if the user wants to try and guess the word
        if (input == '1') {
            if (lang == 1) {//for english
                printf("\nPlease enter the word you want to guess: ");
                scanf("%s", userguess);
            }
            if (lang == 2) {//for french
                printf("\nVeuillez entrer le mot que vous voulez deviner: ");
                scanf("%s", userguess);
            }
            // check if they got it correct
            if (strcmp(wordtoguess, userguess) == 0) { // if correct
                if (lang == 1) {//for english
                    printf("\n%s : is the correct word!\nYOU WIN!\n", userguess);
                    menu(lang);
                }
                if (lang == 2) {//for french
                    printf("\n%s : est le bon mot!\nVOUS GAGNEZ!\n", userguess);
                    menu_French(lang);
                }
            }
            else { // if not correct
                if (lang == 1) {//for english
                    printf("\n%s : is not the correct word!\n", userguess);
                    mistake++;
                    printBody(mistake);
                }
                if (lang == 2) {//for french
                    printf("\n%s : n'est pas le bon mot!\n", userguess);
                    mistake++;
                    printBody(mistake);
                }
            }
        }
        else {
            if (lang == 1) {//for english
                printf("\nPlease enter a valid character!");
            }
            if (lang == 2) {//for french
                printf("\nVeuillez saisir un caractere valide!");
            }
        }
    }

    goto mark;
}