#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "include/solver.h"
#include "include/io.h"
#include "tests/test_mode.h"
#include "include/NRoots.h"
#include "include/solve_equation.h"

#define TEST_MODE

int main(void)
{
    #ifdef TEST_MODE

    test_equation();

    #else

    solve_equation();
    
    #endif

    return 0;
}
