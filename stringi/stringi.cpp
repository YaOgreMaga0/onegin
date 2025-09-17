#include <stdio.h>
#include <assert.h>
#include <math.h>

void MyPuts(char* a);
int MyStrchr(char *str, const char tofind);
int MyStrlen(char* str);
long long int MyAtoi(char* str);


int main()
{
    char a [11] = "abcdefghij" ;
    char inta[11] = "1234567890";
    MyPuts(a);   //abcdefghij
    printf("\n%d\n",MyStrchr(a, 'd')); //4
    printf("%d\n",MyStrlen(a)); //10
    printf("%d\n",MyAtoi(inta)); //01234567890
    return 0;
}

void MyPuts(char* str)
{
    assert(str != NULL);
    while(*str != '\0')
    {
        putchar(*str);
        str++;
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

long long int MyAtoi(char* str)
{
    assert(str != NULL);
    long long int integer = 0;
    while(*str != '\0')
    {
        if(*str>57 || *str<48)
        {
            printf("input is not a number\n");
            return NAN;
        }
        integer+=(*str-48);
        integer*=10;
        str++;
    }
    integer/=10;
    return integer;
}