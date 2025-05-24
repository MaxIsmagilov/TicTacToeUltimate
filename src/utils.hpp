/// utils.hpp
/// This provides definitions to basic types, enums, and functions

#pragma once

#include <cstdint>
#include <string>

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
constexpr u8 get_location(const u8 major, const u8 minor) noexcept;

/// @brief gets the major square of the location in question
/// @param location
/// @return a u8
constexpr u8 get_major(u8 location) noexcept;

/// @brief gets the minor square of the location in question
/// @param location
/// @return a u8
constexpr u8 get_minor(u8 location) noexcept;

/// @brief text names for positions
static const std::string position_names[10] = {
    "top left",     "top middle",  "top right",     "middle left",  "middle",
    "middle right", "bottom left", "bottom middle", "bottom right", "anywhere"};

} // namespace TTTU
