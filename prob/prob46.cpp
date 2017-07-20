#include "utils.hpp"

#include <cmath>
#include <iostream>

bool is_square(int n) {
  if (n % 2) return false;
  n /= 2;
  const int fac = sqrt(n);
  return (fac * fac == n);
}

namespace prob46 {
int Start() {
  int i = 3;
  while (true) {
    if (not utils::is_prime_miller(i)) {
      bool valid = false;
      for (int prime = i - 2; prime >= 3; prime -= 2) {
        if (utils::is_prime_miller(prime) and is_square(i - prime)) {
          valid = true;
          break;
        }
      }
      if (not valid) {
        std::cout << i << std::endl;
        return 0;
      }
    }
    i += 2;
  }
  return 0;
}
}
