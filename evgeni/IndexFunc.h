#ifndef INDEXFUNC_H
#define INDEXFUNC_H
#include "StringFunc.h"


unsigned long long int CountOfSymbols(const char* name);
void FillIndex(char* buf, struct stroka* index, long long int count);
void FillOutput(struct stroka* index, FILE* output, int  len);
unsigned int FillBuf(const unsigned long long int cnt, FILE* text, char* buf);


#endif
