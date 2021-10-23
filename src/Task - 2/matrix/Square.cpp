//------------------------------------------------------------------------------
// Square.cpp - содержит функции обработки обычной квадратной матрицы.
//------------------------------------------------------------------------------

#include "Square.h"
#include <cstdio>
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Ввод квадратной матрицы.
void Square::In(FILE *fp) {
    array = new double *[dimension];

    for (int i = 0; i < dimension; ++i) {
        array[i] = new double [dimension];
        for (int j = 0; j < dimension; ++j) {
            char* temp = new char[Matrix::MAX_LENGTH];

            // Проверка значения на корректность или поиск следующей корректной матрицы.
            if (!feof(fp)) {
                fscanf(fp, "%s", temp);
            } else {
                delete this;
                FindNextCorrect(fp);
                return;
            }

            if (!TryParse(temp, &array[i][j])) {
                delete this;
                FindNextCorrect(fp);
                return;
            }

            delete[] temp;
        }
    }

    if (feof(fp)) {
        delete this;
        return;
    }

    char* command = new char[Matrix::MAX_LENGTH];
    fscanf(fp, "%s", command);
    if (strcmp(command, "end") != 0) {
        delete this;
        FindNextCorrect(fp);
    }
    delete[] command;
}

//------------------------------------------------------------------------------
// Случайный ввод квадратной матрицы.
void Square::InRandom() {
    for (int i = 0; i < dimension; ++i) {
        array[i] = new double [dimension];
        for (int j = 0; j < dimension; ++j) {
            array[i][j] = Random(-10.0, 11.0);
        }
    }
}

//------------------------------------------------------------------------------
// Вывод квадратной матрицы.
void Square::Out( FILE *fWrite) {
    if (correct) {
        fprintf(fWrite, "%s%d%s", "It's Square Matrix: dimension = ", dimension, "\n");
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                fprintf(fWrite, "%f%s", array[i][j], " ");
            }
            fprintf(fWrite, "%s","\n");

        }
        fprintf(fWrite, "%s%f%s", "Average ", Average(), "\n");

    } else {
        fprintf(fWrite, "%s","Incorrect Matrix\n");
    }
}

//------------------------------------------------------------------------------
// Удаление квадратной матрицы.
Square::~Square()  {
    for (int i = 0; i < dimension; ++i) {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;
    dimension = 0;
    correct = false;
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов квадратной матрицы.
double Square::Average() {
    double average = 0;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            average += array[i][j];
        }
    }
    return average / (dimension * dimension);
}
//------------------------------------------------------------------------------
// Инициализация квадратной матрицы.
Square::Square(int dimension) {
    this->correct = true;
    this->dimension = dimension;
    this->array = new double *[dimension];
}


