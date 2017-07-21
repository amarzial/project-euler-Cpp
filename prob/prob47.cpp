#include "utils.hpp"

#include <iostream>
#include <vector>

namespace prob47 {

std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

int next_prime(int n) {
  if (n == 2) return 3;
  do {
    n += 2;
  } while (not utils::is_prime_miller(n));
  return (n);
}

bool has_four_prime_factors(int n) {
  if (utils::is_prime_miller(n)) return false;
  int prime;
  auto rem = n;
  int factors = 0;
  for (auto p : primes) {
    prime = p;
    if (rem % prime == 0) ++factors;
    while (rem % prime == 0) {
      rem /= prime;
      if (utils::is_prime_miller(rem)) {
        ++factors;
        rem = 1;
        break;
      }
    }
    if (rem <= 1) break;
  }
  while (rem > 1) {
    prime = next_prime(prime);
    primes.push_back(prime);
    if (rem % prime == 0) ++factors;
    while (rem % prime == 0) {
      rem /= prime;
      if (utils::is_prime_miller(rem)) {
        ++factors;
        rem = 1;
        break;
      }
    }
  }
  return factors == 4;
}

int Start() {
  int i = 647;
  int cnt = 0;
  while (cnt < 4) {
    if (has_four_prime_factors(i++)) {
      ++cnt;
    } else {
      cnt = 0;
    }
  }
  std::cout << i << std::endl;
  return 0;
}
}
