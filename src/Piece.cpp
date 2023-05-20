#include <sablefish/Piece.hpp>

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
Piece::GetPieceType() const
{
    return m_pieceType;
}

// Returns the PieceColor of the current Piece instance.
PieceColor
Piece::GetPieceColor() const
{
    return m_pieceColor;
}

bool
Piece::operator==(const Piece& other) const {
    return m_pieceType == other.m_pieceType && m_pieceColor == other.m_pieceColor;
}
