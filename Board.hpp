#pragma once

#include <array>

#include "Bitboard.hpp"
#include "Constants.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::board
{
// A Board represents an 8 x 8 chess board and contains two board state representations.
// These include an array of 12 Bitboards (one for each PieceType and PieceColor combination) and an array of 64 Squares.
//
// The Bitboard representation is used for most operations, utilizing the efficiency of bitwise operations.
//
// The array of Squares representation is used for operations where Bitboards are inconvenient. Most notably, determining
// if a particular Square contains a particular Piece.
class Board
{
public:
    Board();

    void Initialize();
    const Bitboard& GetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor);
    void SetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor, const Bitboard& bitboard);
    const Square& GetSquare(BoardSquare boardSquare);
    void SetSquare(BoardSquare boardSquare, const Square& square);

private:
    void InitializeBitboards();
    void InitializeSquares();
    int GetBitboardIndex(piece::PieceType pieceType, piece::PieceColor pieceColor);

    std::array<Bitboard, constants::NUM_PIECE_TYPES * constants::NUM_COLORS> m_bitboards{};
    std::array<Square, constants::NUM_SQUARES> m_squares{};
};
} // namespace sablefish::board
