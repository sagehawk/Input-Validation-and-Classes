#include <iostream>
#include <limits>

namespace input_prot {
int validate_int_range(const std::string &prompt, const std::string &error_msg,
                       int lower_bound, int upper_bound) {
  int num;
  while (true) {
    std::cout << prompt;
    std::cin >> num;
    if (std::cin.fail() || num < lower_bound || num > upper_bound) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << error_msg << std::endl;
    } else {
      std::cin.ignore();
      std::cout
          << "Your input has been validated {Lower & Upper Validator (int)}"
          << std::endl;
      return num;
    }
  }
}

int validate_int_lower(const std::string &prompt, const std::string &error_msg,
                       int lower_bound) {
  int num;
  while (true) {
    std::cout << prompt;
    std::cin >> num;
    if (std::cin.fail() || num < lower_bound) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << error_msg << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      ;
      std::cout << "Your input has been validated {LowerBound (int) Validator}"
                << std::endl;
      return num;
    }
  }
}

double validate_double_range(const std::string &prompt,
                             const std::string &error_msg, double lower_bound,
                             double upper_bound) {
  double num;
  while (true) {
    std::cout << prompt;
    std::cin >> num;
    if (std::cin.fail() || num < lower_bound || num > upper_bound) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << error_msg << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout
          << "Your input has been validated {Lower & Upper Validator (double)}"
          << std::endl;
      return num;
    }
  }
}
int main() {}
