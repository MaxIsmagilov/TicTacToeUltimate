/// utils.hpp
/// This provides definitions to basic types, enums, and functions

#pragma once

#include <cstdint>

namespace TTTU {

/// @brief 32-bit unsigned value
using u32 = uint32_t;

/// @brief 8-bit unsigned value
using u8 = uint8_t;

/// @brief values for squares being full or marked
enum SquareValue : u8 { None = 0U, X = 2U, O = 3U };

/// @brief converts a major/minor location to an array index
/// @param major
/// @param minor
/// @return u8
constexpr u8 get_location(const u8 major, const u8 minor);

} // namespace TTTU
