#include <stdio.h>

int main()
{
    int x=2;

    char *ptr;
    ptr=(char *)(&x);

    for(int i=-4; i<9; i++)
    {
        if(i==0)
        {
            printf("%p\t %d\t<----\n", ptr+i, *(ptr+i));
            continue;
        }
        printf("%p\t%2d\n", ptr+i, *(ptr+i));
    }

    return 0;
}
