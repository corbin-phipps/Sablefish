#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Bitboard.hpp"
#include "Piece.hpp"

namespace sablefish::board
{
enum class BoardSquare {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
};

constexpr size_t operator-(const BoardSquare& lhs, const BoardSquare& rhs) {
    return static_cast<size_t>(lhs) - static_cast<size_t>(rhs);
}

constexpr size_t operator<<(const BoardSquare& lhs, int shift) {
    return static_cast<size_t>(lhs) << shift;
}

constexpr Bitboard operator<<(Bitboard lhs, const BoardSquare& rhs) {
    return lhs << static_cast<Bitboard>(rhs);
}

// A Square represents an individual square in a chess board and is used in one of the Board representations.
//
// Each Square contains a Piece object. A Square is "occupied" if the Square's Piece is not Piece::Empty.
class Square
{
public:
    Square() = default;
    Square(const Piece& piece, const BoardSquare boardSquare);

    const BoardSquare GetBoardSquare() const;
    const Piece& GetPiece() const;
    bool IsOccupied() const;

    const std::string ToString() const;

    bool operator==(const Square& other) const;

private:
    BoardSquare m_boardSquare{};
    Piece m_piece{};
    bool m_isOccupied{ false };
};
} // namespace sablefish::board

#endif // SQUARE_HPP
