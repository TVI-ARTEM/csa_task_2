//------------------------------------------------------------------------------
// Matrix.cpp - содержит функции обработки обобщенной квадратной матрицы.
//------------------------------------------------------------------------------

#include <cstring>
#include <cstdio>
#include "Matrix.h"
#include "Square.h"
#include "Diagonal.h"
#include "LTriangle.h"
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Ввод обобщенной матрицы.
Matrix *Matrix::StaticIn(FILE *fp) {
    char* command = new char[Matrix::MAX_LENGTH];
    fscanf(fp, "%s", command);

    // Проверка комманды на корректность или поиск следующей корректной матрицы.
    if (strcmp(command, "begin") != 0) {
        FindNextCorrect(fp);
        delete[] command;
        return nullptr;
    }
    delete[] command;

    int key, dimension;

    char* temp = new char[Matrix::MAX_LENGTH];
    fscanf(fp, "%s", temp);


    // Проверка значения на корректность или поиск следующей корректной матрицы.
    if (!TryParse(temp, &key) && key > 0) {
        FindNextCorrect(fp);
        delete[] temp;
        return nullptr;
    }

    fscanf(fp, "%s", temp);
    // Проверка значения на корректность или поиск следующей корректной матрицы.
    if (!TryParse(temp, &dimension) || !(dimension > 0 && dimension < 101)) {
        FindNextCorrect(fp);
        delete[] temp;
        return nullptr;
    }
    delete[] temp;
    Matrix* matrix = nullptr;
    switch (key) {
        case 1: {
            matrix = new Square(dimension);
            break;
        }
        case 2: {
            matrix = new Diagonal(dimension);
            break;
        }
        case 3: {
            matrix = new LTriangle(dimension);
            break;
        }
        default:
            return nullptr;
    }
    matrix->In(fp);
    return matrix;
}

//------------------------------------------------------------------------------
// Случайный ввод обобщенной матрицы.
Matrix *Matrix::StaticInRandom() {
    auto key = Random(1, 4);
    auto dimension = Random(1, 21);
    Matrix* matrix = nullptr;
    switch(key) {
        case 1: {
            matrix = new Square(dimension);
            break;
        }
        case 2: {
            matrix = new Diagonal(dimension);
            break;
        }
        case 3: {
            matrix = new LTriangle(dimension);
            break;
        }
        default:
            return nullptr;
    }
    matrix->InRandom();
    return matrix;
}



