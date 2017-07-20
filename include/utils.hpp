#ifndef __UTILS_H__
#define __UTILS_H__
#include <cmath>

namespace utils {
int factorial(int n);

int digitCount(int n);

bool isPrime(int n);

bool isPandigital(int n, bool include_zero = false);
}

#endif
