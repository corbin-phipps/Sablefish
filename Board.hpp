#pragma once

#include <array>

#include "Bitboard.hpp"
#include "Constants.hpp"

namespace sablefish::board
{
// TODO: Would these be better somewhere else?
enum class PieceType {
    Pawn = 0,
    Rook = 1,
    Knight = 2,
    Bishop = 3,
    Queen = 4,
    King = 5
};

enum class PieceColor {
    White = 0,
    Black = 1
};

class Board
{
public:
    Board();

    Bitboard GetBitboard(PieceType pieceType, PieceColor pieceColor);

private:
    void InitializeBitboards();
    int GetBitboardIndex(PieceType pieceType, PieceColor pieceColor);

    std::array<Bitboard, constants::NUM_PIECE_TYPES * constants::NUM_COLORS> m_bitboards;
};
} // namespace sablefish::board
