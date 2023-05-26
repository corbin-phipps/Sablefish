#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <stack>

#include "Bitboard.hpp"
#include "Board.hpp"
#include "Move.hpp"
#include "Piece.hpp"

namespace sablefish
{
class Player
{
public:
    Player(const board::PieceColor playerPieceColor, std::shared_ptr<board::Board> board);

    const board::PieceColor GetPlayerPieceColor() const;
    const size_t GetCompletedMovesCount() const;
    std::shared_ptr<board::Board> GetBoard() const;
    const Bitboard GetPlayerPiecesBitboard();

private:
    const Bitboard CalculatePlayerPiecesBitboard();

    board::PieceColor m_playerPieceColor{};
    std::stack<sablefish::moves::Move> m_completedMoves{};
    std::shared_ptr<board::Board> m_board{};
    Bitboard m_playerPiecesBitboard{};
};
}

#endif // PLAYER_HPP
