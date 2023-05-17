#include <bitset>

#include "Utilities.hpp"

using namespace sablefish::board;
using namespace sablefish::constants;

std::vector<BoardSquare>
ConvertBitboardToBoardSquares(Bitboard bitboard)
{
    std::vector<BoardSquare> boardSquares{};

    std::bitset<NUM_SQUARES> bits(bitboard.GetBitBoard());
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i]) {
            boardSquares.push_back(static_cast<BoardSquare>(i));
        }
    }

    return boardSquares;
}