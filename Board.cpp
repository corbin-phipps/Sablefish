#include "Board.hpp"

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

namespace sablefish::board
{
/* constructor */
Board::Board() :
    m_bitboards{}
{
    InitializeBitboards();
}

/* public */
Bitboard
Board::GetBitboard(PieceType pieceType, PieceColor pieceColor)
{
    return m_bitboards.at(GetBitboardIndex(pieceType, pieceColor));
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

int
Board::GetBitboardIndex(PieceType pieceType, PieceColor pieceColor)
{
    return (static_cast<int>(pieceType) * NUM_COLORS) + static_cast<int>(pieceColor);
}
} // namespace sablefish::board
