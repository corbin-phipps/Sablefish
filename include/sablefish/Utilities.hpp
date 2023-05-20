#pragma once

#include <vector>

#include "Bitboard.hpp"
#include "Board.hpp"

namespace sablefish::board
{
std::vector<BoardSquare> ConvertBitboardToBoardSquares(const Bitboard& bitboard);
Bitboard ConvertPieceDataToStartingBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor);
} // namespace sablefish::board
