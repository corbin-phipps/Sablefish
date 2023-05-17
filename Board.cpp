#include "Board.hpp"
#include "Utilities.hpp"

using namespace sablefish::board;
using namespace sablefish::board::piece;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

/* constructor */
Board::Board() :
    m_bitboards{},
    m_squares{}
{
    Initialize();
}

/* public */
void
Board::Initialize()
{
    InitializeBitboards();
    InitializeSquares();
}

const Bitboard&
Board::GetBitboard(PieceType pieceType, PieceColor pieceColor)
{
    return m_bitboards.at(GetBitboardIndex(pieceType, pieceColor));
}

void
Board::SetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor, const Bitboard& bitboard)
{
    m_bitboards.at(GetBitboardIndex(pieceType, pieceColor)) = bitboard.GetBitboard();
}

const Square&
Board::GetSquare(BoardSquare boardSquare)
{
    return m_squares.at(static_cast<int>(boardSquare));
}

void
Board::SetSquare(BoardSquare boardSquare, const Square& square)
{
    m_squares.at(static_cast<int>(boardSquare)) = square;
}

/* private */
void
Board::InitializeBitboards()
{
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        SetBitboard(pieceType, pieceColor, ConvertPieceDataToBitboard(pieceType, pieceColor));
    }
}

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

int
Board::GetBitboardIndex(PieceType pieceType, PieceColor pieceColor)
{
    return (static_cast<int>(pieceType) * NUM_COLORS) + static_cast<int>(pieceColor);
}
