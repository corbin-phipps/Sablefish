#include "Bitboard.hpp"

namespace sablefish::board
{
/* constructor */
Bitboard::Bitboard(uint64_t bitboard) :
    m_bitboard(bitboard)
{
}

/* public */
uint64_t
Bitboard::GetBitBoard()
{
    return m_bitboard;
}
} // namespace sablefish::board