#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

namespace prob50 {
std::vector<int> sieve(int cap, std::vector<bool>& nums) {
  std::vector<int> primes;

  nums.resize(cap + 1, true);
  for (int i = 2; i <= cap; ++i) {
    if (nums[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= cap; j += i) nums[j] = false;
    }
  }
  return primes;
}

std::vector<int> prime_sum(std::vector<int>& primes) {
  std::vector<int> psum;
  psum.resize(primes.size() + 1, 0);
  for (uint32_t i = 0; i < primes.size(); ++i) {
    psum[i + 1] = psum[i] + primes[i];
    if (psum[i + 1] > 1000000) {
      psum.resize(i + 1);
      break;
    }
  }
  return psum;
}

int Start() {
  std::vector<bool> nums;
  auto numbers = sieve(1000000, nums);
  auto psum = prime_sum(numbers);
  int answer = 0;
  for (auto n = psum.begin(); n != psum.end(); n++) {
    for (auto i = psum.rbegin(); i != psum.rend(); ++i) {
      if (*n > *i) break;
      if (nums[*i - *n]) answer = std::max(answer, *i - *n);
    }
  }
  std::cout << answer << std::endl;
  return 0;
}
}
