#include "StringFunc.h"
#include "IndexFunc.h"

unsigned long long int CountOfSymbols(const char* name)
{
    assert(name != NULL);

    struct stat fileinf = {};
    stat(name, &fileinf);
    unsigned long long int cnt = fileinf.st_size;
    if(cnt == 0)
        return -1;

    return cnt;
}

void FillIndex(char* buf, struct Line* index, long long int count)
{
    assert(buf != NULL);
    assert(index != NULL);
    assert(count > 0);

    int LineLen = 1, n = 0;
    for(int i = 0; i < count; i++)
    {
        if(*buf == '\0')
        {
            index[n].string = buf - (LineLen - 1);
            index[n].len = LineLen;
            n++;
            LineLen = 0;
        }
        LineLen++;
        buf += sizeof(char);
    }
}


void FillOutput(struct Line* index, const char* filename, int  len)
{
    assert(index != NULL);
    assert(filename != NULL);
    assert(len > 0);

    FILE* outfile = fopen(filename, "w");
    if(outfile == NULL)
        printf("Error file open\n");

    for(int i = 0; i < len; i++)
    {
        const char* string = index[i].string;
        fputs(string, outfile);
        fputs("\n", outfile);
    }
    fclose(outfile);
}


unsigned int FillBuf(unsigned long long int cnt, FILE* text, char* buf)
{
    assert(cnt > 0);
    assert(text != NULL);
    assert(buf != NULL);

    char c = '\0';
    unsigned int CountOfLines = 0;
    size_t freadcnt = fread(buf, cnt, sizeof(char), text);
    for(long long int i = 0; i < cnt; i++)
    {
        if(buf[i] == '\n')
        {
            buf[i] = '\0';
            CountOfLines++;
        }
    }

    return CountOfLines;
}
