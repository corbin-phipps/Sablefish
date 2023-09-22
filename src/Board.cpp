#include <sablefish/Board.hpp>
#include <sablefish/Utilities.hpp>

#include <iostream>

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::moves;

/* constructor */

// Default constructor for a Board that also initializes it.
Board::Board()
{
    Initialize();
}

/* public */

// Given a Piece, returns the appropriate Bitboard.
const Bitboard
Board::GetBitboard(const Piece& piece) const
{
    return m_bitboards.at(GetBitboardIndex(piece));
}

// Given a BoardSquare, returns the appropriate Square in the Board.
const Square&
Board::GetSquare(const BoardSquare boardSquare) const
{
    return m_squares.at(static_cast<size_t>(boardSquare));
}

// Given a valid Move and PieceColor, update the Board accordingly.
void
Board::UpdateBoard(const sablefish::moves::Move move, const PieceColor pieceColor)
{
    std::tuple<BoardSquare, BoardSquare, MoveType> moveData = GetMoveData(move);
    // TODO: Update board
}

// Displays the current Board
const std::string
Board::ToString()
{
    std::string boardString;
    for (int rank = NUM_RANKS - 1; rank >= 0; rank--) {
        for (int file = 0; file < NUM_FILES; file++) {
            Square square = m_squares.at(rank * 8 + file);
            char squareChar = '-';
            switch (square.GetPiece().GetPieceColor()) {
                case PieceColor::White:
                    switch (square.GetPiece().GetPieceType()) {
                        case PieceType::Pawn:
                            squareChar = 'P';
                            break;
                        case PieceType::Rook:
                            squareChar = 'R';
                            break;
                        case PieceType::Knight:
                            squareChar = 'N';
                            break;
                        case PieceType::Bishop:
                            squareChar = 'B';
                            break;
                        case PieceType::Queen:
                            squareChar = 'Q';
                            break;
                        case PieceType::King:
                            squareChar = 'K';
                            break;
                        default:
                            squareChar = '-';
                            break;
                    }
                    break;
                case PieceColor::Black:
                    switch (square.GetPiece().GetPieceType()) {
                        case PieceType::Pawn:
                            squareChar = 'p';
                            break;
                        case PieceType::Rook:
                            squareChar = 'r';
                            break;
                        case PieceType::Knight:
                            squareChar = 'n';
                            break;
                        case PieceType::Bishop:
                            squareChar = 'b';
                            break;
                        case PieceType::Queen:
                            squareChar = 'q';
                            break;
                        case PieceType::King:
                            squareChar = 'k';
                            break;
                        default:
                            squareChar = '-';
                            break;
                    }
                    break;
                default:
                    squareChar = '-';
                    break;
            }
            boardString += squareChar;
        }
        boardString += '\n';
    }

    return boardString;
}

/* private */

// Initializes both representations of the Board.
void
Board::Initialize()
{
    InitializeBitboards();
    InitializeSquares();
}

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
    // Set Squares for actual Pieces
    for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
        auto piece = Piece(pieceType, pieceColor);
        std::vector<BoardSquare> boardSquares = ConvertBitboardToBoardSquares(GetBitboard(piece));
        for (const auto& boardSquare : boardSquares) {
            SetSquare(Square(piece, boardSquare));
        }
    }

    // Set empty Squares
    Bitboard startingEmptyRanks = bitfields::RANK_3 | bitfields::RANK_4 | bitfields::RANK_5 | bitfields::RANK_6;
    std::vector<BoardSquare> boardSquares = ConvertBitboardToBoardSquares(startingEmptyRanks);
    for (const auto& boardSquare : boardSquares) {
        SetSquare(Square({ PieceType::Empty, PieceColor::Empty }, boardSquare));
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

/* protected */

// Given a Piece and a Bitboard, sets the appropriate Bitboard.
void
Board::SetBitboard(const Piece& piece, const Bitboard bitboard)
{
    m_bitboards.at(GetBitboardIndex(piece)) = bitboard;
}

// Given a BoardSquare and a Square, sets the appropriate Square in the Board.
void
Board::SetSquare(const Square& square)
{
    m_squares.at(static_cast<size_t>(square.GetBoardSquare())) = square;
}
