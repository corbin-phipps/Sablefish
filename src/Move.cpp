#include <sablefish/Bitboard.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Move.hpp>

using namespace sablefish::board;

namespace sablefish::moves
{
// Creates and returns a Move based on the given start/target BoardSquares and the MoveType.
Move
CreateMove(BoardSquare startingSquare, BoardSquare targetSquare, MoveType moveType)
{
    Move move = 0U;
    
    // Set the starting square
    move |= (startingSquare << 10) & STARTING_SQUARE_MASK;

    // Set the target square
    move |= (targetSquare << 4) & TARGET_SQUARE_MASK;

    // Set the move type
    move |= static_cast<size_t>(moveType) & MOVE_TYPE_MASK;

    return move;
}

// Returns a boolean representing whether or not a Move is a promotion based on the given Piece and target BoardSquare
bool
IsPromotion(Piece piece, BoardSquare targetSquare)
{
    Bitboard square = 1ULL << targetSquare;
    if (piece.GetPieceType() == PieceType::Pawn) {
        if (piece.GetPieceColor() == PieceColor::White) {
            return square & bitfields::RANK_8;
        } else if (piece.GetPieceColor() == PieceColor::Black) {
            return square & bitfields::RANK_1;
        } else { // PieceColor::Empty
            // TODO: Log error
            return false;
        }
    } else {
        return false;
    }
}
} // namespace sablefish::moves
