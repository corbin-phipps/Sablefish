#include "Square.hpp"

using namespace sablefish::board;
using namespace sablefish::board::piece;

/* constructors */
Square::Square() :
    m_piece(Piece()),
    m_isOccupied(false)
{
}

Square::Square(const Piece& piece) :
    m_piece(piece),
    m_isOccupied(true)
{
}

/* public */
const Piece&
Square::GetPiece()
{
    return m_piece;
}

bool
Square::IsOccupied()
{
    return m_isOccupied;
}
