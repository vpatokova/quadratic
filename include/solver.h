/*!
    \file
    \brief Header file with the description of solver function
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "NRoots.h"

/*!
    \brief Solves quadratic equation
    \param[in] a       Coefficient a
    \param[in] b       Coefficient b
    \param[in] c       Coefficient c
    \param[in] x1_ptr  Pointer at first root x1
    \param[in] x2_ptr  Pointer at second root x2
    \return Number of roots
*/

NRoots solver(double a, double b, double c, double *x1_ptr, double *x2_ptr);

#endif // !SOLVER_H
