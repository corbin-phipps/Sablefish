#include <sablefish/Board.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
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

// Given a Piece, returns the appropriate Bitboard.
const Bitboard
Board::GetBitboard(const Piece& piece) const
{
    return m_bitboards.at(GetBitboardIndex(piece));
}

// Given a Piece and a Bitboard, sets the appropriate Bitboard.
void
Board::SetBitboard(const Piece& piece, const Bitboard bitboard)
{
    m_bitboards.at(GetBitboardIndex(piece)) = bitboard;
}

// Given a BoardSquare, returns the appropriate Square in the Board.
const Square&
Board::GetSquare(const BoardSquare boardSquare) const
{
    return m_squares.at(static_cast<size_t>(boardSquare));
}

// Given a BoardSquare and a Square, sets the appropriate Square in the Board.
void
Board::SetSquare(const Square& square)
{
    m_squares.at(static_cast<size_t>(square.GetBoardSquare())) = square;
}

// Clears the current Board
void
Board::Clear()
{
    // Clear Bitboard representation
    for (auto& bitboard : m_bitboards) {
        bitboard = EMPTY_BITBOARD;
    }

    // Clear Squares representation
    for (auto& square : m_squares) {
        square = std::move(Square());
    }
}

/* private */

// Initializes all Bitboards in the Board to the starting positions of each Piece.
void
Board::InitializeBitboards()
{
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        SetBitboard({ pieceType, pieceColor }, ConvertPieceDataToStartingBitboard(pieceType, pieceColor));
    }
}

// Initializes all Squares in the Board to the starting positions of each Piece.
void
Board::InitializeSquares()
{
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        auto piece = Piece(pieceType, pieceColor);
        std::vector<BoardSquare> boardSquares = ConvertBitboardToBoardSquares(GetBitboard(piece));
        for (const auto& boardSquare : boardSquares) {
            SetSquare(Square(piece, boardSquare));
        }
    }
}

// Given a Piece, returns the index of the appropriate Bitboard.
const size_t
Board::GetBitboardIndex(const Piece& piece) const
{
    auto pieceType = static_cast<size_t>(piece.GetPieceType());
    auto pieceColor = static_cast<size_t>(piece.GetPieceColor());

    return (pieceType * NUM_COLORS) + pieceColor;
}
