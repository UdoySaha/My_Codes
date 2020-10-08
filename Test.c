#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char c;
    int a;
    int d;
    char d1;
    float d2;
  /*  char d3;
    char d4;*/
}testtype;

int main()
{
    testtype h;
    printf("%lu", sizeof(h));
    return 0;
}

