#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/solver.h"
#include "../include/utils.h"
#include "../include/NRoots.h"
#include "../include/io.h"
#include "../include/solve_equation.h"

void solve_equation()
{
    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;

    int number_roots = 0;

    if (input(&a, &b, &c))
    {
        number_roots = solver(a, b, c, &x1, &x2);

        printer(number_roots, x1, x2);
    }
    else
        printf("Input was not correct");
}