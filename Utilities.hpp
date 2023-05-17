#pragma once

#include <vector>

#include "Bitboard.hpp"
#include "Board.hpp"

namespace sablefish::board
{
std::vector<BoardSquare> ConvertBitboardToBoardSquares(Bitboard bitboard);
} // namespace sablefish::board
