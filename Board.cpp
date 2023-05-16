#include "Board.hpp"

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

Bitboard
Board::GetBitboard(PieceType pieceType, PieceColor pieceColor)
{
    return m_bitboards.at(GetBitboardIndex(pieceType, pieceColor));
}

void
Board::SetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor, Bitboard bitboard)
{
    m_bitboards.at(GetBitboardIndex(pieceType, pieceColor)) = bitboard.GetBitBoard();
}

Square
Board::GetSquare(BoardSquare boardSquare)
{
    return m_squares.at(static_cast<int>(boardSquare));
}

void
Board::SetSquare(BoardSquare boardSquare, Square square)
{
    m_squares.at(static_cast<int>(boardSquare)) = square;
}

/* private */
void
Board::InitializeBitboards()
{
    SetBitboard(PieceType::Pawn, PieceColor::White, Bitboard(WHITE_PAWNS_START));
    SetBitboard(PieceType::Pawn, PieceColor::Black, Bitboard(BLACK_PAWNS_START));
    SetBitboard(PieceType::Rook, PieceColor::White, Bitboard(WHITE_ROOKS_START));
    SetBitboard(PieceType::Rook, PieceColor::Black, Bitboard(BLACK_ROOKS_START));
    SetBitboard(PieceType::Knight, PieceColor::White, Bitboard(WHITE_KNIGHTS_START));
    SetBitboard(PieceType::Knight, PieceColor::Black, Bitboard(BLACK_KNIGHTS_START));
    SetBitboard(PieceType::Bishop, PieceColor::White, Bitboard(WHITE_BISHOPS_START));
    SetBitboard(PieceType::Bishop, PieceColor::Black, Bitboard(BLACK_BISHOPS_START));
    SetBitboard(PieceType::Queen, PieceColor::White, Bitboard(WHITE_QUEENS_START));
    SetBitboard(PieceType::Queen, PieceColor::Black, Bitboard(BLACK_QUEENS_START));
    SetBitboard(PieceType::King, PieceColor::White, Bitboard(WHITE_KING_START));
    SetBitboard(PieceType::King, PieceColor::Black, Bitboard(BLACK_KING_START));
}

void
Board::InitializeSquares()
{
    // TODO: Make this more efficient
    SetSquare(BoardSquare::A1, Square(Piece(PieceType::Rook, PieceColor::White)));
    // ...remaining 63 squares
}

int
Board::GetBitboardIndex(PieceType pieceType, PieceColor pieceColor)
{
    return (static_cast<int>(pieceType) * NUM_COLORS) + static_cast<int>(pieceColor);
}
