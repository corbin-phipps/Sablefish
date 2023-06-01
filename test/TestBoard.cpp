#include "TestBoard.hpp"

using namespace sablefish::board;
using namespace sablefish::constants::bitfields;

// Clears the current TestBoard
void
TestBoard::Clear()
{
    // Clear Bitboard representation
    for (auto& bitboard : m_bitboards) {
        bitboard = EMPTY_BITBOARD;
    }

    // Clear Squares representation
    for (auto& square : m_squares) {
        square = std::move(Square());
    }
}

// Updates a Square in the current TestBoard. Used for setting up TestBoard positions
void
TestBoard::UpdateSquare(const Square& square)
{
    // Set the Square representation
    SetSquare(square);

    // Set the Bitboard representation
    auto piece = square.GetPiece();
    auto pieceBitboard = GetBitboard(piece);
    SetBit(pieceBitboard, square.GetBoardSquare());
    SetBitboard(piece, pieceBitboard);
}

// Returns a boolean representing whether or not the TestBoard is empty.
bool
TestBoard::IsEmpty()
{
    // Check Bitboards
    for (const auto& [pieceType, pieceData] : PIECE_DATA) {
        if (GetBitboard({ pieceType, pieceData }) != EMPTY_BITBOARD) {
            return false;
        }
    }

    // Check Squares
    Square emptySquare = Square();
    for (size_t i = 0; i < NUM_SQUARES; i++) {
        if (GetSquare(static_cast<BoardSquare>(i)) != emptySquare) {
            return false;
        }
    }

    return true;
}
