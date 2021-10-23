#ifndef __streamManage__
#define __streamManage__

//------------------------------------------------------------------------------
// streamManage.h - содержит функцию, ищущую следующую корректную матрицу.
//------------------------------------------------------------------------------

#include <fstream>

//------------------------------------------------------------------------------
// Поиск следующей корректной матрицы.
inline void FindNextCorrect(FILE *fp) {
    char* command = new char[10000];

    while (!feof(fp)) {
        fscanf(fp, "%s", command);

        if (!strcmp(command, "end")) {
            break;
        } else if (!strcmp(command, "begin")) {
            fseek(fp, ftell(fp) - 5, SEEK_SET);
            break;
        }
    }
    delete[] command;
}

#endif //__streamManage__
