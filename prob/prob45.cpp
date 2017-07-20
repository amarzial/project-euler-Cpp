#include <iostream>
#include <cmath>
#include <cstdint>

namespace prob45 {
int64_t get_hexagonal(int64_t n) { return (n * (2 * n - 1)); }

bool is_pentagonal(int64_t n) {
  int64_t num = (1 + sqrt(1 + 24 * n)) / 6;
  return (num * (3 * num - 1) / 2) == n;
}

int Start() {
  int64_t i = 144;
  while (true) {
    int64_t num = get_hexagonal(i);
    if (is_pentagonal(num)) {
      std::cout << num << std::endl;
      return (0);
    }
    ++i;
  }
}
}
