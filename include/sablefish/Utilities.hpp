#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <vector>

#include "Bitboard.hpp"
#include "Board.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::board
{
const std::vector<BoardSquare> ConvertBitboardToBoardSquares(const Bitboard bitboard);
const Bitboard ConvertBoardSquaresToBitboard(const std::vector<BoardSquare>& boardSquares);
const Bitboard ConvertPieceDataToStartingBitboard(const PieceType pieceType, const PieceColor pieceColor);
Square ConvertBoardSquareToStartingSquare(const BoardSquare boardSquare);

std::string ToString(const Bitboard bitboard);
std::string ToString(const BoardSquare boardSquare);
} // namespace sablefish::board

#endif // UTILITIES_HPP
