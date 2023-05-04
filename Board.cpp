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
} // namespace sablefish::board
