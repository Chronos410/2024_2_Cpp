#include <stdio.h>

void main()
{
    for (int a = 1; a < 10; a++)
    {
        for (int b = 1; b < 10; b++)
        {
            if (a * b < 10) {
                printf(" ");
            }
            printf(" %d", a*b);
        }
        printf("\n");
    }
}