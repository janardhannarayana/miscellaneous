#include <stdio.h>

int main()
{
/*
 * Compile with gcc -DPRINTX=0 macro_dynamic.c or
 * gcc -DPRINTX=1 macro_dynamic.c
 */
    int x = 10;
    int y = 11;
    #if PRINTX
    printf("X = %d\n",x);
    #else
    printf("Y = %d\n",y);
    #endif
}
