#include <cmath>
#include <iostream>
#include <vector>

namespace prob30 {
int sumPowers(int n) {
  std::vector<int> digits;
  while (n >= 10) {
    digits.push_back(n % 10);
    n /= 10;
  }
  digits.push_back(n);
  int sum = 0;
  for (unsigned int i = 0; i < digits.size(); i++) {
    sum += pow(digits[i], 5);
  }
  return sum;
}

int Start() {
  int n = 1000;
  int res = 0;
  while (++n < 355000) {
    if (prob30::sumPowers(n) == n) res += n;
  }
  std::cout << res << std::endl;
  return 0;
}
}
