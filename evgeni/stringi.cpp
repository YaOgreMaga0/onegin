#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h> //chto bi posmotret kak rabotaet nepovtorimi original
#include <stdlib.h>
#include "stringi.h"



/*
int main()
{
    char a [11] = "abcdefghij";
    char inta[9] = "01234567";
    char dobavochka1[4] = "klm";  //Leonid Modestovich))))
    char dobavochka2[7] = "klmnop";
    MyPuts(a);   //abcdefghij
    printf("\n%d\n",MyStrchr(a, 'd')); //4
    printf("%d\n",MyStrlen(a)); //10
    printf("%d\n",MyAtoi(inta)); //1234567
    printf("%s\n", MyStrcat(a,dobavochka1)); //abcdefghijklm
    printf("%s\n", MyStrNcat(a,dobavochka2, 4)); //abcdefghijklmn
    char priem[27] ="";
    FILE* test = fopen("test.txt","r");
    MyPuts(MyFgets(priem, 27, test));
    MyPuts(MyStrDup(a));
    return 0;
}
*/
void MyPuts(char* str)
{
    assert(str != NULL);
    while(*str != '\0')
    {
        putchar(*str);
        str+=sizeof(char);
    }
}

int MyStrchr(char *str, const char tofind)
{
    assert(str != NULL);
    char* mem = str;
    while(*str != tofind)
        str++;
    return int(str - mem + 1);
}

int MyStrlen(char* str)
{
    assert(str != NULL);
    long long int len = 0;
    while(*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

int MyAtoi(char* str)
{
    assert(str != NULL);
    int integer = 0;
    while(*str != '\0')
    {
        if(*str>57 || *str<48)
        {
            printf("input is not a number\n");
            return 0;
        }
        integer+=(*str-48);
        integer*=10;
        str++;
    }
    integer/=10;
    return integer;
}


char* MyStrcat(char* direction, char* add)
{
    assert(direction != NULL);
    assert(add != NULL);
    char* begin = (char*)calloc((int)(MyStrlen(direction) + MyStrlen(add))+1, 1);
    for(int i = 0; i < (int)(MyStrlen(direction) + MyStrlen(add)); i++)
    {
        if( i < (int)(MyStrlen(direction)))
            *(begin + i) = *((char*)(direction + i));
        else
            *(begin + i) = *((char*)(add + i - MyStrlen(direction)));
    }
    *(direction + MyStrlen(direction) + MyStrlen(add)+1) = '\0';
    return begin;
}
char* MyStrNcat(char* direction, char* add, const int count)
{
    assert(direction != NULL);
    assert(add != NULL);
    char* begin = (char*)calloc((int)(MyStrlen(direction) + MyStrlen(add))+1, 1);
    for(int i = 0; i < (int)(MyStrlen(direction) + count); i++) // pomenyal razmer add na count
    {
        if( i < (int)(MyStrlen(direction)))
            *(begin + i) = *((char*)(direction + i));
        else
            *(begin + i) = *((char*)(add + i - MyStrlen(direction)));
    }
    *(direction + MyStrlen(direction) + MyStrlen(add)+1) = '\0';
    return begin;
}




char* MyFgets(char* str, int count, FILE* stream)  //ya dvoe sutok pitalsa napisat , chisto sherez ukazatel FILE* i elementi ego structuri, prezhde chem sosed scazal mne chto mozhno uzat fgetc. iz principa na vihodnih poprobu napisat napramyy cherez FILE*, no ne seichas
{
    assert(str != NULL);
    assert(stream != NULL);
    char* begin = str;
    char c = fgetc(stream);
    int i = 0;
    while(count > 0 && c != EOF)
    {
        *(char*)((int)begin + i*sizeof(char)) = c;
        c = fgetc(stream);
        i++;
    }
    return str;
}


char* MyStrDup(char* str)
{
    assert(str != NULL);
    long long int len = 0;
    while(*(str+len*sizeof(char)) != '\0')
        len++;
    char* begin = (char*)calloc(len+1, 1);
    for(int i = 0; i < len; i++)
        *(char *)((int)begin + i * sizeof(char)) = *(char *)((int)str + i * sizeof(char));
    return begin;
}



void FillIndex(char* buf, struct stroka* index, long long int count)
{
    int otrezok = 1, n = 0;
    for(int i = 0; i < count; i++)
    {
        if(*buf == '\0')
        {
            ((stroka*)((size_t)index + n*sizeof(stroka))) -> string = (char*)((size_t)buf - (otrezok-1) * sizeof(char));
            ((stroka*)((size_t)index + n*sizeof(stroka)))-> len = otrezok;
            n++;
            otrezok = 0;
        }
        otrezok++;
        buf+=sizeof(char);
    }
}


void MySort(struct stroka* index, int len)
{
    assert(index != NULL);
    assert(len > 0);
    for(int i = 1; i < len;i++)
    {
        for(int j = 0; j < len-i;j++)
        {
            char* str1 = ((stroka*)((size_t)index + j*sizeof(stroka)))->string;
            char* str2 = ((stroka*)((size_t)index + (j+1)*sizeof(stroka)))->string;
            int len1 = ((stroka*)((size_t)index + j*sizeof(stroka)))->len;
            int len2 = ((stroka*)((size_t)index + (j+1)*sizeof(stroka)))->len;
            for(int k = 0; k < (len1>len2 ? len2 : len1); k++)
            {
                if((int)(*((char*)((size_t)str1 + k*sizeof(char)))) > (int)(*((char*)((size_t)str2 + k*sizeof(char)))))
                {
                    struct stroka swap = *((stroka*)((size_t)index + j*sizeof(stroka)));
                    *((stroka*)((size_t)index + j*sizeof(stroka))) = *((stroka*)((size_t)index + (j+1)*sizeof(stroka)));
                    *((stroka*)((size_t)index + (j+1)*sizeof(stroka))) = swap;
                    break;
                }
                if((int)(*((char*)((size_t)str1 + k*sizeof(char)))) < (int)(*((char*)((size_t)str2 + k*sizeof(char)))))
                    break;
            }
        }
    }
}


void FillMyBuf(struct stroka* index, FILE* output, int  len)
{
    for(int i = 0; i < len; i++)
    {
        const char* string = ((stroka*)((size_t)index + i*sizeof(stroka)))->string;
        fputs(string, output);
        fputs("\n",output);
    }
}

int BackCompare(const void* a, const void * b)
{
    struct stroka first = *(stroka*)(a);
    struct stroka second = *(stroka*)(b);
    int len1 = first.len;
    int len2 = second.len;
    char* str1 = first.string;
    char* str2 = second.string;
    for(int i = 0; i < (len1 > len2 ? len2 : len1); i++)
    {
        int char1 = (int)(*(char*)((size_t)str1 + (len1 - i - 2)*sizeof(char)));
        int char2 = (int)(*(char*)((size_t)str2 + (len2 - i - 2)*sizeof(char)));
        if((char1 < char2)&&((char1>64 && char1 < 91)||(char1>96 && char1 < 123))&&((char2>64 && char2 < 91)||(char2>96 && char2 < 123)))
            return -1;
    }
    return 1;
}

