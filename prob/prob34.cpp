#include <cmath>
#include <iostream>

#include "utils.hpp"

namespace prob34 {
bool isCurious(int num) {
  int tot = 0, tmp = num;
  for (int i = 0; i < utils::digit_count(num); i++) {
    tot += utils::factorial(tmp % 10);
    tmp /= 10;
  }
  return (num == tot && (num != 1 && num != 2)) ? true : false;
}

int Start() {
  int sum = 0;
  for (int i = 3; i < 100000; i++) {
    if (prob34::isCurious(i)) sum += i;
  }
  std::cout << sum << std::endl;
  return 0;
}
}
