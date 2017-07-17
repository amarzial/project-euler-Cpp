#include <cmath>
#include <iostream>
#include <set>
#include <vector>

namespace prob36 {
int genPalyndrome(int body, int base, bool odd) {
  int out = body;

  if (odd) out /= base;

  while (body > 0) {
    out = (out * 10) + (body % base);
    body /= base;
  }
  return out;
}

bool isPalyndrome(int num, int base) {
  int rev = 0;
  int orig = num;

  while (orig > 0) {
    rev = rev * base + orig % base;
    orig /= base;
  }

  return (num == rev);
}

int Start() {
  const int limit = 1000000;
  int total = 0;

  int pal;
  bool odd;
  for (int t = 0; t < 2; ++t) {
    odd = (t % 2 == 0);
    int i = 1;
    while ((pal = genPalyndrome(i, 10, odd)) < limit) {
      if (isPalyndrome(pal, 2)) total += pal;
      ++i;
    }
  }
  std::cout << total << std::endl;
  return 0;
}
}
