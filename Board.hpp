#pragma once

#include <array>

#include "Bitboard.hpp"
#include "Constants.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::board
{
class Board
{
public:
    Board();

    void Initialize();
    Bitboard GetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor);
    Square GetSquare(BoardSquare boardSquare);

private:
    void InitializeBitboards();
    void InitializeSquares();
    int GetBitboardIndex(piece::PieceType pieceType, piece::PieceColor pieceColor);

    std::array<Bitboard, constants::NUM_PIECE_TYPES * constants::NUM_COLORS> m_bitboards;
    std::array<Square, constants::NUM_SQUARES> m_squares;
};
} // namespace sablefish::board
