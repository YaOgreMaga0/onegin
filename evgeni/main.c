#include "stringi.h"

int main()
{
    struct stat fileinf;
    FILE* text = fopen("text.txt", "r");
    FILE* output = fopen("output.txt", "w");
    fclose(output);
    stat("text.txt", &fileinf);
    const unsigned int count = fileinf.st_size;
    char* buf = (char*)calloc(count, sizeof(char));
    char* bufcopy = buf;
    int unsigned n = 1;  //количество строк
    char c = fgetc(text);
    for(int i = 0; i < count; i++)
    {
        if(c == '\n')
        {
            c = '\0';
            n++;
        }
        *buf = c;
        c = fgetc(text);
        buf++;
    }
    *buf = '\0';
    const int len = n;
    struct stroka index[len] = {};
    FillIndex(bufcopy, index, len, count);
    MySort(index, count);
    FillMyBuf(index, output, count);
    //BackSort(index, count);
    //FillMyBuf(index, output, count);
    fclose(output);
    return 0;
}
