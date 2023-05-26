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
    move |= (static_cast<uint16_t>(startingSquare) << 10) & STARTING_SQUARE_MASK;

    // Set the target square
    move |= (static_cast<uint16_t>(targetSquare) << 4) & TARGET_SQUARE_MASK;

    // Set the move type
    move |= static_cast<uint16_t>(moveType) & MOVE_TYPE_MASK;

    return move;
}
} // namespace sablefish::moves
