#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stack>

#include "Move.hpp"
#include "Piece.hpp"

namespace sablefish
{
class Player
{
public:
    Player(const board::PieceColor pieceColor);

    const board::PieceColor GetPlayerPieceColor() const;
    const size_t GetCompletedMovesCount() const;

private:
    board::PieceColor m_pieceColor{};
    std::stack<Move> m_completedMoves{};
};
}

#endif // PLAYER_HPP
