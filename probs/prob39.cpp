#include <iostream>

namespace prob39 {

bool is_rect(int a, int p) {
  int n = (2 * a * a + p * p - 2 * p * a);
  int d = (2 * (p - a));
  return not(n % d);
}

int Start() {
  int maxcount = 0;
  int solution = 0;
  for (int i = 3; i <= 1000; i++) {
    int count = 0;
    for (int j = 1; j <= i / 4; j++) {
      if (is_rect(j, i)) count++;
    }
    if (count > maxcount) {
      maxcount = count;
      solution = i;
    }
  }
  std::cout << solution << std::endl;
  return (0);
}
}
