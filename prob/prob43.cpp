#include <algorithm>
#include <cstdint>
#include <iostream>

namespace prob43 {

int get_three(int *nbr) { return ((nbr[0] * 100) + (nbr[1] * 10) + (nbr[2])); }

uint64_t get_full(int *nbr) {
  uint64_t tot = 0;
  for (int i = 0; i < 10; i++) {
    tot *= 10;
    tot += nbr[i];
  }
  return tot;
}

bool is_divisible(int *num) {
  if (get_three(num + 1) % 2) return false;
  if (get_three(num + 2) % 3) return false;
  if (get_three(num + 3) % 5) return false;
  if (get_three(num + 4) % 7) return false;
  if (get_three(num + 5) % 11) return false;
  if (get_three(num + 6) % 13) return false;
  if (get_three(num + 7) % 17) return false;
  return true;
}

int Start() {
  int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  uint64_t sum = 0;
  do {
    if (is_divisible(nums)) sum += get_full(nums);
  } while (std::next_permutation(nums, nums + 10));
  std::cout << sum << std::endl;
  return 0;
}
}
