#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// Container.h - содержит тип данных - матрица,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "../matrix/Matrix.h"
#include <cstdio>
//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
class Container {
public:
    enum {MAX_LEN = 10000};
    Container();
    ~Container();
    void In(FILE *fp);
    void InRandom(int length);
    void Out(FILE *fp);
    void Sort();
private:
    int currentLength;
    Matrix *cont[MAX_LEN]{};
};

#endif //__container__
