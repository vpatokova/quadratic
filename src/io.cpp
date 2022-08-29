#include <stdio.h>
#include "../include/io.h"
#include "../include/NRoots.h"

int input(double *a_ptr, double *b_ptr, double *c_ptr)
{
    //printf("write coefficient a, b, c:\n");
    char ch = 'a';

    while (scanf("%lg %lg %lg", a_ptr, b_ptr, c_ptr) != 3)
    {
        printf("This is not a number. Write a number\n");
        ch = getchar();
        while (ch != '\n')
        {
            ch = getchar();
            if (ch == EOF)
                return 0;
            continue;
        }
    }
    return 1;
}

void printer(int number_roots, double x1, double x2)
{
    switch (number_roots)
    {
        case INFINITE_ROOTS:
            printf("The equation has infinite roots\n");
            break;

        case ZERO_ROOTS:
            printf("The equation has no roots\n");
            break;

        case ONE_ROOT:
            printf("The root is x = %lg\n", x1);
            break;

        case TWO_ROOTS:
            printf("The roots are x1 = %lg and x2 = %lg\n", x1, x2);
            break;

        default:
            printf("[printer]: Unsupported number of roots.\n");
            break;
    }
}

