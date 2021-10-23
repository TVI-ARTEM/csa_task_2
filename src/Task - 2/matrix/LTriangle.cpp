//------------------------------------------------------------------------------
// LTriangle.cpp - содержит функции обработки нижнетреугольной квадратной матрицы.
//------------------------------------------------------------------------------

#include "LTriangle.h"
#include <cstdio>
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Ввод нижнетреугольной матрицы.
void LTriangle::In(FILE *fp) {
    array = new double[dimension * (dimension + 1) / 2];
    for (int i = 0; i < dimension * (dimension + 1) / 2; ++i) {
        char *temp = new char[Matrix::MAX_LENGTH];

        // Проверка значения на корректность или поиск следующей корректной матрицы.
        if (!feof(fp)) {
            fscanf(fp, "%s", temp);
        } else {
            delete this;
            FindNextCorrect(fp);
            return;
        }

        if (!TryParse(temp, &array[i])) {
            delete this;
            FindNextCorrect(fp);
            return;
        }
        delete[] temp;
    }

    if (feof(fp)) {
        delete this;
        return;
    }

    char *command = new char[Matrix::MAX_LENGTH];
    fscanf(fp, "%s", command);
    if (strcmp(command, "end") != 0) {
        delete this;
        FindNextCorrect(fp);
    }
    delete[] command;
}

//------------------------------------------------------------------------------
// Случайный ввод нижнетреугольной матрицы.
void LTriangle::InRandom() {
    for (int i = 0; i < dimension * (dimension + 1) / 2; ++i) {
        array[i] = Random(-10.0, 11.0);
    }
}

//------------------------------------------------------------------------------
// Вывод нижнетреугольной матрицы.
void LTriangle::Out(FILE *fWrite) {
    if (correct) {
        fprintf(fWrite, "%s %d %s", "It's low triangle Matrix: dimension = ", dimension, "\n");
        int count = 0;
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                if (i >= j) {
                    fprintf(fWrite, "%f %s", array[count], "");

                    ++count;
                } else {
                    fprintf(fWrite, "%d %s", 0, "");

                }
            }
            fprintf(fWrite, "%s", "\n");

        }
        fprintf(fWrite, "%s %f %s", "Average ", Average(), "\n");

    } else {
        fprintf(fWrite, "%s", "Incorrect Matrix\n");

    }
}

//------------------------------------------------------------------------------
// Удаление нижнетреугольной матрицы.
LTriangle::~LTriangle() {
    delete[] array;
    array = nullptr;
    dimension = 0;
    correct = false;
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов нижнетреугольной матрицы.
double LTriangle::Average() {
    double average = 0;
    for (int i = 0; i < dimension * (dimension + 1) / 2; ++i) {
        average += array[i];
    }
    return average / (dimension * dimension);
}

//------------------------------------------------------------------------------
// Инициализация нижнетреугольной матрицы.
LTriangle::LTriangle(int dimension) {
    this->correct = true;
    this->dimension = dimension;
    this->array = new double[dimension * (dimension + 1) / 2];
}
