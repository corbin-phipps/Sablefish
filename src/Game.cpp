#include <sablefish/Game.hpp>

#include <stdexcept>

using namespace sablefish;
using namespace sablefish::board;
using namespace sablefish::moves;

/* constructor */
Game::Game() :
    m_board(std::make_shared<Board>())
{
}

/* public */

std::shared_ptr<Board>
Game::GetBoard() const
{
    return m_board;
}

Player
Game::GetPlayer(const PieceColor pieceColor) const
{
    if (pieceColor == PieceColor::White) {
        return m_whitePlayer;
    } else if (pieceColor == PieceColor::Black) {
        return m_blackPlayer;
    } else {
        throw std::invalid_argument("Invalid PieceColor");
    }
}

std::pair<Move, PieceColor>
Game::GetLastMove() const
{
    if (!m_completedMoves.empty()) {
        return m_completedMoves.top();
    } else {
        throw std::runtime_error("No completed moves");
    }
}
