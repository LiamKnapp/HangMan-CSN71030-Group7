//Nihchal & Liam
//Group 7
//HangMan
#include "Header.h"
#define MAX_LEN_NAME 100
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

    printf("\n");
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
    char name[MAX_LEN_NAME];
    
    GameInfor tmp;
    time_t mytime = time(NULL);
    char* time_str = ctime(&mytime);
    time_str[strlen(time_str) - 1] = '\0';
    clock_t start, end;  
    double time_use;
    start = clock();
    if (lang == 1) {
        printf("\n%d Total letters\n", charcount);
    }
    if (lang == 2) {
        printf("\n%d Nombre total de lettres\n", charcount);
    }
   
    
    while (1) {
        if (lang == 1) { // for english
            printf("\nType '1' to try and guess the word if you are ready!\nEnter a letter to guess: ");
        }
        if (lang == 2) { //for french
            printf("\nTapez '1' pour essayer de deviner le mot si vous etes pret!\nEntrer un lettre a deviner: ");
        }
    mark:
        scanf("%c", &input); // to get the user input for there guess
        char c[2];
        fgets(c, 2, stdin);
        int n = 0;
        //check to see if the input is valid
        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
            //if the letter is in the word
            if (strchr(wordtoguess, input) != NULL) {
                if (lang == 1) { // for english
                    // check to see if the user has already entered that letter
                    for (int i = 0; savedinput[i]; i++) {
                        if (savedinput[i] == input) {
                            printf("\nYou already guess that letter!\nTry again: ");
                            goto mark;
                        }
                    }


                    //find if the letter appears in the word more then once
                    for (int i = 0; wordtoguess[i]; i++) {
                        if (wordtoguess[i] == input){
                        
                            n++;
                        }
                    }

                    printf("\n%c : is in the word %d times. \n", input, n);

                    //save the word in the array depending on how many times it appears
                    for (int i = 0; i < n; i++) {
                        savedinput[saved] = input;
                        saved++;
                    }

                    //print the letters that the user has gotten correct
                    for (int i = 0; i < charcount; i++) {
                        printf("%c, ", savedinput[i]);
                    }
                    printf(" : are all in the word\n");
                }

                if (lang == 2) { // for french

                    // check to see if the user has already entered that letter
                    for (int i = 0; savedinput[i]; i++) {
                        if (savedinput[i] == input) {
                            printf("\nVous devinez deja cette lettre!\nReessayer: ");
                            goto mark;
                        }
                    }

                     //find if the letter appears in the word more then once
                    for (int i = 0; wordtoguess[i]; i++) {
                        if (wordtoguess[i] == input) {

                            n++;
                        }
                    }

                    printf("%c : est dans le mot %d fois\n", input, n);

                    //save the word in the array depending on how many times it appears
                    for (int i = 0; i < n; i++) {
                        savedinput[saved] = input;
                        saved++;
                    }

                    for (int i = 0; i < charcount; i++) {
                        printf("%c, ", savedinput[i]);
                    }
                    printf(" : sont tous dans le mot\n");
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
                    printf("You Lose.\n");
                    printf("The word was: %s\n\n", wordtoguess);
                    menu(lang);
                    break;
                }
                if (lang == 2) { // for french
                    printf("Tu as perdu.\n");
                    printf("Le mot etait %s\n\n", wordtoguess);
                    menu_French(lang);
                    break;
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
                        end = clock();
                        time_use = (double)(end - start);
                        printf("\nPlease enter your name:\n");
                        scanf_s("%s", &name, sizeof(name)); 
                        strcpy(tmp.Player_1, name);
                        tmp.Score = charcount;
                        strcpy(tmp.time, time_str);
                        strcpy(tmp.word, wordtoguess);
                        tmp.time_count = time_use / 1000; // count the second
                        Insert(tmp);
                        menu(lang);
                        break;
                    }
                    if (lang == 2) {//for french
                        printf("\n%s : est le bon mot!\nVOUS GAGNEZ!\n", userguess);
                        end = clock();
                        time_use = (double)(end - start);
                        printf("S'il vous plait entrez votre nom:\n");
                        scanf_s("%s", &name, sizeof(name));
                        strcpy(tmp.Player_1, name);
                        tmp.Score = charcount;
                        strcpy(tmp.time, time_str);
                        strcpy(tmp.word, wordtoguess);
                        tmp.time_count = time_use / 1000;
                        Insert(tmp);
                        menu_French(lang);
                        break;
                    }
                }
                else { // if not correct
                    if (lang == 1) {//for english
                        printf("\n%s : is not the correct word!\n", userguess);
                        mistake++;
                        printBody(mistake);
                        char c[2];
                        fgets(c, 2, stdin);
                    }
                    if (lang == 2) {//for french
                        printf("\n%s : n'est pas le bon mot!\n", userguess);
                        mistake++;
                        printBody(mistake);
                        char c[2];
                        fgets(c, 2, stdin);
                    }
                    //if the user runs out of guesses
                    if (mistake == 6) {
                        if (lang == 1) { // for english
                            printf("You Lose.\n");
                            printf("The word was: %s\n\n", wordtoguess);
                            menu(lang);
                            break;
                        }
                        if (lang == 2) { // for french
                            printf("Tu as perdu.\n");
                            printf("Le mot etait %s\n\n", wordtoguess);
                            menu_French(lang);
                            break;
                        }
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

    }

}