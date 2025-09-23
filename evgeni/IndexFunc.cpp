#include "IndexFunc.h"

unsigned long long int CountOfSymbols(const char* name)
{
    assert(name != NULL);
    struct stat fileinf;
    stat(name, &fileinf);
    unsigned long long int cnt = fileinf.st_size;
    if(cnt == 0)
    {
        printf("file is empty\n");
        abort();
    }
    return cnt;
}

void FillIndex(char* buf, struct stroka* index, long long int count)
{
    assert(buf != NULL);
    assert(index != NULL);
    assert(count > 0);

    int otrezok = 1, n = 0;
    for(int i = 0; i < count; i++)
    {
        if(*buf == '\0')
        {
            index[n].string = buf - (otrezok - 1);
            index[n].len = otrezok;
            n++;
            otrezok = 0;
        }
        otrezok++;
        buf += sizeof(char);
    }
}


void MySort(struct stroka* index, int len)
{
    assert(index != NULL);
    assert(len > 0);
    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < len-i; j++)
        {
            if(IndexCompare(index + j, index + j + 1) != -1)
            {
                struct stroka swap = index[j];
                index[j] = index[j + 1];
                index[j + 1] = swap;
            }
        }
    }
}


void FillOutput(struct stroka* index, FILE* output, int  len)
{
    for(int i = 0; i < len; i++)
    {
        const char* string = index[i].string;
        fputs(string, output);
        fputs("\n", output);
    }
}

int BackCompare(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);
    struct stroka first = *(stroka*)(a);
    struct stroka second = *(stroka*)(b);
    int len1 = first.len;
    int len2 = second.len;
    char* char1 = first.string + len1;
    char* char2 = second.string + len2;
    while(len1 > 0 && len2 > 0)
    {
        char1--;
        char2--;
        while(!isalpha(*char1) && len1 > 0)
        {
            len1--;
            char1--;
        }
        while(!isalpha(*char2) && len2 > 0)
        {
            len2--;
            char2--;
        }
        if(tolower(*char1) < tolower(*char2))
            return -1;
        if(tolower(*char1) > tolower(*char2))
            return 1;
        len1--;
        len2--;
    }
    return 0;
}

unsigned int FillBuf(unsigned long long int cnt, FILE* text, char* buf)
{
    assert(cnt > 0);
    assert(text != NULL);
    assert(buf != NULL);
    char c = '\0';
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


int IndexCompare(const void* a, const void* b)
{
    const stroka* str1 = (const stroka*)a;
    const stroka* str2 = (const stroka*)b;
    char* char1 = str1->string;
    char* char2 = str2->string;
    int len1 = str1->len;
    int len2 = str2->len;
    while(len1 > 0 && len2 > 0)
    {
        while(!isalpha(*char1) && len1 > 0)
        {
            len1--;
            char1++;
        }
        while(!isalpha(*char2) && len2 > 0)
        {
            len2--;
            char2++;
        }
        if(tolower(*char1) > tolower(*char2))
            return 1;
        if(tolower(*char1) < tolower(*char2))
            return -1;
        char1++;
        char2++;
        len1--;
        len2--;
    }
    return 0;
}
