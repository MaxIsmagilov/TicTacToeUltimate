#include "board.hpp"

namespace TTTU {

Board::Board() noexcept : m_area{SquareValue::None} {}

Board::Board(Board &&other) noexcept : m_area{other.m_area} {}

void Board::operator=(const Board &other) noexcept {
  std::copy(other.m_area.begin(), other.m_area.end(), m_area.begin());
}

constexpr void Board::switch_side() noexcept { m_side = (m_side == 0) ? 1 : 0; }

constexpr void Board::set_side(const u8 value) noexcept { m_side = value; }

constexpr void Board::set(const u8 major, const u8 minor,
                          const SquareValue s) noexcept {
  m_area[get_location(major, minor)] = s;
}

constexpr SquareValue Board::at(const u8 major, const u8 minor) const noexcept {
  return m_area[get_location(major, minor)];
}

std::string Board::to_string() const noexcept {
  std::string outpt{};

  for (u8 i = 0; i < 81; ++i) {
    switch (m_area[i]) {
    case SquareValue::X:
      outpt += "X";
      break;
    case SquareValue::O:
      outpt += "O";
      break;
    default:
      outpt += " ";
      break;
    }
    if (i == 80)
      outpt += "\n";
    else if (i % 27 == 26)
      outpt += std::string("\n           |             |\n") +
               std::string("-----------+-------------+-----------\n") +
               std::string("           |             |\n");
    else if (i % 9 == 8)
      outpt += "\n--+---+--  |  --+---+--  | ---+---+--\n";
    else if (i % 3 == 2)
      outpt += "  |  ";
    else
      outpt += " | ";
  }
  return outpt;
}

} // namespace TTTU
