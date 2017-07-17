#include <cmath>
#include <iostream>

namespace prob40 {

int get_efficient(int n) {
  if (n < 10) return n;
  int status = 10;
  int magnitude = 1;
  int incr;
  while (true) {
    magnitude++;
    incr = (9 * std::pow(10, magnitude - 1) * magnitude);
    if (status + incr > n) {
      int number = ((n - status) / magnitude) + std::pow(10, magnitude - 1);
      int digit = ((n - status) % magnitude);
      return (
          (number / static_cast<int>(std::pow(10, (magnitude - 1) - digit))) %
          10);
    }
    status += incr;
  }
}

int Start() {
  int result = 1;
  for (auto i = 1; i <= 1000000; i *= 10) {
    result *= get_efficient(i);
  }

  std::cout << result << std::endl;
  return (0);
}
}
