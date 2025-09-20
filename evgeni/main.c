#include "stringi.h"

int main()
{
    struct stat fileinf;
    FILE* text = fopen("text.txt", "r");
    FILE* output = fopen("output.txt", "w");
    stat("text.txt", &fileinf);
    const unsigned int count = fileinf.st_size - 4;
    char* buf = (char*)calloc(count, sizeof(char));
    char* bufcopy = buf;
    int unsigned n = 0;  //количество строк
    char c;
    for(int i = 0; i < count; i++)
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
    const int len = n;
    struct stroka index[len] = {};
    FillIndex(bufcopy, index, count);
    MySort(index, len);
    FillMyBuf(index, output, len);
    //BackSort(index, count);
    //FillMyBuf(index, output, count);
    fclose(text);
    fclose(output);
    free(bufcopy);
    return 0;
}
