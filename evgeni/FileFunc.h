#ifndef FILEFUNC_H
#define FILEFUNC_H

#include "StringFunc.h"
#include "IndexFunc.h"

struct BufAndIndexInf
{
    char* buf;
    struct Line* index;
    int CntLines;
};

struct BufAndIndexInf FileReadAndMakeBuf(const char* filename);


#endif //FILEFUNC_H
