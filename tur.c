#include "tur.h"

int main(int argc, char *args[]) {
    bool mode = false; //режим: 1-debug, 0- run
    int tSize = STAPE;
    char *tape;
    int ptape = 0;

    if (argc != 5) {
        printf("Use: turing.exe -r/-d tape.txt com.txt out.txt\n");
        printf(*args);
        return -1;
    }
    if (args[1][0] == '-')
        switch (args[1][1]) {
            case 'r':      //run
                mode = false;
                break;
            case 'd':                //debug
                mode = true;
                break;
            default:
                printf("There must be -d or -r.\n");
                break;
        }
    else {
        printf("The 2d argument must be -r or -d.\n");
        printf("%s", args[1]);
        return -1;
    }

    printf(args[3]);
    loadTape(args[2], &tape, &ptape, &tSize);
    printTape(stdout, &tape, tSize, ptape);
    loadCom(args[3]);
    printCom();
    run((char *) &args[4], mode, &tape, &ptape, &tSize);

    if (tape != NULL)
        free(tape);

    return 0;
}