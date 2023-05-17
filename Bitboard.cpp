#include "Bitboard.hpp"

using namespace sablefish::board;

/* constructor */
Bitboard::Bitboard(uint64_t bitboard) :
    m_bitboard(bitboard)
{
}

/* public */
uint64_t
Bitboard::GetBitboard() const
{
    return m_bitboard;
}
