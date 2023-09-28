#include <sablefish/MoveGenerator.hpp>
#include <sablefish/Player.hpp>

#include <algorithm>
#include <stdexcept>

using namespace sablefish;
using namespace sablefish::board;
using namespace sablefish::moves;

/* constructor */

// Constructs a Player object with the given PieceColor and shared Board.
Player::Player(const PieceColor playerPieceColor, std::shared_ptr<Board> board, std::shared_ptr<MoveGenerator> moveGenerator) :
    m_playerPieceColor(playerPieceColor),
    m_board(board),
    m_moveGenerator(moveGenerator),
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
Player::GetPlayerPiecesBitboard() const
{
    return CalculatePlayerPiecesBitboard();
}

// Plays the given move for the current Player.
void
Player::PlayMove(Move move)
{
    // Generate legal moves
    // TODO: Currently using pseudo-legal, update to legal
    auto pseudoLegalMoves = m_moveGenerator->GeneratePseudoLegalMoves(m_playerPieceColor);

    // Check if given move is legal
    if (std::find(pseudoLegalMoves.begin(), pseudoLegalMoves.end(), move) == pseudoLegalMoves.end()) {
        // TODO: Don't throw, return some value indicating that the given move is not legal. Perhaps rename to TryPlayMove or something
        throw std::invalid_argument("Invalid move");
    }

    // Update board and other variables
    // TODO: Need a way to update the move stack in Game
    m_board->UpdateBoard(move, m_playerPieceColor);
}

/* private */

// Returns a Bitboard of all of the current Player's pieces on the shared Board.
const Bitboard
Player::CalculatePlayerPiecesBitboard() const
{
    Bitboard playerPiecesBitboard = 0ULL;
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        if (pieceColor == m_playerPieceColor) {
            playerPiecesBitboard |= m_board->GetBitboard(pieceType, pieceColor);
        }
    }

    return playerPiecesBitboard;
}
