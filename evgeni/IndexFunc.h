#ifndef INDEXFUNC_H
#define INDEXFUNC_H
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct stroka
{
    unsigned int len;
    char* string;
};

unsigned long long int CountOfSymbols(const char* name);
void FillIndex(char* buf, struct stroka* index, long long int count);
void MySort(struct stroka* index, int len);
void FillOutput(struct stroka* index, FILE* output, int  len);
int BackCompare(const void* a, const void* b);
unsigned int FillBuf(const unsigned long long int cnt, FILE* text, char* buf);
int IndexCompare(const void* a, const void* b);

#endif
