#include "IndexFunc.h"

int main()
{
    char name[11] = "onegin.txt";
    struct stat fileinf;
    stat(name, &fileinf);
    const unsigned long long int cnt = CountOfSymbols(name);
    char* buf = (char*)calloc(cnt, sizeof(buf));
    FILE* text = FileOpen(name);
    FILE* output = fopen("output.txt", "w");
    int unsigned n = CountOfLines(cnt, text, buf);  //количество строк


    long long int count = cnt - n;
    const int len = n;
    struct stroka index[len] = {};
    FillIndex(buf, index, count);


    MySort(index, len);
    FillMyBuf(index, output, len);
    fputs("\n\n\n\n\n\n\n\n\n", output);


    qsort(index, len, sizeof(struct stroka), BackCompare);
    FillMyBuf(index, output, len);


    fclose(text);
    fclose(output);
    free(buf);
    return 0;
}
