#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

namespace prob42 {

bool is_triangular(const std::string& str) {
  int value = 0;
  for (auto c : str) value += c - 'A' + 1;
  int delta = (1 + 4 * (2 * value));
  int cmp = sqrt(delta);
  if (cmp * cmp == delta and cmp % 2) return true;
  return false;
}

int Start() {
  std::ifstream t("./files/p042_words.txt");
  std::stringstream buffer;
  buffer << t.rdbuf();
  std::string str = buffer.str();
  size_t begin = 0;
  size_t next = 0;
  int count = 0;
  while (next != std::string::npos) {
    next = str.find(',', begin);
    std::string s;
    if (next != std::string::npos)
      s = str.substr(begin + 1, next - begin - 2);
    else
      s = str.substr(begin + 1, str.size() - begin - 2);
    if (is_triangular(s)) count++;
    begin = next + 1;
  }
  std::cout << count << std::endl;
  t.close();
  return 0;
}
}
