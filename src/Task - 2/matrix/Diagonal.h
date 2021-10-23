#ifndef __diagonal__
#define __diagonal__

//------------------------------------------------------------------------------
// Diagonal.h - содержит описание диагональной квадратной матрицы.
//------------------------------------------------------------------------------

#include "Matrix.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Диагональная квадратная матрица.
class Diagonal : public Matrix {
private:
    // Элементы матрицы.
    double *array;
public:
    explicit Diagonal(int dimension);
    ~Diagonal();
    void In(FILE *fp) override;
    void InRandom() override;
    void Out(FILE *fWrite) override;
    double Average() override;
};

#endif