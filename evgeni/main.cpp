#include "FileFunc.h"
#include "StringFunc.h"
#include "IndexFunc.h"


int main()
{
    const char* source = "onegin.txt"; //file names
    const char* result1 = "output1.txt";
    const char* result2 = "output2.txt";

    struct BufAndIndexInf Inf = FileReadAndMakeBuf(source); //Fill buffer and index array and return information about text

    MySort(Inf.index, Inf.CntLines); //First "straigth" sort
    fprintf(stderr, "check1\n");
    FillOutput(Inf.index, result1, Inf.CntLines); //Fill text in output1
    fprintf(stderr, "check2\n");

    BubleQsort(Inf.index, Inf.CntLines, sizeof(struct Line), BackCompare); //qsort
    fprintf(stderr, "check3\n");
    FillOutput(Inf.index, result2, Inf.CntLines); //Fill text in output2
    fprintf(stderr, "check4\n");

    free(Inf.buf);
    free(Inf.index);
    return 0;
}
