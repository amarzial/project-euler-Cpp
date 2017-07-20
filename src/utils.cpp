#include "utils.hpp"

#include <array>
#include <cstdint>

namespace utils {
int factorial(int n) { return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n; }

int digit_count(int n) {
  int pow = 10;
  int count = 1;
  while (pow < n) {
    if (count == 9) return 10;
    pow *= 10;
    ++count;
  }

  return count;
}

bool is_prime(int n) {
  int square_root = sqrt(n);  // use math.h
  for (int i = 2; i <= square_root; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  if (n <= 1) return false;
  return true;
}

//prime miller
static int64_t power(int a, int n, int mod) {
  int64_t power = a, result = 1;

  while (n) {
    if (n & 1) result = (result * power) % mod;
    power = (power * power) % mod;
    n >>= 1;
  }
  return result;
}

static bool witness(int a, int n) {
  int t, u, i;
  int64_t prev, curr;

  u = n / 2;
  t = 1;
  while (!(u & 1)) {
    u /= 2;
    ++t;
  }

  prev = power(a, u, n);
  for (i = 1; i <= t; ++i) {
    curr = (prev * prev) % n;
    if ((curr == 1) && (prev != 1) && (prev != n - 1)) return true;
    prev = curr;
  }
  if (curr != 1) return true;
  return false;
}

bool is_prime_miller(int number) {
  if (((!(number & 1)) && number != 2) || (number < 2) ||
      (number % 3 == 0 && number != 3))
    return (false);

  if (number < 1373653) {
    for (int k = 1; 36 * k * k - 12 * k < number; ++k)
      if ((number % (6 * k + 1) == 0) || (number % (6 * k - 1) == 0))
        return (false);

    return true;
  }

  if (number < 9080191) {
    if (witness(31, number)) return false;
    if (witness(73, number)) return false;
    return true;
  }

  if (witness(2, number)) return false;
  if (witness(7, number)) return false;
  if (witness(61, number)) return false;
  return true;
}
//\prime miller

bool is_pandigital(int n, bool include_zero) {
  std::array<int, 10> vals;
  vals.fill(0);
  bool stopped = false;
  while (n > 0) {
    vals[n % 10] = 1;
    n /= 10;
  }
  for (int i = (include_zero ? 0 : 1); i < 10; i++) {
    if (vals[i] == 1 and stopped)
      return false;
    else if (vals[i] == 0)
      stopped = true;
  }
  return true;
}
}
