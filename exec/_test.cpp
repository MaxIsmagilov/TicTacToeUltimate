#include "board.cpp"

#include <iostream>

int main() {
  TTTU::Board b{};
  std::cout << b.to_string();
  return 0;
}
