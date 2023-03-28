#include <iostream>
#include <limits>

namespace input_prot {
// Function for validating integer input within a specified range
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
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout
          << "Your input has been validated {Lower & Upper Validator (int)}"
          << std::endl;
      return num;
    }
  }
}

// Function for validating integer input with a lower bound only
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
      std::cout << "Your input has been validated {LowerBound (int) Validator}"
                << std::endl;
      return num;
    }
  }
}

// Function for validating double input within a specified range
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

// Function for validating char input from a list of acceptable values
char validate_char_list(const std::string &prompt, const std::string &error_msg,
                        const std::string &char_list) {
  char input_char;
  while (true) {
    std::cout << prompt;
    std::cin >> input_char;
    if (std::cin.fail() || char_list.find(input_char) == std::string::npos) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << error_msg << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Your input has been validated {Char List Validator}"
                << std::endl;
      return input_char;
    }
  }
}
} // namespace input_prot
int main() {
  int num1 = input_prot::validate_int_lower(
      "Enter a Number: ",
      "The value you have entered has caused an error, please try again\n", 0);
  std::cout << "Enter a Number: ";
  double num2 = input_prot::validate_double_range(
      "", "The value you have entered has caused an error, please try again\n",
      0.0, 100.0);
  std::cout << "Enter a grade (i.e. 0 - 100): ";
  int grade1 = input_prot::validate_int_range(
      "", "The value you have entered has caused an error, please try again\n",
      0, 100);
  std::cout << "Enter a grade (i.e. 0.0 - 100.00): ";
  double grade2 = input_prot::validate_double_range(
      "", "The value you have entered has caused an error, please try again\n",
      0.0, 100.0);

  return 0;
}