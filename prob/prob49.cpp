#include <iostream>
#include <vector>

namespace prob49 {

std::vector<char> plist;

std::vector<char> prime_list(int size) {
  std::vector<char> vec;
  vec.resize(size + 1, 1);
  for (int i = 2; i <= size; ++i) {
    if (vec[i] == 1) {
      for (int j = 2 * i; j <= size; j += i) vec[j] = 0;
    }
  }
  return vec;
}

void char_swap(char *a, char *b) {
  const char tmp = *a;
  *a = *b;
  *b = tmp;
}

int next_perm(int num) {
  int val = num;
  char digs[4];
  for (int i = 0; i < 4; ++i) {
    digs[4 - i - 1] = val % 10;
    val /= 10;
  }
  int k = -1;
  for (int i = 0; i < 3; ++i) {
    if (digs[i] < digs[i + 1]) k = i;
  }
  if (k == -1) return 0;
  int l = -1;
  for (int j = k + 1; j < 4; j++) {
    if (digs[k] < digs[j]) l = j;
  }
  char_swap(digs + k, digs + l);
  if (k == 0)
    char_swap(digs + 1, digs + 3);
  else if (k == 1)
    char_swap(digs + 2, digs + 3);
  val = 0;
  for (int i = 0; i < 4; i++) {
    val *= 10;
    val += digs[i];
  }
  return val;
}

int Start() {
  plist = prime_list(10000);
  for (int first = 1489; first < 10000; first += 2) {
    if (plist[first]) {
      int second = first;
      while ((second = next_perm(second)) != 0) {
        if (plist[second]) {
          int diff = second - first;
          int third = second;
          while ((third = next_perm(third)) != 0) {
            if (plist[third] and (third - second == diff)) {
              std::cout << first << second << third << std::endl;
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}
}
