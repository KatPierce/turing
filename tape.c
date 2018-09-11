#include "tur.h"
/*
Файл:

V
12345
*/


void clearTape(char **tape, int *ptape, int tSize )
{
//   if(tape != NULL)
//        free(*tape);
    *tape = (char* )calloc(tSize, sizeof(char));
    for( int i=0; i<tSize; i++ )
    {
        *(*tape+i)= '_';
    }
    *ptape = tSize/2;
}

void loadTape(char *input, char **tape, int *ptape, int *tSize)
{
    clearTape(tape,ptape,*tSize);
    FILE *in = fopen( input, "rt" );
    int v=-1;
    char ch;
    int j=*ptape;
    int res;
    char str[81]; // золотой стандарт
    fgets(str,80,in);
    int len = strlen(str);
    for( int i=0; i<len; i++ )
    {
        if( str[i] == 'V' )
        {
            v=i;
            break;
        }
    }
    while(1)
    {
        res=fscanf( in, "%c", &ch );
        if( ch=='\n' || res==EOF)
            break;
        *(*tape+j)=  ch;
        j++;
    }
    *ptape += v;
    fclose(in);
}

void printTape(FILE *output, char *tape, int tSize, int ptape)
{
    int gap=80;
    int st = gap/2;
    int i = ptape-st;

    fprintf(output, "%*c\n", st+1, 'V');
    for (int k=0; k < gap; i++, k++)
    {
        if(!(tape[i]=='_'|| i<0 || i>tSize ))
            fprintf(output,"%c",tape[i]);
        else
            fprintf(output," ");
    }

    fprintf(output,"\n\n");
}

void Left(int *ptape, int *tSize, char **tape )
{
    (*ptape)--;
    if (*ptape>=0)
    {
        return;
    }
    int size = *tSize;
    *tSize += EXTAPE;
    char *temp = (char *)calloc(size, sizeof(char));
    *tape = (char *)realloc(*tape, *tSize);
    //переносим
    for (int i = 0, j = EXTAPE; i<size; i++, j++)
    {
        *(*tape+j) = *(temp+i);
    }
    *ptape = *tSize-size-1;

}

void Right(int *ptape, int *tSize, char **tape )
{
    (*ptape)++;
    if (*ptape < *tSize)
        return;
    *tSize += EXTAPE;
    *tape = (char *)realloc(*tape, *tSize);
    for( int i= *ptape; i< *tSize; i++ )
        *(*tape+i)= '_';
}

void setTape( char *tape, int ptape, char ch)
{
    tape[ptape] = ch;
}

void move( char c, int *ptape, int *tSize, char **tape)
{
    switch (c)
    {
        case '>' : Right(ptape,tSize, tape);
                    break;
        case '<' : Left(ptape,tSize, tape);
                    break;
        default: printf("Wrong command. There must be < or > \n");
                    break;
    }

}
