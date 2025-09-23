#include "IndexFunc.h"

FILE* FileOpen(char* name)
{
    assert(name != NULL);
    FILE* text = fopen(name, "r");
    if(text == NULL)
    {
        printf("incorrect file name\n");
        abort();
    }
    return text;
}

unsigned long long int CountOfSymbols(char* name)
{
    assert(name != NULL);
    struct stat fileinf;
    stat(name, &fileinf);
    unsigned long long int cnt = fileinf.st_size;
    if(cnt == 0)
    {
        printf("file is empty");
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
            //type *arr
            //arr + 1 <=> (size_t)arr + 1 * sizeof(type)
            //*(arr + 1) <=> arr[1]
            //|0|0|0|0|0|0|0|0|
            //index[n].string = ...
            //index++ и index->stroka = ...
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
            char* str1 = index[j].string;
            char* str2 = index[j+1].string;
            int len1 = index[j].len;
            int len2 = index[j+1].len;
            for(int k = 0; k < (len1 > len2 ? len2 : len1); k++)
            {
                if((int)str1[k] > (int)str2[k])
                {
                    struct stroka swap = index[j];
                    index[j] = index[j + 1];
                    index[j + 1] = swap;
                    break;
                }
                if((int)str1[k] < (int)str2[k])
                    break;
            }
        }
    }
}


void FillMyBuf(struct stroka* index, FILE* output, int  len)
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
    char* str1 = first.string;
    char* str2 = second.string;
    for(int i = 0; i < (len1 > len2 ? len2 : len1); i++)
    {
        int char1 = (int)(str1[len1 - i - 1]);
        int char2 = (int)(str2[len2 - i - 1]);
        if((char1 < char2) && isalpha(char1) && isalpha(char2))
            return -1;
        if((char1 > char2) && isalpha(char1) && isalpha(char2))
            return 1;
    }
    return 1;
}

unsigned int CountOfLines(const unsigned long long int cnt, FILE* text, char* buf)
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

