#include "tur.h"

void run(char *output, bool mode, char **tape, int *ptape, int *tSize) {
    int len = strlen(alf);
    bool f = false;
    char comType;
    FILE *oFile;
    int x;

    oFile = fopen(&output, "wt");
    if (oFile == NULL) {
        printf("Output file %s can't be open.\n", output);
        exit(1);
    }
    if (mode) {
        printf("Press DOWN for next step, ENTER - run program, ESC- finish program");
    }
    for (int i = 0; i < N;) {
        for (int j = 0; j < M;) {
            if (com[i][j].com == -1)
                continue;
            // print
            printTape(oFile, *tape, *tSize, *ptape);
            printCom1(i, j);

            comType = com[i][j].mark;
            switch (comType) {
                case 'W':
                    setTape(*tape, *tSize, com[i][j].com);
                    break;
                case 'S':
                    move(com[i][j].com, ptape, tSize, tape);
                    break;
                case '_':
                    if (!((com[i][j].com == '.') && (com[i][j].q == 0)))
                        printf("Wrong command.\n");
                    break;
                default:
                    printf("Wrong command. There must be W or S \n");
                    break;
            } //разбираем команду: W- запись на ленту, S- сдвиг


            //q=0 состояние останова машины
            if (com[i][j].q == 0) {
                f = true;
                break;
            }

            //режим отладки
            if (mode) {
                do {
                    x = getch();
                    if (x == DOWN)
                        break;
                    if (x == ENTER) {
                        mode = false;
                        break;
                    }
                    if (x == ESC) {
                        printf("Program was stopped.\n");
                        fprintf(oFile, "Program was stopped.\n");
                        return;
                    }
                    printf("Wrong key. Press Enter/Esc/Down");

                } while (1);
            }


            // new i j
            j = com[i][j].q - 1;
            char ch = *tape[*ptape];
            char ch2;
            for (int k = 0; k < len; k++) {
                ch2 = alf[k];
                if (ch == ch2) {
                    i = k;
                    break;
                }
            }
        } // end for j
        if (f)
            break;
    } // end for i

    printTape(oFile, *tape, *tSize, *ptape);
    fprintf(oFile, "STOP\n");
    fclose(oFile);
}

