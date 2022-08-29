/*!
    \file
    \brief Header file with the description of input and output functions
*/

#ifndef IO_H
#define IO_H

#include "NRoots.h"

/*!
    \brief Reads coefficients a, b and c
    \param[out] a_ptr Pointer at coefficient a
    \param[out] b_ptr Pointer at coefficient b
    \param[out] c_ptr Pointer at coefficient c
    \return True or false
*/

int input(double *a_ptr, double *b_ptr, double *c_ptr);

/*!
    \brief Prints roots of quadratic equation
    \param[in] number_roots Number of roots
    \param[in] x1           First root
    \param[in] x2           Second root
*/

void printer(int number_roots, double x1, double x2);

#endif // !IO_H
