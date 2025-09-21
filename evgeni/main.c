#include "stringi.h"

int main()
{
    struct stat fileinf;
    FILE* text = fopen("onegin.txt", "r");
    FILE* output = fopen("output.txt", "w");
    stat("text.txt", &fileinf);
    const unsigned long long int cnt = fileinf.st_size;
    long long int count = 0;
    char* buf = (char*)calloc(cnt, sizeof(char));
    char* bufcopy = buf;
    int unsigned n = 0;  //количество строк
    char c;
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
    count =cnt - n;
    const int len = n;
    struct stroka index[len] = {};
    FillIndex(bufcopy, index, count);
    MySort(index, len);
    FillMyBuf(index, output, len);
    fputs("\n\n\n\n\n\n\n\n\n", output);
    qsort(index, len, sizeof(struct stroka), BackCompare);
    FillMyBuf(index, output, len);

    fclose(text);
    fclose(output);
    free(bufcopy);
    return 0;
}
