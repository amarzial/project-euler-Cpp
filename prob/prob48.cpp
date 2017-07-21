#include <cstdint>
#include <iostream>

namespace prob48 {

uint64_t trimmed_pow(int num, int exp) {
  uint64_t res = 1;
  for (int i = 0; i < exp; i++) {
    res *= exp;
    res %= 10000000000;
  }
  return res;
}

int Start() {
  uint64_t answer = 0;
  for (int i = 1; i <= 1000; i++) {
    answer += trimmed_pow(i, i);
    answer %= 10000000000;
  }
  std::cout << answer << std::endl;
  return 0;
}
}
