#ifndef STRINGI_H
#define STRINGI_H


void MyPuts(char* a);
int MyStrchr(char *str, const char tofind);
int MyStrlen(char* str);
char* MyStrcat(char* direction, char* add);
char* MyStrNcat(char* direction, char* add, const int count);
int MyAtoi(char* str);
char* MyFgets(char* str, int count, FILE* stream);
char* MyStrDup(char* str);


#endif
