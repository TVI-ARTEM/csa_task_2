#ifndef __lTriangle__
#define __lTriangle__

//------------------------------------------------------------------------------
// LTriangle.h - содержит описание нижнетреугольной квадратной матрицы.
//------------------------------------------------------------------------------

#include "Matrix.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Нижнетреугольная квадратная матрица.
class LTriangle : public Matrix {
private:
    // Элементы матрицы.
    double *array;
public:
    explicit LTriangle(int dimension);
    ~LTriangle();
    void In(FILE *fp) override;
    void InRandom() override;
    void Out(FILE *fWrite) override;
    double Average() override;
};


#endif //__lTriangle__
