#include <sablefish/Player.hpp>

using namespace sablefish;
using namespace sablefish::board;

/* constructor */

Player::Player(const PieceColor playerPieceColor, std::shared_ptr<Board> board) :
    m_playerPieceColor(playerPieceColor),
    m_board(board),
    m_playerPiecesBitboard(CalculatePlayerPiecesBitboard())
{
}

/* public */

const PieceColor
Player::GetPlayerPieceColor() const
{
    return m_playerPieceColor;
}

const size_t
Player::GetCompletedMovesCount() const
{
    return m_completedMoves.size();
}

std::shared_ptr<board::Board>
Player::GetBoard() const
{
    return m_board;
}

const Bitboard
Player::GetPlayerPiecesBitboard()
{
    return CalculatePlayerPiecesBitboard();
}

/* private */

const Bitboard
Player::CalculatePlayerPiecesBitboard()
{
    Bitboard playerPiecesBitboard = 0ULL;
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        if (pieceColor == m_playerPieceColor) {
            playerPiecesBitboard |= m_board->GetBitboard(pieceType, pieceColor);
        }
    }

    return playerPiecesBitboard;
}
