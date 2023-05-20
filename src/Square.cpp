#include <sablefish/Square.hpp>

using namespace sablefish::board;
using namespace sablefish::board::piece;

/* constructors */

// Default constructor for an empty Square.
Square::Square() :
    m_piece(Piece()),
    m_isOccupied(false)
{
}

// Constructs a Square with a given Piece.
Square::Square(const Piece& piece) :
    m_piece(piece)
{
    m_isOccupied = piece.GetPieceType() != PieceType::Empty;
}

/* public */

// Returns the Piece occupying the current Square instance.
const Piece&
Square::GetPiece() const
{
    return m_piece;
}

// Returns a boolean representing whether or not the Square is occupied.
bool
Square::IsOccupied() const
{
    return m_isOccupied;
}

bool
Square::operator==(const Square& other) const {
    return m_piece == other.m_piece && m_isOccupied == other.m_isOccupied;
}
