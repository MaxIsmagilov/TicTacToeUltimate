#include "board.hpp"

namespace TTTU {

Board::Board() noexcept : m_area{SquareValue::None} {}

Board::Board(Board &&other) noexcept
    : m_area{other.m_area}, m_moveable_position{other.m_moveable_position} {}

void Board::operator=(const Board &other) noexcept {
  std::copy(other.m_area.begin(), other.m_area.end(), m_area.begin());
  m_moveable_position = other.m_moveable_position;
}

constexpr void Board::move(const u8 location) noexcept {
  m_area[location] = (m_side == 0) ? SquareValue::X : SquareValue::O;
  switch_side();
  m_moveable_position = get_minor(location);
}

constexpr void Board::switch_side() noexcept { m_side = (m_side == 0) ? 1 : 0; }

constexpr void Board::set_side(const u8 value) noexcept { m_side = value; }

constexpr void Board::set(const u8 major, const u8 minor,
                          const SquareValue s) noexcept {
  m_area[get_location(major, minor)] = s;
}

constexpr void Board::set(const u8 location, const SquareValue s) noexcept {
  m_area[location] = s;
}

constexpr SquareValue Board::at(const u8 major, const u8 minor) const noexcept {
  return m_area[get_location(major, minor)];
}

constexpr SquareValue Board::at(const u8 location) const noexcept {
  return m_area[location];
}

std::string Board::to_string(const std::vector<u8> &locations) const noexcept {
  std::string outpt{};

  for (u8 i = 0; i < 81; ++i) {
    u8 ind = std::ranges::find(locations, i) - locations.begin();
    if (ind != locations.size()) {
      outpt += std::to_string(ind);
      if (ind / 10 == 0)
        outpt += " ";
    } else {
      outpt += [](SquareValue s) -> std::string {
        switch (s) {
        case SquareValue::X:
          return "X ";
        case SquareValue::O:
          return "O ";
        default:
          return "  ";
        }
      }(m_area[i]);
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
      outpt += " |  ";
    else
      outpt += "| ";
  }
  outpt += (m_side == 0) ? "X" : "O";
  outpt += " can go ";
  outpt += position_names[m_moveable_position];
  outpt += "\n";

  return outpt;
}

} // namespace TTTU
