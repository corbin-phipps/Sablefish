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

Bitboard
Board::GetBitboard(PieceType pieceType, PieceColor pieceColor)
{
    return m_bitboards.at(GetBitboardIndex(pieceType, pieceColor));
}

void
Board::SetBitboard(piece::PieceType pieceType, piece::PieceColor pieceColor, Bitboard bitboard)
{
    m_bitboards.at(GetBitboardIndex(pieceType, pieceColor)) = bitboard.GetBitboard();
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
    std::vector<BoardSquare> whitePawnsBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Pawn, PieceColor::White));
    std::vector<BoardSquare> blackPawnsBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Pawn, PieceColor::Black));
    std::vector<BoardSquare> whiteRookBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Rook, PieceColor::White));
    std::vector<BoardSquare> blackRookBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Rook, PieceColor::Black));
    std::vector<BoardSquare> whiteKnightBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Knight, PieceColor::White));
    std::vector<BoardSquare> blackKnightBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Knight, PieceColor::Black));
    std::vector<BoardSquare> whiteBishopBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Bishop, PieceColor::White));
    std::vector<BoardSquare> blackBishopBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Bishop, PieceColor::Black));
    std::vector<BoardSquare> whiteQueenBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Queen, PieceColor::White));
    std::vector<BoardSquare> blackQueenBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::Queen, PieceColor::Black));
    std::vector<BoardSquare> whiteKingBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::King, PieceColor::White));
    std::vector<BoardSquare> blackKingBoardSquares = ConvertBitboardToBoardSquares(GetBitboard(PieceType::King, PieceColor::Black));

    for (const auto& boardSquare : whitePawnsBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Pawn, PieceColor::White)));
    }
    for (const auto& boardSquare : blackPawnsBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Pawn, PieceColor::Black)));
    }
    for (const auto& boardSquare : whiteRookBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Rook, PieceColor::White)));
    }
    for (const auto& boardSquare : blackRookBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Rook, PieceColor::Black)));
    }
    for (const auto& boardSquare : whiteKnightBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Knight, PieceColor::White)));
    }
    for (const auto& boardSquare : blackKnightBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Knight, PieceColor::Black)));
    }
    for (const auto& boardSquare : whiteBishopBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Bishop, PieceColor::White)));
    }
    for (const auto& boardSquare : blackBishopBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Bishop, PieceColor::Black)));
    }
    for (const auto& boardSquare : whiteQueenBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Queen, PieceColor::White)));
    }
    for (const auto& boardSquare : blackQueenBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::Queen, PieceColor::Black)));
    }
    for (const auto& boardSquare : whiteKingBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::King, PieceColor::White)));
    }
    for (const auto& boardSquare : blackKingBoardSquares) {
        SetSquare(boardSquare, Square(Piece(PieceType::King, PieceColor::Black)));
    }
}

int
Board::GetBitboardIndex(PieceType pieceType, PieceColor pieceColor)
{
    return (static_cast<int>(pieceType) * NUM_COLORS) + static_cast<int>(pieceColor);
}
