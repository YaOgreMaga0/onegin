#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

void InputMatrix(int* mat, const int n, const int m);
void PrintMatrix(int* mat, const int n, const int m);
int MaxMatrix(int* mat, const int n, const int m);
int MinMatrix(int* mat, const int n, const int m);

void InputTriangleMatrix(int* mat, const int n);
void PrintTriangleMatrix(int* mat, const int n);
int MaxTriangleMatrix(int* mat, const int n);
int MinTriangleMatrix(int* mat, const int n);


void InputRhombusMatrix(int* mat, const int n);
void PrintRhombusMatrix(int* mat, const int n);
int MaxRhombusMatrix(int* mat, const int n);
int MinRhombusMatrix(int* mat, const int n);

int main()
{
    const int n = 4;
    int mat[n][n] = {};
/*
    InputMatrix(mat[n], n, n);  //1 2 3 4 5 6 7 8 9
    PrintMatrix(mat[n], n, n); //1 2 3 4 5 6 7 8 9
    printf("%d %d\n", MaxMatrix(mat[n], n, n), MinMatrix(mat[n], n, n)); //9 1
    InputTriangleMatrix(mat[n], n);  //1 4 5 7 8 9
    PrintTriangleMatrix(mat[n], n); //1 0 0 4 5 0 7 8 9
    printf("%d %d\n", MaxTriangleMatrix(mat[n], n), MinTriangleMatrix(mat[n], n)); //9 1
    InputRhombusMatrix(mat[n], n);  //2 4 5 6 8
    PrintRhombusMatrix(mat[n], n); //0 2 0 4 5 6 0 8 0
    printf("%d %d\n", MaxRhombusMatrix(mat[n], n), MinRhombusMatrix(mat[n], n)); //8 2
*/
    return 0;
}


//default matrix

void InputMatrix(int* mat, const int n, const int m)
{
    assert(mat != NULL);
    int symbol = 0;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &symbol);
            *(int*)((size_t)mat + (j  + i * n) * sizeof(int)) = symbol;
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
            printf("%d ", *(int*)((size_t)mat + (j  + i * n) * sizeof(int)));
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
            maxon = (((*(int*)((size_t)mat + (j  + i * n) * sizeof(int))) < maxon) ? maxon : (*(int*)((size_t)mat + (j  + i * n) * sizeof(int))));
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
            minon = (((*(int*)((size_t)mat + (j  + i * n) * sizeof(int))) > minon) ? minon : (*(int*)((size_t)mat + (j  + i * n) * sizeof(int))));
        }
    }
    return minon;
}



//triangle matrix
void InputTriangleMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    int symbol = 0;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j < i + 1)
            {
                scanf("%d", &symbol);
                *(int*)((size_t)mat + (j  + i * n) * sizeof(int)) = symbol;
            }
            else
                *(int*)((size_t)mat + (j  + i * n) * sizeof(int)) = 0;
        }
    }
}



void PrintTriangleMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", *(int*)((size_t)mat + (j  + i * n) * sizeof(int)));
        }
        printf("\n");
    }
}


int MaxTriangleMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    int maxon = INT_MIN;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            maxon = (((*(int*)((size_t)mat + (j  + i * n) * sizeof(int))) < maxon) ? maxon : (*(int*)((size_t)mat + (j  + i * n) * sizeof(int))));
        }
    }
    return maxon;
}



int MinTriangleMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    int minon = INT_MAX;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            minon = (((*(int*)((size_t)mat + (j  + i * n) * sizeof(int))) > minon) ? minon : (*(int*)((size_t)mat + (j  + i * n) * sizeof(int))));
        }
    }
    return minon;
}



//rhombus matrix
void InputRhombusMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    int symbol = 0;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(((j >= n/2 - i - 1) && (j <= n/2 + i) && (i <= n/2)) || ((j >= i/2) && (j <= n - i/2 - 1) && (i >= n/2)))
            {
                scanf("%d", &symbol);
                *(int*)((size_t)mat + (j  + i * n) * sizeof(int)) = symbol;
            }
            else
                *(int*)((size_t)mat + (j  + i * n) * sizeof(int)) = 0;
        }
    }
}



void PrintRhombusMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", *(int*)((size_t)mat + (j  + i * n) * sizeof(int)));
        }
        printf("\n");
    }
}


int MaxRhombusMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    int maxon = INT_MIN;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            maxon = (((*(int*)((size_t)mat + (j  + i * n) * sizeof(int))) < maxon) ? maxon : (*(int*)((size_t)mat + (j  + i * n) * sizeof(int))));
        }
    }
    return maxon;
}



int MinRhombusMatrix(int* mat, const int n)
{
    assert(mat != NULL);
    int minon = INT_MAX;
    for(int i = 0 ;i < n; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            minon = (((*(int*)((size_t)mat + (j  + i * n) * sizeof(int))) > minon) ? minon : (*(int*)((size_t)mat + (j  + i * n) * sizeof(int))));
        }
    }
    return minon;
}
