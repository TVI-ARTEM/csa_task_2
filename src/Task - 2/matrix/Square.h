#ifndef __square__
#define __square__

//------------------------------------------------------------------------------
// Square.h - содержит описание обычной квадратной матрицы.
//------------------------------------------------------------------------------

#include "Matrix.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Обычная квадратная матрица.
class Square : public Matrix {
private:
    // Элементы матрицы.
    double **array{};
public:
    explicit Square(int dimension);
    ~Square();
    void In(FILE *fp) override;
    void InRandom() override;
    void Out(FILE *fWrite) override;
    double Average() override;
};

#endif