#include <cmath>
#include <iostream>
#include <unordered_set>

namespace prob44 {
int Start() {
  std::unordered_set<int> pents;
  int n = 2;
  while (true) {
    ++n;
    int s = n * (3 * n - 1) / 2;
    for (auto pj : pents) {
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
