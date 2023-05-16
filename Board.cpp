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

Square
Board::GetSquare(BoardSquare boardSquare)
{
    return m_squares.at(static_cast<int>(boardSquare));
}

/* private */
void
Board::InitializeBitboards()
{
    m_bitboards.at(GetBitboardIndex(PieceType::Pawn, PieceColor::White)) = WHITE_PAWNS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Pawn, PieceColor::Black)) = BLACK_PAWNS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Rook, PieceColor::White)) = WHITE_ROOKS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Rook, PieceColor::Black)) = BLACK_ROOKS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Knight, PieceColor::White)) = WHITE_KNIGHTS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Knight, PieceColor::Black)) = BLACK_KNIGHTS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Bishop, PieceColor::White)) = WHITE_BISHOPS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Bishop, PieceColor::Black)) = BLACK_BISHOPS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Queen, PieceColor::White)) = WHITE_QUEENS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::Queen, PieceColor::Black)) = BLACK_QUEENS_START;
    m_bitboards.at(GetBitboardIndex(PieceType::King, PieceColor::White)) = WHITE_KING_START;
    m_bitboards.at(GetBitboardIndex(PieceType::King, PieceColor::Black)) = BLACK_KING_START;
}

void
Board::InitializeSquares()
{
    // TODO
}

int
Board::GetBitboardIndex(PieceType pieceType, PieceColor pieceColor)
{
    return (static_cast<int>(pieceType) * NUM_COLORS) + static_cast<int>(pieceColor);
}
