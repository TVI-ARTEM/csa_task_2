//------------------------------------------------------------------------------
// Diagonal.cpp - содержит функции обработки диагональной квадратной матрицы.
//------------------------------------------------------------------------------

#include "Diagonal.h"
#include <cstring>
#include <cstdio>
#include "../functions/tryParse.h"
#include "../functions/random.h"
#include "../functions/streamManage.h"

//------------------------------------------------------------------------------
// Случайный ввод обобщенной матрицы.
void Diagonal::In(FILE *fp) {
    array = new double[dimension];
    for (int i = 0; i < dimension; ++i) {
        char* temp = new char[Matrix::MAX_LENGTH];

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

    char* command = new char[Matrix::MAX_LENGTH];
    fscanf(fp, "%s", command);
    if (strcmp(command, "end") != 0) {
        delete this;
        FindNextCorrect(fp);
    }

    delete[] command;
}

//------------------------------------------------------------------------------
// Случайный ввод диагональной матрицы.
void Diagonal::InRandom() {
    for (int i = 0; i < dimension; ++i) {
        array[i] = Random(-10.0, 11.0);
    }
}

//------------------------------------------------------------------------------
// Вывод диагональной матрицы.
void Diagonal::Out(FILE *fWrite) {
    if (correct) {
        fprintf(fWrite, "%s%d%s", "It's Diagonal Matrix: dimension = ", dimension, "\n");
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                if (i == j) {
                    fprintf(fWrite, "%f%s", array[i], "");
                } else {
                    fprintf(fWrite, "%d%s", 0, " ");
                }
            }
            fprintf(fWrite, "%s","\n");
        }
        fprintf(fWrite, "%s%d%s", "Average ", Average(), "\n");
    } else {
        fprintf(fWrite, "%s","Incorrect Matrix\n");

    }
}

//------------------------------------------------------------------------------
// Удаление диагональной матрицы.
Diagonal::~Diagonal() {
    delete[] array;
    array = nullptr;
    dimension = 0;
    correct = false;
}

//------------------------------------------------------------------------------
// Подсчет среднего значения элементов диагональной матрицы.
double Diagonal::Average() {
    double average = 0;
    for (int i = 0; i < dimension; ++i) {
        average += array[i];
    }
    return average / (dimension * dimension);
}

//------------------------------------------------------------------------------
// Инициализация диагональной матрицы.
Diagonal::Diagonal(int dimension) {
    this->correct = true;
    this->dimension = dimension;
    this->array = new double [dimension];
}
