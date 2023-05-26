#include <sablefish/MoveGenerator.hpp>
#include <sablefish/Constants.hpp>

using namespace sablefish::board;
using namespace sablefish::constants::bitfields;
using namespace sablefish::constants::functions;
using namespace sablefish::moves;

/* constructor */

MoveGenerator::MoveGenerator(std::shared_ptr<Board> board) :
    m_board(board)
{
}

/* public */

// Returns a list of pseudo-legal Moves for the given PieceColor.
std::vector<Move>
MoveGenerator::GeneratePseudoLegalMoves(const PieceColor pieceColor)
{
    std::vector<Move> pseudoLegalMoves{};

    // Generate moves for each PieceType of the given PieceColor
    for (size_t i = 0; i < static_cast<size_t>(PieceType::Empty); i++) {
        PieceType pieceType = static_cast<PieceType>(i);
        Bitboard pieceBitboard = m_board->GetBitboard(pieceType, pieceColor);

        // Generate moves for each piece of the current PieceType and PieceColor
        while (pieceBitboard != EMPTY_BITBOARD) {
            Bitboard attacks;
            BoardSquare pieceSquare = PopLsb(pieceBitboard);
            auto square = static_cast<size_t>(pieceSquare);
            
            // Generate attack Bitboard for the current piece
            switch (pieceType) {
                case PieceType::Pawn:
                    // TODO: Fix once implemented
                    attacks = 0ULL;
                    break;
                case PieceType::Rook:
                    attacks = ROOK_MOVES.at(square);
                    break;
                case PieceType::Knight:
                    attacks = KNIGHT_MOVES.at(square);
                    break;
                case PieceType::Bishop:
                    attacks = BISHOP_MOVES.at(square);
                    break;
                case PieceType::Queen:
                    attacks = QUEEN_MOVES.at(square);
                    break;
                case PieceType::King:
                    attacks = KING_MOVES.at(square);
                    break;
                default:
                    // TODO: Log error
                    attacks = 0ULL;
                    break;
            }

            // Construct Moves based on current piece's square and the potential attack squares
            //
            // TODO: Should only include moves that don't land on any pieces of the same PieceColor
            // TODO: Need to accurately set MoveType
            while (attacks != EMPTY_BITBOARD) {
                BoardSquare attackSquare = PopLsb(attacks);
                Move move = CreateMove(pieceSquare, attackSquare, MoveType::Quiet);
            }
        }
    }

    return pseudoLegalMoves;
}
