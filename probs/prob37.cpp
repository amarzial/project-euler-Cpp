#include "utils.hpp"

#include <cmath>
#include <iostream>
#include <set>
#include <vector>

namespace prob37 {

std::set<int> nbrs;

bool is_truncatable(int n) {
  if (n == 0) return true;
  if (utils::isPrime(n)) return (is_truncatable(n / 10));
  return (false);
}

void get_nbrs(int n, int digits) {
  if (digits > 7 or not utils::isPrime(n)) return;
  if (digits > 1 and is_truncatable(n)) {
    nbrs.insert(n);
  }
  for (auto i = 1; i <= 9; ++i) get_nbrs(n + i * (pow(10, digits)), digits + 1);
}

int Start() {
  get_nbrs(3, 1);
  get_nbrs(7, 1);
  int tot = 0;
  for (auto v : nbrs) {
    tot += v;
  }
  std::cout << tot << std::endl;
  return 0;
}
}
