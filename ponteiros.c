#include <stdio.h>
#include <stdlib.h>


int main(){

    int a = 10;
    int *p1 = &a;
    int **p2 = &p1;

    printf("a = %d\n", a);
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", **p2);

    **p2 = 99;
    printf("a = %d\n", a);
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", **p2);


    return 0;
}