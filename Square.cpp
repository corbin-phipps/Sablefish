#include "Square.hpp"

using namespace sablefish::board;
using namespace sablefish::board::piece;

/* constructors */
Square::Square() :
    m_piece(Piece()),
    m_isOccupied(false)
{
}

Square::Square(Piece piece) :
    m_piece(piece),
    m_isOccupied(true)
{
}

/* public */
Piece
Square::GetPiece()
{
    return m_piece;
}

bool
Square::IsOccupied()
{
    return m_isOccupied;
}
