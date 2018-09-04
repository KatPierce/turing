#include "tur.h"
/*
Файл:

V
12345
*/

//char tape[STAPE];
//char *tape;
//int ptape;

void clearTape(char **tape, int *ptape, int tSize )
{
//   if(tape != NULL)
//        free(*tape);
    *tape = (char* )calloc(tSize, sizeof(char));
    for( int i=0; i<tSize; i++ )
    {
        tape[i]= (char *) '_';
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
        tape[j++]=  ch;
    }
    *ptape += v;
    fclose(in);
}

void printTape(FILE *output, char **tape, int tSize, int ptape)
{
    int sh = 30;
    fprintf(output, "%*c\n", sh+1, 'V');
    for (int i = ptape - sh; i < ptape+sh; i++)
    {
        if (tape[i] == '_')
            printf(" ");
        else
            printf("%c",tape[i]);
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
