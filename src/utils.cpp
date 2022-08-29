#include <math.h>
#include "../include/utils.h"
#include "../include/NRoots.h"

int is_equal(double x, double y)
{
    const double EPSILON = 0.00001;
    return (fabs(x - y) < EPSILON);
}
