#include "tur.h"
/*
Файл:

V
12345
*/

char tape[STAPE];
int ptape;
void clearTape()
{
    for( int i=0; i<STAPE; i++ )
    {
        tape[i]='_';
    }
    ptape = STAPE/2;
}

void loadTape()
{
    clearTape();
    FILE *in = fopen( "ftape.txt", "rt" );
    int v=-1;
    char ch;
    int j=ptape;
    int ret;
    char str[81];
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
        ret=fscanf( in, "%c", &ch );
        if( ch=='\n' || ret==EOF)
            break;
        tape[j++]=ch;
    }
    ptape += v;
    fclose(in);
}

void printTape()
{
    int d = 30;
    printf("%*c\n", d+1, 'V');
    for (int i = ptape - d; i < ptape+d; i++)
    {
        if (tape[i] == '_')
            printf(" ");
        else
            printf("%c",tape[i]);
    }
    printf("\n\n");
}

void Left()
{
    ptape--;
}

void Right()
{
    ptape++;
}

void setTape( char ch)
{
    tape[ptape] = ch;
}
