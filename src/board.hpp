/// board.hpp
/// this file contains the declarations for a board

#pragma once

#include "utils.cpp"

#include <array>
#include <ranges>
#include <string>

namespace TTTU {

class Board {
public:
  /// @brief constructor for Board
  Board() noexcept;

  /// @brief copy for Board
  /// @param other another board
  Board(Board &&other) noexcept;

  /// @brief assignment for Board
  /// @param other another board
  void operator=(const Board &other) noexcept;

  /// @brief switches the side to move
  constexpr void switch_side() noexcept;

  /// @brief sets the side to move
  /// @param value
  constexpr void set_side(const u8 value) noexcept;

  /// @brief sets a square for the board
  /// @param major
  /// @param minor
  /// @param s
  constexpr void set(const u8 major, const u8 minor,
                     const SquareValue s) noexcept;

  /// @brief gets the value at a square
  /// @param major
  /// @param minor
  /// @return a SquareValue
  constexpr SquareValue at(const u8 major, const u8 minor) const noexcept;

  /// @brief gets a string representation of the board
  /// @return a std::string
  std::string to_string() const noexcept;

private:
  /// @brief an array representing the board
  std::array<SquareValue, 81> m_area;

  /// @brief the side to move
  u8 m_side{0};

  /// @brief 9 is null here
  u8 moveable_position{9};
};

} // namespace TTTU
