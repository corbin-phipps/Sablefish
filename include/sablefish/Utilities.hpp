#pragma once

#include <vector>

#include "Bitboard.hpp"
#include "Board.hpp"

namespace sablefish::board
{
const std::vector<BoardSquare> ConvertBitboardToBoardSquares(const Bitboard bitboard);
const Bitboard ConvertPieceDataToStartingBitboard(const piece::PieceType pieceType, const piece::PieceColor pieceColor);
} // namespace sablefish::board
