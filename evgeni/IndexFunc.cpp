#include "IndexFunc.h"
#include "StringFunc.h"

unsigned long long int CountOfSymbols(const char* name)
{
    assert(name != NULL);

    struct stat fileinf = {};
    stat(name, &fileinf);
    unsigned long long int cnt = fileinf.st_size;
    if(cnt == 0)
    {
        printf("file is empty\n");
        return -1;
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


void FillOutput(struct stroka* index, FILE* output, int  len)
{
    assert(index != NULL);
    assert(output != NULL);
    assert(len > 0);

    for(int i = 0; i < len; i++)
    {
        const char* string = index[i].string;
        fputs(string, output);
        fputs("\n", output);
    }
}


unsigned int FillBuf(unsigned long long int cnt, FILE* text, char* buf)
{
    assert(cnt > 0);
    assert(text != NULL);
    assert(buf != NULL);

    char c = '\0';
    unsigned int CountOfLines = 0;
    for(long long int i = 0; i < cnt; i++)
    {
        c = fgetc(text);
        if(c == '\n')
        {
            c = '\0';
            CountOfLines++;
        }
        *buf = c;
        buf++;
    }

    return CountOfLines;
}
