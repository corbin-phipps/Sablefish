#include <sablefish/Player.hpp>

using namespace sablefish;
using namespace sablefish::board;

/* constructor */

Player::Player(const PieceColor pieceColor) :
    m_pieceColor(pieceColor)
{
}

/* public */

const PieceColor
Player::GetPlayerPieceColor() const
{
    return m_pieceColor;
}

const size_t
Player::GetCompletedMovesCount() const
{
    return m_completedMoves.size();
}
