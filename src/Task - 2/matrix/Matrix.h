#ifndef __matrix__
#define __matrix__

//------------------------------------------------------------------------------
// Matrix.h - содержит описание обобщающей квадратной матрицы.
//------------------------------------------------------------------------------
#include <cstdio>
#include <cstring>
//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся квадратные матрицы.
class Matrix {
protected:
    int dimension{};
    bool correct{};
public:
    enum {MAX_LENGTH = 1000000};
    static Matrix* StaticIn(FILE *fp);
    virtual void In(FILE *fp) = 0;
    static Matrix* StaticInRandom();
    virtual void InRandom() = 0;
    virtual void Out(FILE *fWrite) = 0;
    virtual double Average() = 0;
};

#endif