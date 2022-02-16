#pragma once
#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int FileEncrypt(int);
int FileDecrypt(int);
char* FileGetWord(int);
int FileRemoveWord(char[], int);
void menu();
void printBody(int mistakes, char* body);
void menu_language();
void menu_French();