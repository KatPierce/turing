#include "tur.h"

void run()
{
    int len = strlen(alf);
    bool f=false;

    for(int i=0; i<N;  )
    {
        for(int j=0; j<M;  )
        {
            if( com[i][j].com == -1 )
                continue;
            // print
            printTape();
            printCom1(i,j);

            setTape(com[i][j].set);
            if( com[i][j].com == '>')
                Right();
            else if( com[i][j].com == '<')
                Left();

            if( com[i][j].q == 0 )
            {
                f=true;
                break;
            }

            // new i j
            j = com[i][j].q-1;
            char ch = tape[ptape];
            char ch2;
            for( int k=0; k<len; k++)
            {
                ch2 = alf[k];
                if( tape[ptape] == alf[k] )
                {
                    i = k;
                    break;
                }
            }
        } // end for j
        if(f)
            break;
    } // end for i

    printTape();
}

