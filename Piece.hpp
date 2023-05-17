#pragma once

namespace sablefish::board::piece
{
enum class PieceType {
    Pawn = 0,
    Rook = 1,
    Knight = 2,
    Bishop = 3,
    Queen = 4,
    King = 5,
    Empty = 6
};

enum class PieceColor {
    White = 0,
    Black = 1,
    Empty = 2
};

// A Piece represents a chess piece, consisting of a PieceType and PieceColor.
//
// The PieceTypes are: Pawn, Rook, Knight, Bishop, Queen, and King.
// The PieceColors are: White and Black.
class Piece
{
public:
    Piece();
    Piece(PieceType pieceType, PieceColor pieceColor);

    PieceType GetPieceType();
    PieceColor GetPieceColor();

private:
    PieceType m_pieceType{ PieceType::Empty };
    PieceColor m_pieceColor{ PieceColor::Empty };
};
} // namespace sablefish::board::piece
