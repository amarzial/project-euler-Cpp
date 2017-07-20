#ifndef __UTILS_H__
#define __UTILS_H__
#include <cmath>

namespace utils {
int factorial(int n);

int digit_count(int n);

bool is_prime(int n);

bool is_prime_miller(int number);

bool is_pandigital(int n, bool include_zero = false);
}

#endif
