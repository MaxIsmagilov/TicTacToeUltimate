#include "utils.hpp"

namespace TTTU {

constexpr u8 get_location(const u8 major, const u8 minor) noexcept {
  constexpr u8 maj_shifts[] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
  constexpr u8 min_shifts[] = {0, 1, 2, 9, 10, 11, 18, 19, 20};
  return maj_shifts[major] + min_shifts[minor];
}

constexpr u8 get_major(u8 location) noexcept {
  u8 mjr = 0;
  if (location % 9 < 3)
    mjr = 0;
  else if (location % 9 < 6)
    mjr = 1;
  else
    mjr = 2;
  if (location / 27 == 0)
    mjr += 0;
  else if (location / 27 == 1)
    mjr += 3;
  else
    mjr += 6;
  return mjr;
}

constexpr u8 get_minor(u8 location) noexcept {
  u8 mjr = 0;
  if (location % 3 == 0)
    mjr = 0;
  else if (location % 3 == 1)
    mjr = 1;
  else
    mjr = 2;
  if (location / 9 == 0)
    mjr += 0;
  else if (location / 9 == 1)
    mjr += 3;
  else
    mjr += 6;
  return mjr;
}

} // Namespace TTTU