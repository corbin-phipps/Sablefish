#include "Bitboard.hpp"

namespace sablefish::board
{
Bitboard::Bitboard(uint64_t bitboard) :
    m_bitboard(bitboard)
{
}

uint64_t
Bitboard::GetBitBoard()
{
    return m_bitboard;
}
} // namespace sablefish::board
