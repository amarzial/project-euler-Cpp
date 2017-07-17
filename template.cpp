#include "problems.hpp"

#include <chrono>
#include <iostream>

template <class T>
void print_speed(T diff) {
  std::cout
      << "Execution time: "
      << (std::chrono::duration_cast<std::chrono::microseconds>(diff).count() /
          1000.)
      << "ms" << std::endl;
}

int main() {
  int problem = 0;
  std::cout << "Problem number (0: full run): ";
  std::cin >> problem;
  std::cin.ignore();
  std::cout << "Executing n: " << problem << std::endl;
  auto start_t = std::chrono::system_clock::now();
  auto end_t = std::chrono::system_clock::now();
  auto full_run = false;
  switch (problem) {
    case 0:
      full_run = true;
      $REPLACE$
      break;
    default:
      std::cout << "Problem " + std::to_string(problem) + " not found!"
                << std::endl;
      return 0;
  }
  return 0;
}
