#include "fns.h"
#include <stdexcept>

using std::runtime_error;

void compare(int i1, int i2)
{
    if (i1 != i2)
        throw runtime_error("Not equal");
}

int factorial(int i)
{
    if (i == 1)
        return 1;
    return i * factorial(i - 1);
}