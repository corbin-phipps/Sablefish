#include <bitset>
#include <iostream>

#include <sablefish/Constants.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board::piece;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

namespace sablefish::board {
// Returns an array of BoardSquares that are occupied according to the given Bitboard.
std::vector<BoardSquare>
ConvertBitboardToBoardSquares(const Bitboard& bitboard)
{
    std::vector<BoardSquare> boardSquares{};

    std::bitset<NUM_SQUARES> bits(bitboard);
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i]) {
            boardSquares.push_back(static_cast<BoardSquare>(i));
        }
    }

    return boardSquares;
}

// Returns the starting Bitboard of the piece represented by the given PieceType and PieceColor.
Bitboard
ConvertPieceDataToStartingBitboard(PieceType pieceType, PieceColor pieceColor)
{
    if (pieceType == PieceType::Pawn) {
        return (pieceColor == PieceColor::White) ? WHITE_PAWNS_START : BLACK_PAWNS_START;
    } else if (pieceType == PieceType::Rook) {
        return (pieceColor == PieceColor::White) ? WHITE_ROOKS_START : BLACK_ROOKS_START;
    } else if (pieceType == PieceType::Knight) {
        return (pieceColor == PieceColor::White) ? WHITE_KNIGHTS_START : BLACK_KNIGHTS_START;
    } else if (pieceType == PieceType::Bishop) {
        return (pieceColor == PieceColor::White) ? WHITE_BISHOPS_START : BLACK_BISHOPS_START;
    } else if (pieceType == PieceType::Queen) {
        return (pieceColor == PieceColor::White) ? WHITE_QUEEN_START : BLACK_QUEEN_START;
    } else if (pieceType == PieceType::King) {
        return (pieceColor == PieceColor::White) ? WHITE_KING_START : BLACK_KING_START;
    } else { // pieceType == PieceType::Empty
        std::cerr << "PieceType::Empty is unexpected" << std::endl;
        return 0ULL;
    }
}
} // namespace sablefish::board