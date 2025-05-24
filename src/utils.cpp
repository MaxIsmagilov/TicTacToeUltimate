#include "utils.hpp"

namespace TTTU {

constexpr u8 get_location(const u8 major, const u8 minor) {
  return major * 9 + minor;
}

} // Namespace TTTU