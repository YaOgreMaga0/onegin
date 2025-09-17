#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

void InputMatrix(int* mat, const int n, const int m);
void PrintMatrix(int* mat, const int n, const int m);
int MaxMatrix(int* mat, const int n, const int m);
int MinMatrix(int* mat, const int n, const int m);

void InputTriangleMatrix(int* mat, const int n, const int m);
void PrintTriangleMatrix(int* mat, const int n, const int m);
void MaxTriangleMatrix(int* mat, const int n, const int m);
void MinTriangleMatrix(int* mat, const int n, const int m);

int main()
{
    const int n = 3, m = 3;
    int mat[n][m] = {};
    InputMatrix(mat[n], n, m);  //1 2 3 4 5 6 7 8 9
    PrintMatrix(mat[n], n, m); //1 2 3 4 5 6 7 8 9
    printf("%d %d", MaxMatrix(mat[n], n, m), MinMatrix(mat[n], n, m)); //9 1
    return 0;
}

void InputMatrix(int* mat, const int n, const int m)
{
    assert(mat != NULL);
    int symbol = 0;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &symbol);
            *(int*)((size_t)mat + (j * m + i) * sizeof(int)) = symbol;
        }
    }
}



void PrintMatrix(int* mat, const int n, const int m)
{
    assert(mat != NULL);
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", *(int*)((size_t)mat + (j * m + i) * sizeof(int)));
        }
        printf("\n");
    }
}


int MaxMatrix(int* mat, const int n, const int m)
{
    assert(mat != NULL);
    int maxon = INT_MIN;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            maxon = (((*(int*)((size_t)mat + (j * m + i) * sizeof(int))) < maxon) ? maxon : (*(int*)((size_t)mat + (j * m + i) * sizeof(int))));
        }
    }
    return maxon;
}

//(((*(int*)((size_t)mat + (j * m + i) * sizeof(int))) < maxon) ? maxon : (*(int*)((size_t)mat + (j * m + i) * sizeof(int))))


int MinMatrix(int* mat, const int n, const int m)
{
    assert(mat != NULL);
    int minon = INT_MAX;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            minon = (((*(int*)((size_t)mat + (j * m + i) * sizeof(int))) > minon) ? minon : (*(int*)((size_t)mat + (j * m + i) * sizeof(int))));
        }
    }
    return minon;
}




