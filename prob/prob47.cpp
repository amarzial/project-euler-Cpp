#include "utils.hpp"

#include <iostream>
#include <vector>

namespace prob47 {

std::vector<unsigned int> primes{2, 3, 5, 7, 11, 13, 17, 19};

int next_prime(int n) {
  if (n == 2) return 3;
  do {
    n += 2;
  } while (not utils::is_prime_miller(n));
  return (n);
}

bool has_four_prime_factors(unsigned int n) {
  unsigned int prime;
  int factors = 0;
  for (auto p : primes) {
    prime = p;
    if (n % prime == 0) ++factors;
    while (n % prime == 0) n /= prime;
    if (n <= 1) break;
  }
  while (n > 1) {
    prime = next_prime(prime);
    primes.push_back(prime);
    if (n % prime == 0) ++factors;
    while (n % prime == 0) n /= prime;
  }
  return factors == 4;
}

int Start() {
  unsigned int i = 647;
  while (true) {
    int cnt = 0;
    while (has_four_prime_factors(i + cnt)) {
      if (cnt == 3) {
        std::cout << i << std::endl;
        return 0;
      }
      ++cnt;
    }
    i += 1 + cnt;
  }
  return 1;
}
}
