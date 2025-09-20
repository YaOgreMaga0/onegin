#ifndef STRINGI_H
#define STRINGI_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

struct stroka
{
    unsigned int len;
    char* string;
};


void MyPuts(char* a);
int MyStrchr(char *str, const char tofind);
int MyStrlen(char* str);
char* MyStrcat(char* direction, char* add);
char* MyStrNcat(char* direction, char* add, const int count);
int MyAtoi(char* str);
char* MyFgets(char* str, int count, FILE* stream);
char* MyStrDup(char* str);
void FillIndex(char* buf, struct stroka* index, int count);
void MySort(struct stroka* index, int len);
void FillMyBuf(struct stroka* index, FILE* output, int  len);

#endif
