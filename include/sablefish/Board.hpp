#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <string>

#include "Bitboard.hpp"
#include "Constants.hpp"
#include "Move.hpp"
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

    Bitboard GetBitboard(const Piece& piece) const;
    Bitboard GetBitboard(const PieceType pieceType, const PieceColor pieceColor) const;
    const Square& GetSquare(const BoardSquare boardSquare) const;

    void UpdateBoard(const sablefish::moves::Move move, const PieceColor pieceColor);

    const std::string ToString();

private:
    void Initialize();

    void InitializeBitboards();
    void InitializeSquares();

    const size_t GetBitboardIndex(const Piece& piece) const;

protected:
    void SetBitboard(const Piece& piece, const Bitboard bitboard);
    void SetSquare(const Square& square);
    void ClearSquare(const BoardSquare boardSquare);

    std::array<Bitboard, constants::NUM_PIECE_TYPES * constants::NUM_COLORS> m_bitboards{};
    std::array<Square, constants::NUM_SQUARES> m_squares{};
};
} // namespace sablefish::board

#endif // BOARD_HPP
