#include <sablefish/Player.hpp>

using namespace sablefish;
using namespace sablefish::board;

/* constructor */

// Constructs a Player object with the given PieceColor and shared Board.
Player::Player(const PieceColor playerPieceColor, std::shared_ptr<Board> board) :
    m_playerPieceColor(playerPieceColor),
    m_board(board),
    m_playerPiecesBitboard(CalculatePlayerPiecesBitboard())
{
}

/* public */

// Returns the PieceColor of the current Player instance.
const PieceColor
Player::GetPlayerPieceColor() const
{
    return m_playerPieceColor;
}

// Returns the number of completed moves by the current Player instance.
const size_t
Player::GetCompletedMovesCount() const
{
    return m_completedMoves.size();
}

// Returns the Board shared by the current Player instance.
std::shared_ptr<board::Board>
Player::GetBoard() const
{
    return m_board;
}

// Returns the current Bitboard of all of the current Player's pieces.
const Bitboard
Player::GetPlayerPiecesBitboard()
{
    return CalculatePlayerPiecesBitboard();
}

/* private */

// Returns a Bitboard of all of the current Player's pieces on the shared Board.
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
