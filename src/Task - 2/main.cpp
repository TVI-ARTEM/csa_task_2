//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, выполняющую тестирование.
//------------------------------------------------------------------------------

#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "container/Container.h"


void commandLineError() {
    printf("incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

void qualifierValueError() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

int main(int argCount, char* argValues[]) {
    auto start = clock();

    if (argCount != 5) {
        commandLineError();
        return 1;
    }

    printf("Start\n");

    auto* c = new Container();

    if(!strcmp(argValues[1], "-f")) {
        FILE *fp;
        // Проверка файла на существование.
        if ((fp = fopen(argValues[2], "r")) == nullptr) {
            printf("Incorrect In-file");
            return 2;
        }
        c->In(fp);
        fclose(fp);
    }
    else if(!strcmp(argValues[1], "-n")) {
        auto length = atoi(argValues[2]);
        if((length < 1) || (length > 10000)) {
            printf("%s%d%s","incorrect number of matrixes = ", length,
                 ". Set 0 < number <= 10000\n");
            return 3;
        }
        srand(static_cast<unsigned int>(time(nullptr)));
            c->InRandom(length);
    }
    else {
        qualifierValueError();
        return 4;
    }

    // Вывод контейнера до сортировки.
    FILE *fWriteFirst;
    fWriteFirst = fopen(argValues[3], "w");

    c->Out(fWriteFirst);
    fprintf(fWriteFirst, "%s%f%s","\nTime: ",(clock() - start) * 1.0 / CLOCKS_PER_SEC,"s\n");
    fclose(fWriteFirst);

    // Вывод контейнера после сортировки.
    FILE *fWriteSecond;
    fWriteSecond = fopen(argValues[4], "w");
    fprintf(fWriteSecond, "%s", "---Sorted Container---\n");
    c->Sort();
    c->Out(fWriteSecond);
    fprintf(fWriteFirst, "%s%f%s","\nTime sorted: ",(clock() - start) * 1.0 / CLOCKS_PER_SEC,"s\n");

    delete c;
    fprintf(fWriteFirst, "%s%f%s","\nTime after clearing: ",(clock() - start) * 1.0 / CLOCKS_PER_SEC,"s\n");
    fclose(fWriteSecond);

    printf("End\n");

    return 0;
}
