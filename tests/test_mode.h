/*!
    \file
    \brief Header file with the description of test_mode functions
*/

#ifndef CHECK_ROOTS_H
#define CHECK_ROOTS_H

#include "../include/NRoots.h"

/*!
    \brief Reads values from the file
    \param[in] a_ptr               Pointer at coefficient a
    \param[in] b_ptr               Pointer at coefficient b
    \param[in] c_ptr               Pointer at coefficient c
    \param[in] expected_nRoots_ptr Pointer at expected number of roots
    \param[in] expected_x1_ptr     Pointer at expected first root x1
    \param[in] expected_x2_ptr     Pointer at expected second root x2
*/
 
void test_input(double *a_ptr, double *b_ptr, double *c_ptr,
                int *expected_nRoots_ptr, double *expected_x1_ptr, double *expected_x2_ptr);

/*!
    \brief Checks if results match with expected results
    \param[in] test_number      Number of test
    \param[in] number_roots     Number of roots
    \param[in] x1               First root x1
    \param[in] x2               Second root x2
    \param[in] expected_nRoots  Expected number of numbers
    \param[in] expected_x1      Expected first root x1
    \param[in] expected_x2      Expected second root x2
    \return Number of failed tests
*/

int check_roots(int test_number, int number_roots, double x1, double x2,
                int expected_nRoots, double expected_x1, double expected_x2);

/*!
    \brief Tests the program with values from a file
*/
void test_equation();

#endif // !CHECK_ROOTS_H
