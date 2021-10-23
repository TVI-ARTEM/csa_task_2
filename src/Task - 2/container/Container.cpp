//------------------------------------------------------------------------------
// Container.cpp - содержит функции обработки контейнера.
//------------------------------------------------------------------------------

#include "Container.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Инициализация контейнера.
Container::Container() {
    currentLength = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов.
Container::~Container() {
    for (int i = 0; i < currentLength; ++i) {
        delete cont[i];
    }
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void Container::In(FILE *fp) {
    while (!feof(fp)) {
         if (((cont)[currentLength] = Matrix::StaticIn(fp)) != nullptr) {
            ++currentLength;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void Container::InRandom(int length) {
    for (; currentLength < length; ++currentLength) {
        cont[currentLength] = Matrix::StaticInRandom();
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Container::Out(FILE *fWrite) {
    if (currentLength > 0) {
        fprintf(fWrite, "%s", "Filled Container:\n");
        fprintf(fWrite, "%s%d%s", "Container contains ", currentLength, " elements\n");

        for (int i = 0; i < currentLength; i++) {
            fprintf(fWrite, "%d%s", i + 1, ": ");
            cont[i]->Out(fWrite);
        }
    } else {
        fprintf(fWrite, "%s", "Empty Container.\n");
        fprintf(fWrite, "%s%d%s", "Container contains ", currentLength, " elements\n");
    }
}

//------------------------------------------------------------------------------
// Сортировка контейнера методом вставки - straight sort.
void Container::Sort() {
    for (int i = 1; i < currentLength; ++i) {
        for (auto j = i; j > 0 && cont[j - 1]->Average() < cont[j]->Average(); --j) {
            auto temp = cont[j - 1];
            cont[j - 1] = cont[j];
            cont[j] = temp;
        }
    }
}


