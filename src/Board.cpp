#include <sablefish/Board.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::board::piece;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

/* constructor */

// Default constructor for a Board that also initializes it.
Board::Board() :
    m_bitboards{},
    m_squares{}
{
    Initialize();
}

/* public */

// Initializes both representations of the Board.
void
Board::Initialize()
{
    InitializeBitboards();
    InitializeSquares();
}

// Given a PieceType and PieceColor, returns the appropriate Bitboard.
const Bitboard&
Board::GetBitboard(PieceType pieceType, PieceColor pieceColor)
{
    return m_bitboards.at(GetBitboardIndex(pieceType, pieceColor));
}

// Given a PieceType, PieceColor, and Bitboard, sets the appropriate Bitboard.
void
Board::SetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor, const Bitboard& bitboard)
{
    m_bitboards.at(GetBitboardIndex(pieceType, pieceColor)) = bitboard;
}

// Given a BoardSquare, returns the appropriate Square in the Board.
const Square&
Board::GetSquare(BoardSquare boardSquare)
{
    return m_squares.at(static_cast<size_t>(boardSquare));
}

// Given a BoardSquare and a Square, sets the appropriate Square in the Board.
void
Board::SetSquare(BoardSquare boardSquare, const Square& square)
{
    m_squares.at(static_cast<size_t>(boardSquare)) = square;
}

/* private */

// Initializes all Bitboards in the Board to the starting positions of each Piece.
void
Board::InitializeBitboards()
{
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        SetBitboard(pieceType, pieceColor, ConvertPieceDataToStartingBitboard(pieceType, pieceColor));
    }
}

// Initializes all Squares in the Board to the starting positions of each Piece.
void
Board::InitializeSquares()
{
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        std::vector<BoardSquare> boardSquares = ConvertBitboardToBoardSquares(GetBitboard(pieceType, pieceColor));
        for (const auto& boardSquare : boardSquares) {
            SetSquare(boardSquare, Square(Piece(pieceType, pieceColor)));
        }
    }
}

// Given a PieceType and PieceColor, returns the index of the appropriate Bitboard.
size_t
Board::GetBitboardIndex(PieceType pieceType, PieceColor pieceColor)
{
    return (static_cast<size_t>(pieceType) * NUM_COLORS) + static_cast<size_t>(pieceColor);
}
