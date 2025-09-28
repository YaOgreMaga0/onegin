#include "FileFunc.h"
#include "StringFunc.h"
#include "IndexFunc.h"


int main()
{
    const char* source = "onegin.txt"; //file names
    const char* result1 = "output1.txt";
    const char* result2 = "output2.txt";

    BufAndIndexInf Inf = FileReadAndMakeBuf(source); //Fill buffer and index array and return information about text
    if(Inf.buf == NULL || Inf.CntLines == -1 || Inf.index == NULL)
    {
        printf("incorrect input file\n");
        return 1;
    }

    fprintf(stderr, "check1\n");
    MySort(Inf.index, Inf.CntLines); //First "straigth" sort
    fprintf(stderr, "check2\n");
    if(FillOutput(Inf.index, result1, Inf.CntLines) == 1) //Fill text in output1
    {
        printf("incorrect output file\n");
        return 1;
    }
    fprintf(stderr, "check3\n");

    BubleQsort(Inf.index, Inf.CntLines, sizeof(struct Line), BackCompare); //qsort
    fprintf(stderr, "check4\n");
    if(FillOutput(Inf.index, result2, Inf.CntLines) == 1) //Fill text in output2
    {
        printf("incorrect output file\n");
        return 1;
    }
    fprintf(stderr, "check5\n");

    MemoryFree(&Inf);
    return 0;
}
