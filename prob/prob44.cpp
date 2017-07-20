#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_set>

namespace prob44 {

bool is_pentagonal(int n) {
  int num = (1 + sqrt(1 + 24 * n)) / 6;
  return (num * (3 * num - 1) / 2) == n;
}

int Start() {
  std::unordered_set<int> pents;
  int n = 2;
  while (true) {
    ++n;
    int s = n * (3 * n - 1) / 2;
    for (auto pj : pents) {
      if (not is_pentagonal(s - pj) or not is_pentagonal(s - (2 * pj)))
        continue;
      if (pents.find(s - pj) != pents.end() and
          pents.find((s - pj) - pj) != pents.end()) {
        std::cout << ((s - pj) - pj) << std::endl;
        return 0;
      }
    }
    pents.insert(s);
  }
  return 1;
}
}
