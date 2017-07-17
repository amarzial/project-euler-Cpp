#include "utils.hpp"

#include <iostream>

namespace prob41 {
int Start() {
  for (auto i = 7654321; i > 1235; i -= 2) {
    if (utils::isPandigital(i) and utils::isPrime(i)) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  return 0;
}
}
