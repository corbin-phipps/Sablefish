#include <bitset>

#include "Constants.hpp"
#include "Utilities.hpp"

using namespace sablefish::board;
using namespace sablefish::board::piece;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

std::vector<BoardSquare>
ConvertBitboardToBoardSquares(const Bitboard& bitboard)
{
    std::vector<BoardSquare> boardSquares{};

    std::bitset<NUM_SQUARES> bits(bitboard.GetBitboard());
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i]) {
            boardSquares.push_back(static_cast<BoardSquare>(i));
        }
    }

    return boardSquares;
}

Bitboard
ConvertPieceDataToBitboard(PieceType pieceType, PieceColor pieceColor)
{
    if (pieceType == PieceType::Pawn) {
        return (pieceColor == PieceColor::White) ? Bitboard(WHITE_PAWNS_START) : Bitboard(BLACK_PAWNS_START);
    } else if (pieceType == PieceType::Rook) {
        return (pieceColor == PieceColor::White) ? Bitboard(WHITE_ROOKS_START) : Bitboard(BLACK_ROOKS_START);
    } else if (pieceType == PieceType::Knight) {
        return (pieceColor == PieceColor::White) ? Bitboard(WHITE_KNIGHTS_START) : Bitboard(BLACK_KNIGHTS_START);
    } else if (pieceType == PieceType::Bishop) {
        return (pieceColor == PieceColor::White) ? Bitboard(WHITE_BISHOPS_START) : Bitboard(BLACK_BISHOPS_START);
    } else if (pieceType == PieceType::Queen) {
        return (pieceColor == PieceColor::White) ? Bitboard(WHITE_QUEENS_START) : Bitboard(BLACK_QUEENS_START);
    } else { // pieceType == PieceType::King
        return (pieceColor == PieceColor::White) ? Bitboard(WHITE_KING_START) : Bitboard(BLACK_KING_START);
    }
}
