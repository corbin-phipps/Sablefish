#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>

#include "Bitboard.hpp"
#include "Board.hpp"
#include "Piece.hpp"

namespace sablefish::board
{
const std::vector<BoardSquare> ConvertBitboardToBoardSquares(const Bitboard bitboard);
const Bitboard ConvertBoardSquaresToBitboard(const std::vector<BoardSquare>& boardSquares);
const Bitboard ConvertPieceDataToStartingBitboard(const PieceType pieceType, const PieceColor pieceColor);
Piece ConvertBoardSquareToStartingPiece(const BoardSquare boardSquare);
} // namespace sablefish::board

#endif // UTILITIES_HPP
