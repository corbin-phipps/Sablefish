#include <sablefish/Constants.hpp>
#include <sablefish/Piece.hpp>

using namespace sablefish::board;
using namespace sablefish::constants;

/* constructors */

// Default constructor for a Piece object. Represents a non-existent Piece.
Piece::Piece() :
    m_pieceType(PieceType::Empty),
    m_pieceColor(PieceColor::Empty)
{
}

// Constructs a Piece with the given PieceType and PieceColor.
Piece::Piece(const PieceType pieceType, const PieceColor pieceColor) :
    m_pieceType(pieceType),
    m_pieceColor(pieceColor)
{
}

/* public */

// Returns the PieceType of the current Piece instance.
const PieceType
Piece::GetPieceType() const
{
    return m_pieceType;
}

// Returns the PieceColor of the current Piece instance.
const PieceColor
Piece::GetPieceColor() const
{
    return m_pieceColor;
}

// Returns the string representation of a Piece.
const std::string
Piece::ToString()
{
    std::string pieceTypeString;
    switch (m_pieceType) {
        case PieceType::Pawn:
            pieceTypeString = "Pawn";
            break;
        case PieceType::Rook:
            pieceTypeString = "Rook";
            break;
        case PieceType::Knight:
            pieceTypeString = "Knight";
            break;
        case PieceType::Bishop:
            pieceTypeString = "Bishop";
            break;
        case PieceType::Queen:
            pieceTypeString = "Queen";
            break;
        case PieceType::King:
            pieceTypeString = "King";
            break;
        default:
            pieceTypeString = "Empty";
            break;
    }

    std::string pieceColorString;
    switch (m_pieceColor) {
        case PieceColor::White:
            pieceColorString = "White";
            break;
        case PieceColor::Black:
            pieceColorString = "Black";
            break;
        default:
            pieceColorString = "Empty";
            break;
    }

    return "Piece Type: " + pieceTypeString + "\nPiece Color: " + pieceColorString + "\n";
}

bool
Piece::operator==(const Piece& other) const {
    return m_pieceType == other.m_pieceType && m_pieceColor == other.m_pieceColor;
}
