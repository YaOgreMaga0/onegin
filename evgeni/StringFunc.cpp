#include "StringFunc.h"

int BackCompare(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);

    struct Line first = *(Line*)(a);
    struct Line second = *(Line*)(b);
    int len1 = first.len;
    int len2 = second.len;
    char* char1 = first.string + len1;
    char* char2 = second.string + len2;

    return StrCmpIgnorPunctuation(char1 - 2, char2 - 2, len1, len2, -1);
}


int IndexCompare(const void* a, const void* b)
{
    assert(a != NULL);
    assert(b != NULL);

    const Line* str1 = (const Line*)a;
    const Line* str2 = (const Line*)b;
    char* char1 = str1->string;
    char* char2 = str2->string;
    int len1 = str1->len;
    int len2 = str2->len;

    return StrCmpIgnorPunctuation(char1, char2, len1, len2, 1);
}


void MySort(struct Line* index, int len)
{
    assert(index != NULL);
    assert(len > 0);

    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < len-i; j++)
        {
            if(IndexCompare(index + j, index + j + 1) == 1)
            {
                struct Line swap = index[j];
                index[j] = index[j + 1];
                index[j + 1] = swap;
            }
        }
    }
}

int StrCmpIgnorPunctuation(char* char1, char* char2, int len1, int len2, int mode)
{
    while(len1 > 0 && len2 > 0)
    {
        while(!isalpha(*char1) && len1 > 0)
        {
            len1--;
            char1 += mode;
        }
        while(!isalpha(*char2) && len2 > 0)
        {
            len2--;
            char2 += mode;
        }
        if(tolower(*char1) > tolower(*char2))
            return 1;
        if(tolower(*char1) < tolower(*char2))
            return -1;
        char1 += mode;
        char2 += mode;
        len1--;
        len2--;
    }
    return 0;
}
