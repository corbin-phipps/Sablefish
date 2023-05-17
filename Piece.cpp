#include "Piece.hpp"

using namespace sablefish::board::piece;

/* constructors */

// Default constructor for a Piece object. Represents a non-existent Piece.
Piece::Piece() :
    m_pieceType(PieceType::Empty),
    m_pieceColor(PieceColor::Empty)
{
}

// Constructs a Piece with the given PieceType and PieceColor.
Piece::Piece(PieceType pieceType, PieceColor pieceColor) :
    m_pieceType(pieceType),
    m_pieceColor(pieceColor)
{
}

/* public */

// Returns the PieceType of the current Piece instance.
PieceType
Piece::GetPieceType()
{
    return m_pieceType;
}

// Returns the PieceColor of the current Piece instance.
PieceColor
Piece::GetPieceColor()
{
    return m_pieceColor;
}
