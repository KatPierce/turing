#include "tur.h"

int main()
{
    loadTape();
    printTape();

    loadCom();
    printCom();

    run();

    return 0;
}