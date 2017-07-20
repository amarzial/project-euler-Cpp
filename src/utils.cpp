#include "utils.hpp"

#include <array>
#include <cstdint>

namespace utils {
int factorial(int n) { return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n; }

int digitCount(int n) {
  int pow = 10;
  int count = 1;
  while (pow < n) {
    if (count == 9) return 10;
    pow *= 10;
    ++count;
  }

  return count;
}

bool isPrime(int n) {
  int square_root = sqrt(n);  // use math.h
  for (int i = 2; i <= square_root; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  if (n == 1) return false;
  return true;
}

bool isPandigital(int n, bool include_zero) {
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
