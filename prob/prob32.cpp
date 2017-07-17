#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
namespace prob32 {
bool isPandigital(long n) {
  int digs[9] = {0};
  int cnt = 0;
  long tmp = n;
  while (tmp > 0) {
    int r = tmp % 10;
    if (r == 0) return false;
    digs[r - 1]++;
    cnt++;
    tmp /= 10;
  }
  for (int i = 0; i < cnt; i++)
    if (digs[i] == 0) return false;
  return true;
}

long joinNum(int n1, int n2, int n3) {
  return (n1 * pow10(((int)log10(n2) + 1) + ((int)log10(n3) + 1)) +
          n2 * pow10((int)log10(n3) + 1) + n3);
}
int Start() {
  set<int> prods;
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 100; j++) {
      long res;
      res = joinNum(i, j, i * j);
      if (res <= 987654321 && res > 123456789) {
        if (isPandigital(res)) prods.insert(i * j);
      }
    }
  }
  int res = 0;
  for (set<int>::iterator it = prods.begin(); it != prods.end(); it++)
    res += *it;
  cout << res << endl;
  return 0;
}
}
