#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* Liam */
// File System Functions
int FileEncrypt(int);
int FileDecrypt(int);
char* FileGetWord(int);
int FileRemoveWord(char[], int);
int FileReuseWords(int);

/* Will */
// Math Gamemode Functions
int MathtoGuess(int);
int getGuess(int);
int checkGuess(int, int);

/* Nihchal */
// Word Gamemode Functions


/* Minh */
// UI Menu Functions
void menu(int);
void printBody(int mistakes);
void menu_language();
void menu_French(int);