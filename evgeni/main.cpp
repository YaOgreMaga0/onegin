#include "IndexFunc.h"


int main()
{
    const char* source = "onegin.txt";
    const char* result1 = "output1.txt";
    const char* result2 = "output2.txt";
    struct stat fileinf;
    stat(source, &fileinf);
    unsigned long long int symbolscnt = CountOfSymbols(source);
    char* buf = (char*)calloc(symbolscnt, sizeof(buf));
    if( buf == NULL)
    {
        printf("memory allocation error\n");
        return 1;
    }
    FILE* text = fopen(source, "r");
    FILE* output1 = fopen(result1, "w");
    FILE* output2 = fopen(result2, "w");

    if(text == NULL || output1 == NULL || output2 == NULL)
    {
        printf("Error file open\n");
        return 1;
    }

    int unsigned lencount = FillBuf(symbolscnt, text, buf);

    stroka* index = (stroka*)calloc(lencount, sizeof(stroka));
    if(index == NULL)
    {
        printf("memory allocation error\n");
        return 1;
    }
    FillIndex(buf, index, symbolscnt - lencount);   //вычитаю lencount так как fopen удаляет /r

    printf("proverka1\n");
    MySort(index, lencount);
    printf("proverka2\n");
    FillOutput(index, output1, lencount);
    printf("proverka3\n");

    qsort(index, lencount, sizeof(struct stroka), BackCompare);
    printf("proverka4\n");
    FillOutput(index, output2, lencount);

    fclose(text);
    fclose(output1);
    fclose(output2);
    free(buf);
    return 0;
}
