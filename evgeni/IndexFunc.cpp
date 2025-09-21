#include "IndexFunc.h"


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

unsigned int CountOfLines(const unsigned long long int cnt, FILE* text, char* buf)
{
    assert(buf != NULL);
    char c = '0';
    unsigned int n = 0;
    for(long long int i = 0; i < cnt; i++)
    {
        c = fgetc(text);
        if(c == '\n')
        {
            c = '\0';
            n++;
        }
        *buf = c;
        buf++;
    }
    return n;
}

