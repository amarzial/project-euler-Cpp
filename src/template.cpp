#include "problems.hpp"

#include <chrono>
#include <iostream>
#include <string>

template <class T>
void print_speed(T diff, bool full = false) {
  std::string title;
  if (full)
    title = "Total execution time: ";
  else
    title = "Execution time: ";
  std::cout
      << title
      << (std::chrono::duration_cast<std::chrono::microseconds>(diff).count() /
          1000.)
      << "ms" << std::endl;
}

void usage() {
  std::cout << "Usage:\n\n    euler [problem_number]" << std::endl;
}

int main(int argc, char **argv) {
  int problem = 0;
  if (argc == 1) {
    std::cout << "Problem number (0: full run): ";
    std::cin >> problem;
    std::cin.ignore();
    std::cout << "Executing n: " << problem << std::endl;
  } else if (argc == 2) {
    try {
      problem = std::stoi(argv[1], nullptr, 10);
    } catch (int e) {
      usage();
      exit(e);
    }
  } else {
    usage();
    return 0;
  }
  auto start_t = std::chrono::system_clock::now();
  auto end_t = std::chrono::system_clock::now();
  auto full_timer_start = std::chrono::system_clock::now();
  auto full_run = false;
  switch (problem) {
    case 0:
      full_run = true;
      full_timer_start = std::chrono::system_clock::now();
    $TEMPLATE$
    case ({0}):
      std::cout << "Problem {0}:" << std::endl;
      start_t = std::chrono::system_clock::now();
      prob{0}::Start();
      end_t = std::chrono::system_clock::now();
      print_speed(end_t - start_t);
      if (not full_run) break;
    $END_TEMPLATE$
      break;
    default:
      std::cout << "Problem " + std::to_string(problem) + " not found!"
                << std::endl;
      return 0;
  }
  if (full_run) {
      auto full_timer_stop = std::chrono::system_clock::now();
      print_speed(full_timer_stop - full_timer_start, true);
  }
  return 0;
}
