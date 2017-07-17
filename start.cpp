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
    case(30):
      std::cout << "Problem 30:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob30::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(31):
      std::cout << "Problem 31:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob31::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(32):
      std::cout << "Problem 32:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob32::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(34):
      std::cout << "Problem 34:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob34::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(36):
      std::cout << "Problem 36:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob36::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(37):
      std::cout << "Problem 37:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob37::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(38):
      std::cout << "Problem 38:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob38::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(39):
      std::cout << "Problem 39:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob39::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(40):
      std::cout << "Problem 40:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob40::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    case(41):
      std::cout << "Problem 41:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob41::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
      break;
    default:
      std::cout << "Problem " + std::to_string(problem) + " not found!"
                << std::endl;
      return 0;
  }
  return 0;
}
