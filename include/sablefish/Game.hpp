#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <stack>

#include "Board.hpp"
#include "Move.hpp"
#include "Player.hpp"

namespace sablefish
{
class Game
{
public:
    Game();

    std::shared_ptr<board::Board> GetBoard() const;
    Player GetPlayer(const board::PieceColor pieceColor) const;
    std::pair<moves::Move, board::PieceColor> GetLastMove() const;

private:
    std::shared_ptr<board::Board> m_board{};
    Player m_whitePlayer{ board::PieceColor::White, m_board };
    Player m_blackPlayer{ board::PieceColor::Black, m_board };
    std::stack<std::pair<moves::Move, board::PieceColor>> m_completedMoves{};
};
} // namespace sablefish

#endif // GAME_HPP
