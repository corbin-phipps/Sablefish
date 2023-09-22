#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <stack>

#include "Board.hpp"
#include "Move.hpp"
#include "MoveGenerator.hpp"
#include "Player.hpp"

namespace sablefish
{
class Game
{
public:
    Game();

    std::shared_ptr<board::Board> GetBoard() const;
    std::shared_ptr<moves::MoveGenerator> GetMoveGenerator() const;
    Player GetPlayer(const board::PieceColor pieceColor) const;
    std::pair<moves::Move, board::PieceColor> GetLastMove() const;

private:
    std::shared_ptr<board::Board> m_board{};
    std::shared_ptr<moves::MoveGenerator> m_moveGenerator{};
    Player m_whitePlayer{ board::PieceColor::White, m_board, m_moveGenerator };
    Player m_blackPlayer{ board::PieceColor::Black, m_board, m_moveGenerator };
    std::stack<std::pair<moves::Move, board::PieceColor>> m_completedMoves{};
};
} // namespace sablefish

#endif // GAME_HPP
