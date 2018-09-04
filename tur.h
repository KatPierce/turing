

#ifndef TURING_TUR_H
#define TURING_TUR_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define STAPE 20 //размер ленты
#define EXTAPE 50 //расширение ленты
#define ENTER 13 //код клавиш
#define DOWN 80
#define ESC 27

void clearTape(char **tape, int *ptape, int tSize);
void loadTape(char *input, char **tape, int *ptape, int *tSize);
void printTape(FILE *output, char **tape, int tSize, int ptape);
void Left(int *ptape, int *tSize, char **tape );
void Right(int *ptape, int *tSize, char **tape );
void setTape(char *tape, int ptape, char ch);
void move( char c, int *ptape, int *tSize, char **tape);

/*
0>1   set='0' com='>' q=1
*/
struct COMMAND
{
    char mark, com;
    int q;
};

void clearCom();
void loadCom(char **input);
void printCom();
void printCom1(int i, int j);

//extern char tape[STAPE];
//extern char *tape;
//extern int *ptape;
extern struct COMMAND **com;
extern int N, M; // N - кол-во строк(символов ал) в таблице команд, M - столбцов
extern char alf[256];

void run(char *output, bool mode, char **tape, int *ptape, int *tSize);

#endif //TURING_TUR_H
