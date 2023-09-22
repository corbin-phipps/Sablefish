#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <stack>

#include "Bitboard.hpp"
#include "Board.hpp"
#include "Move.hpp"
#include "MoveGenerator.hpp"
#include "Piece.hpp"

namespace sablefish
{
class Player
{
public:
    Player(const board::PieceColor playerPieceColor, std::shared_ptr<board::Board> board, std::shared_ptr<moves::MoveGenerator> moveGenerator);

    const board::PieceColor GetPlayerPieceColor() const;
    const size_t GetCompletedMovesCount() const;
    std::shared_ptr<board::Board> GetBoard() const;
    const Bitboard GetPlayerPiecesBitboard() const;

    void PlayMove(sablefish::moves::Move move);

private:
    const Bitboard CalculatePlayerPiecesBitboard() const;

    board::PieceColor m_playerPieceColor{};
    std::stack<sablefish::moves::Move> m_completedMoves{};
    std::shared_ptr<board::Board> m_board{};
    std::shared_ptr<moves::MoveGenerator> m_moveGenerator{};
    Bitboard m_playerPiecesBitboard{};
};
}

#endif // PLAYER_HPP
