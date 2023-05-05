#include "Board.hpp"
#include "Bitfields.hpp"

using namespace sablefish::board;

namespace sablefish::board
{
Board::Board() :
    m_whitePawns(bitfields::WHITE_PAWNS_START),
    m_blackPawns(bitfields::BLACK_PAWNS_START),
    m_whiteRooks(bitfields::WHITE_ROOKS_START),
    m_blackRooks(bitfields::BLACK_ROOKS_START),
    m_whiteKnights(bitfields::WHITE_KNIGHTS_START),
    m_blackKnights(bitfields::BLACK_KNIGHTS_START),
    m_whiteBishops(bitfields::WHITE_BISHOPS_START),
    m_blackBishops(bitfields::BLACK_BISHOPS_START),
    m_whiteQueens(bitfields::WHITE_QUEENS_START),
    m_blackQueens(bitfields::BLACK_QUEENS_START),
    m_whiteKing(bitfields::WHITE_KING_START),
    m_blackKing(bitfields::BLACK_KING_START)
{
}

Bitboard Board::WhitePawns()
{
    return m_whitePawns;
}

Bitboard Board::BlackPawns()
{
    return m_blackPawns;
}

Bitboard Board::WhiteRooks()
{
    return m_whiteRooks;
}

Bitboard Board::BlackRooks()
{
    return m_blackRooks;
}

Bitboard Board::WhiteKnights()
{
    return m_whiteKnights;
}

Bitboard Board::BlackKnights()
{
    return m_blackKnights;
}

Bitboard Board::WhiteBishops()
{
    return m_whiteBishops;
}

Bitboard Board::BlackBishops()
{
    return m_blackBishops;
}

Bitboard Board::WhiteQueens()
{
    return m_whiteQueens;
}

Bitboard Board::BlackQueens()
{
    return m_blackQueens;
}

Bitboard Board::WhiteKing()
{
    return m_whiteKing;
}

Bitboard Board::BlackKing()
{
    return m_blackKing;
}
} // namespace sablefish::board
