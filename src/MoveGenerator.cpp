#include <sablefish/MoveGenerator.hpp>
#include <sablefish/Constants.hpp>

using namespace sablefish::board;
using namespace sablefish::moves;

/* public */

// Returns a Bitboard of the generated pseudo-legal moves based on the given Square
// and the given Bitboard of the current Player's pieces.
//
// TODO: This function currently generates the basic moves by each PieceType (excluding Pawns).
// It should be updated to include Pawns, as well as special moves such as Double Pawn Pushes,
// En Passant, Promotions, and Castling.
//
// TODO: This function currently returns a Bitboard of moves, but it should return a std::vector<Move>, 
// with the proper Move encoding. This means that we should also take in a Bitboard of ALL pieces on the
// Board, so we can determine if a capture is made.
const Bitboard
MoveGenerator::GeneratePseudoLegalMoves(const Square& square, const Bitboard playerPiecesBitboard)
{
    Bitboard attacks;
    auto pieceType = square.GetPiece().GetPieceType();
    auto boardSquare = static_cast<size_t>(square.GetBoardSquare());

    switch (pieceType) {
        case PieceType::Pawn:
            // TODO: Fix once implemented
            attacks = 0ULL;
            break;
        case PieceType::Rook:
            attacks = ROOK_MOVES.at(boardSquare);
            break;
        case PieceType::Knight:
            attacks = KNIGHT_MOVES.at(boardSquare);
            break;
        case PieceType::Bishop:
            attacks = BISHOP_MOVES.at(boardSquare);
            break;
        case PieceType::Queen:
            attacks = QUEEN_MOVES.at(boardSquare);
            break;
        case PieceType::King:
            attacks = KING_MOVES.at(boardSquare);
            break;
        default:
            // TODO: Log error
            attacks = 0ULL;
            break;
    }

    return attacks & ~playerPiecesBitboard;
}
