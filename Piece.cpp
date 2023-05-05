#include "Piece.hpp"

namespace sablefish::board::piece
{
/* constructors */
Piece::Piece() :
    m_pieceType(PieceType::Empty),
    m_pieceColor(PieceColor::Empty)
{
}

Piece::Piece(PieceType pieceType, PieceColor pieceColor) :
    m_pieceType(pieceType),
    m_pieceColor(pieceColor)
{
}

/* public */
PieceType
Piece::GetPieceType()
{
    return m_pieceType;
}

PieceColor
Piece::GetPieceColor()
{
    return m_pieceColor;
}
} // namespace sablefish::board::piece
