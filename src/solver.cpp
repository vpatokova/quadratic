#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>
#include "../include/solver.h"
#include "../include/utils.h"
#include "../include/NRoots.h"

int is_zero(double a)
{
    assert(std::isfinite(a));
    
    return is_equal(a, 0);
}
NRoots solve_linear(double b, double c, double *x1_ptr)
{
    assert(x1_ptr != NULL);
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    if (is_zero(c))
        *x1_ptr = 0;
    else
        *x1_ptr = -c / b;

    return ONE_ROOT;
}

NRoots solve_quadratic(double a, double b, double c, double *x1_ptr, double *x2_ptr)
{
    assert(x1_ptr != NULL);
    assert(x2_ptr != NULL);
    assert(x1_ptr != x2_ptr);
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    double discriminant = b*b - 4*a*c;

    if (!is_zero(discriminant))
    {
        if (discriminant < 0)
            return ZERO_ROOTS;

        double square_root = sqrt(discriminant);
        double double_a = 2 * a;

        *x1_ptr = (-b - square_root) / double_a;
        *x2_ptr = (-b + square_root) / double_a;

        return TWO_ROOTS;
    }

    *x1_ptr = -b / (2*a);

    return ONE_ROOT;
}

NRoots solver(double a, double b, double c, double *x1_ptr, double *x2_ptr)
{
    assert(x1_ptr != NULL);
    assert(x2_ptr != NULL);
    assert(x1_ptr != x2_ptr);
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    if (is_zero(a) && is_zero(b) && is_zero(c))
        return INFINITE_ROOTS;
    if (is_zero(a) && is_zero(b))
        return ZERO_ROOTS;
    if (is_zero(a))
        return solve_linear(b, c, x1_ptr);

    return solve_quadratic(a, b, c, x1_ptr, x2_ptr);
}
