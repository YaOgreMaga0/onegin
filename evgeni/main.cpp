#include "StringFunc.h"
#include "IndexFunc.h"


int main()
{
    const char* source = "onegin.txt"; //объявляю название файлов
    const char* result1 = "output1.txt";
    const char* result2 = "output2.txt";
    struct stat fileinf = {}; //подтягиваю из файла его размер
    unsigned long long int symbolscnt = CountOfSymbols(source);
    if(symbolscnt == -1)
        return 0;
    char* buf = (char*)calloc(symbolscnt, sizeof(buf)); //создаю буффер
    if( buf == NULL)
    {
        printf("memory allocation error\n");
        return 1;
    }

    FILE* text = fopen(source, "r"); //открываю файлы для чтения и записи
    FILE* output1 = fopen(result1, "w");
    FILE* output2 = fopen(result2, "w");
    if(text == NULL || output1 == NULL || output2 == NULL)
    {
        printf("Error file open\n");
        return 1;
    }

    int unsigned lencount = FillBuf(symbolscnt, text, buf); //заполняю буффер и возвращаю количество строк
    stroka* index = (stroka*)calloc(lencount, sizeof(stroka)); //создаю массив структур(индекс + длина)
    if(index == NULL)
    {
        printf("memory allocation error\n");
        return 1;
    }
    FillIndex(buf, index, symbolscnt - lencount);   //Заполняю массив индексов. вычитаю lencount так как fopen удаляет /r

    MySort(index, lencount); //Первая сортировка
    fprintf(stderr, "proverka1\n");
    FillOutput(index, output1, lencount); //Заполняю текст в output1
    fprintf(stderr, "proverka2\n");

    qsort(index, lencount, sizeof(struct stroka), BackCompare); //сортировка с помощью qsort
    fprintf(stderr, "proverka3\n");
    FillOutput(index, output2, lencount); //заполняю текст в output2
    fprintf(stderr, "proverka4\n");

    fclose(text); //закрываю файлы, освобождаю calloc
    fclose(output1);
    fclose(output2);
    free(buf);
    free(index);
    return 0;
}
