#include <sablefish/Bitboard.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Move.hpp>
#include <sablefish/Utilities.hpp>

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

// Returns a boolean representing whether or not a Move is a promotion based on the given Piece and target BoardSquare.
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

// Returns a string representation of the given MoveType.
std::string
ToString(const MoveType moveType)
{
    switch (moveType) {
        case MoveType::Quiet: return "Quiet";
        case MoveType::KingCastle: return "KingCastle";
        case MoveType::QueenCastle: return "QueenCastle";
        case MoveType::DoublePawnPush: return "DoublePawnPush";
        case MoveType::Capture: return "Capture";
        case MoveType::EnPassant: return "EnPassant";
        case MoveType::KnightPromotion: return "KnightPromotion";
        case MoveType::BishopPromotion: return "BishopPromotion";
        case MoveType::RookPromotion: return "RookPromotion";
        case MoveType::QueenPromotion: return "QueenPromotion";
        case MoveType::KnightPromotionCapture: return "KnightPromotionCapture";
        case MoveType::BishopPromotionCapture: return "BishopPromotionCapture";
        case MoveType::RookPromotionCapture: return "RookPromotionCapture";
        case MoveType::QueenPromotionCapture: return "QueenPromotionCapture";
        default: return "Unknown MoveType";
    }
}

// Returns a string representation of the given Move.
std::string
ToString(const Move move)
{
    auto startingSquare = (move & STARTING_SQUARE_MASK) >> 10;
    auto targetSquare = (move & TARGET_SQUARE_MASK) >> 4;
    auto moveType = move & MOVE_TYPE_MASK;

    std::string moveString = "Starting Square: " + ToString(static_cast<BoardSquare>(startingSquare)) + "\n";
    moveString += "Target Square: " + ToString(static_cast<BoardSquare>(targetSquare)) + "\n";
    moveString += "Move Type: " + ToString(static_cast<MoveType>(moveType)) + "\n";

    return moveString;
}
} // namespace sablefish::moves
