#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/io.h"
#include "../include/utils.h"
#include "../include/solver.h"
#include "../include/NRoots.h"
#include "test_mode.h"

void test_input(FILE *file, double *a_ptr, double *b_ptr, double *c_ptr,
                int *expected_nRoots_ptr, double *expected_x1_ptr, double *expected_x2_ptr)
{
    fscanf(file, "%lg %lg %lg", a_ptr, b_ptr, c_ptr);

    fscanf(file, "%d", expected_nRoots_ptr);

    if      (*expected_nRoots_ptr == 2)
        fscanf(file, "%lg %lg", expected_x1_ptr, expected_x2_ptr);
    else if (*expected_nRoots_ptr == 1)
        fscanf(file, "%lg", expected_x1_ptr);
    /*else (if *expected_nRoots_ptr == 0 || *expected_nRoots_ptr == 3 )
        continue;*/
}

int check_roots(int test_number, int number_roots, double x1, double x2,
                int expected_nRoots, double expected_x1, double expected_x2)
{
    if ((number_roots != expected_nRoots)
        || (!is_equal(x1, expected_x1))
        || (!is_equal(x2, expected_x2)))
    {
        printf("Test %d   FAILED:   Number of roots = %d, x1 = %lg, x2 = %lg\n"
               "         EXPECTED: Number of roots = %d, x1 = %lg, x2 = %lg\n",
               test_number, number_roots, x1, x2, expected_nRoots, expected_x1, expected_x2);

        return 1;
    }

    printf("Test %d   Success\n", test_number);

    return 0;
}

void test_equation()
{
    double a = 0;
    double b = 0;
    double c = 0;

    int number_roots = 0;
    int expected_nRoots = 0;

    int test_number  = 1;
    int failed_tests = 0;

    const char *input_file_path = "tests/test.txt";
    assert(input_file_path != nullptr);
    FILE *file = fopen(input_file_path, "r");
    assert(file != nullptr);

    while(!feof(file))
    {
        double expected_x1  = 0;
        double expected_x2  = 0;

        test_input(file, &a, &b, &c, &expected_nRoots, &expected_x1, &expected_x2);

        double x1 = 0;
        double x2 = 0;

        number_roots = solver(a, b, c, &x1, &x2);

        failed_tests += check_roots(test_number, number_roots, x1, x2, expected_nRoots, expected_x1, expected_x2);

        printf("\n");

        test_number++;
    }

    printf("Failed tests = %d\n", failed_tests);

    fclose(file);
}
