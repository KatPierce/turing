

#ifndef TURING_TUR_H
#define TURING_TUR_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define STAPE 500

void clearTape();
void loadTape();
void printTape();
void Left();
void Right();
void setTape( char ch);

/*
0>1   set='0' com='>' q=1
*/
struct COMMAND
{
    char set,
            com;
    int q;
};

void clearCom();
void loadCom();
void printCom();
void printCom1(int i, int j);

extern char tape[STAPE];
extern int ptape;
extern struct COMMAND **com;
extern int N, M;
extern char alf[21];

void run();

#endif //TURING_TUR_H
