#pragma once

#include "Bitboard.hpp"

namespace sablefish::board
{
class Board
{
public:
    Board();

    Bitboard WhitePawns();
    Bitboard BlackPawns();
    Bitboard WhiteRooks();
    Bitboard BlackRooks();
    Bitboard WhiteKnights();
    Bitboard BlackKnights();
    Bitboard WhiteBishops();
    Bitboard BlackBishops();
    Bitboard WhiteQueens();
    Bitboard BlackQueens();
    Bitboard WhiteKing();
    Bitboard BlackKing();

private:
    Bitboard m_whitePawns;
    Bitboard m_blackPawns;
    Bitboard m_whiteRooks;
    Bitboard m_blackRooks;
    Bitboard m_whiteKnights;
    Bitboard m_blackKnights;
    Bitboard m_whiteBishops;
    Bitboard m_blackBishops;
    Bitboard m_whiteQueens;
    Bitboard m_blackQueens;
    Bitboard m_whiteKing;
    Bitboard m_blackKing;
};
} // namespace sablefish::board
