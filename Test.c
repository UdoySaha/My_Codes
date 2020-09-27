#include <stdio.h>

int main()
{
    int *i, in=2; i=&in;
    float *f, fl=2.5; f=&fl;
    char *c, ch='a'; c=&ch;
    double *d, dou=10.8; d=&dou;
    void *v;

    printf("Char : %lu\tChar var : %lu\n", sizeof(c), sizeof(ch) );
    printf("Int : %lu \tInt var : %lu\n", sizeof(i), sizeof(in) );
    printf("Float : %lu\tFloat var : %lu\n", sizeof(f), sizeof(fl) );
    printf("Double : %lu\tDouble var : %lu\n", sizeof(d), sizeof(dou) );
    printf("Void : %lu\t", sizeof(v));
    return 0;
}
