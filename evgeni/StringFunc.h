#ifndef STRINGFUNC_H
#define STRINGFUNC_H
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



struct Line
{
    unsigned int len;
    char* string;
};


int BackCompare(const void* a, const void* b);
int IndexCompare(const void* a, const void* b);
void MySort(struct Line* index, int len);
int StrCmpIgnorPunctuation(char* str1, char* str2, int len1, int len2, int mode);


#endif //STRINGFUNC_H
