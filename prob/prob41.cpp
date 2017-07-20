#include "utils.hpp"

#include <iostream>

namespace prob41 {
int Start() {
  for (auto i = 7654321; i > 1235; i -= 2) {
    if (utils::is_pandigital(i) and utils::is_prime(i)) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  return 0;
}
}
