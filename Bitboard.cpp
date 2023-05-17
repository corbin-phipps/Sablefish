#include "Bitboard.hpp"

using namespace sablefish::board;

/* constructors */

// Initializes a Bitboard with the given 64-bit bitboard.
Bitboard::Bitboard(uint64_t bitboard) :
    m_bitboard(bitboard)
{
}

/* public */

// Returns the uint64_t bitboard from the current Bitboard object.
uint64_t
Bitboard::GetBitboard() const
{
    return m_bitboard;
}
