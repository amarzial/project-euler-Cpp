#include "utils.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

namespace prob38 {

bool check_pandigit(int n) {
  std::array<int, 10> vals;
  vals.fill(0);
  while (n > 0) {
    vals[n % 10] = 1;
    n /= 10;
  }
  for (int i = 1; i < 10; i++) {
    if (vals[i] == 0) return false;
  }
  return true;
}

int makemult(int n) {
  int out = n;
  for (int i = 2; i <= 9; i++) {
    int t = n * i;
    int digs;
    int digs2;
    digs = utils::digit_count(out);
    if (digs == 9) return check_pandigit(out) ? out : 0;
    if (((digs) + (digs2 = utils::digit_count(t))) > 9) return 0;
    out = out * std::pow(10, digs2) + t;
  }
  return 0;
}

int Start() {
  int maxval = 0;
  for (int i = 1; i < 10000; i++) {
    maxval = std::max(makemult(i), maxval);
  }
  std::cout << maxval << std::endl;
  return (0);
}
}
