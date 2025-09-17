#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h> //chto bi posmotret kak rabotaet nepovtorimi original
#include <stdlib.h>

void MyPuts(char* a);
int MyStrchr(char *str, const char tofind);
int MyStrlen(char* str);
char* MyStrcat(char* direction, char* add);
char* MyStrNcat(char* direction, char* add, const int count);
int MyAtoi(char* str);



int main()
{
    char a [11] = "abcdefghij";
    char inta[9] = "01234567";
    char dobavochka1[4] = "klm";  //Leonid Modestovich))))
    char dobavochka2[7] = "klmnop";
    MyPuts(a);   //abcdefghij
    printf("\n%d\n",MyStrchr(a, 'd')); //4
    printf("%d\n",MyStrlen(a)); //10
    printf("%d\n",MyAtoi(inta)); //1234567
    printf("%s\n", MyStrcat(a,dobavochka1)); //abcdefghijklm
    printf("%s\n", MyStrNcat(a,dobavochka2, 4)); //abcdefghijklmn
    return 0;
}

void MyPuts(char* str)
{
    assert(str != NULL);
    while(*str != '\0')
    {
        putchar(*str);
        str+=sizeof(char);
    }
}

int MyStrchr(char *str, const char tofind)
{
    assert(str != NULL);
    char* mem = str;
    while(*str != tofind)
        str++;
    return int(str - mem + 1);
}

int MyStrlen(char* str)
{
    assert(str != NULL);
    int len = 0;
    while(*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

int MyAtoi(char* str)
{
    assert(str != NULL);
    int integer = 0;
    while(*str != '\0')
    {
        if(*str>57 || *str<48)
        {
            printf("input is not a number\n");
            return 0;
        }
        integer+=(*str-48);
        integer*=10;
        str++;
    }
    integer/=10;
    return integer;
}


char* MyStrcat(char* direction, char* add)
{
    assert(direction != NULL);
    assert(add != NULL);
    char* begin = (char*)calloc((int)(MyStrlen(direction) + MyStrlen(add))+1, 1);
    for(int i = 0; i < (int)(MyStrlen(direction) + MyStrlen(add)); i++)
    {
        if( i < (int)(MyStrlen(direction)))
            *(begin + i) = *((char*)(direction + i));
        else
            *(begin + i) = *((char*)(add + i - MyStrlen(direction)));
    }
    *(direction + MyStrlen(direction) + MyStrlen(add)+1) = '\0';
    return begin;
}
char* MyStrNcat(char* direction, char* add, const int count)
{
    assert(direction != NULL);
    assert(add != NULL);
    char* begin = (char*)calloc((int)(MyStrlen(direction) + MyStrlen(add))+1, 1);
    for(int i = 0; i < (int)(MyStrlen(direction) + count); i++) // pomenyal razmer add na count
    {
        if( i < (int)(MyStrlen(direction)))
            *(begin + i) = *((char*)(direction + i));
        else
            *(begin + i) = *((char*)(add + i - MyStrlen(direction)));
    }
    *(direction + MyStrlen(direction) + MyStrlen(add)+1) = '\0';
    return begin;
}
