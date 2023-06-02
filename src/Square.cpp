#include <sablefish/Square.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;

/* constructors */

// Default constructor for an empty Square.
Square::Square() :
    m_piece(Piece()),
    m_isOccupied(false)
{
}

// Constructs a Square with a given Piece.
Square::Square(const Piece& piece, const BoardSquare boardSquare) :
    m_boardSquare(boardSquare),
    m_piece(piece)
{
    m_isOccupied = piece.GetPieceType() != PieceType::Empty;
}

/* public */

// Returns the BoardSquare of the current Square instance.
const BoardSquare
Square::GetBoardSquare() const
{
    return m_boardSquare;
}

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

// Returns a string representation of a Square.
const std::string
Square::ToString() const
{
    std::string squareString = "Square:\n";
    squareString += "BoardSquare: " + sablefish::board::ToString(m_boardSquare) + "\n";
    squareString += m_piece.ToString() + "\n";
    squareString += "Occupied: " + std::to_string(m_isOccupied);

    return squareString;
}

bool
Square::operator==(const Square& other) const {
    return m_boardSquare == other.m_boardSquare && m_piece == other.m_piece && m_isOccupied == other.m_isOccupied;
}
