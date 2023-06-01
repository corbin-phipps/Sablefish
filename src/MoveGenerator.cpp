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
        auto pieceType = static_cast<PieceType>(i);
        Bitboard pieceBitboard = m_board->GetBitboard({ pieceType, pieceColor });

        // Generate moves for each piece of the current PieceType and PieceColor
        while (pieceBitboard != EMPTY_BITBOARD) {
            Bitboard targets;
            BoardSquare pieceSquare = PopLsb(pieceBitboard);
            auto square = static_cast<size_t>(pieceSquare);
            
            // Generate target Bitboard for the current piece
            switch (pieceType) {
                case PieceType::Pawn:
                    // TODO: Fix once implemented
                    targets = 0ULL;
                    break;
                case PieceType::Rook:
                    targets = ROOK_MOVES.at(square);
                    break;
                case PieceType::Knight:
                    targets = KNIGHT_MOVES.at(square);
                    break;
                case PieceType::Bishop:
                    targets = BISHOP_MOVES.at(square);
                    break;
                case PieceType::Queen:
                    targets = QUEEN_MOVES.at(square);
                    break;
                case PieceType::King:
                    targets = KING_MOVES.at(square);
                    break;
                default:
                    // TODO: Log error
                    targets = 0ULL;
                    break;
            }

            // Construct Moves based on current piece's square and the potential target squares
            //
            // TODO: Promotion piece is Queen by default, but this should be configurable
            // TODO: Some MoveTypes are missing: Double Pawn Push, King/Queen Castle, En Passant
            while (targets != EMPTY_BITBOARD) {
                BoardSquare targetSquare = PopLsb(targets);
                MoveType moveType = MoveType::Quiet;                                                    // Default MoveType is Quiet
                const auto& attackedSquare = m_board->GetSquare(targetSquare);

                // Construct Move based on its MoveType
                if (!attackedSquare.IsOccupied()) {
                    if (IsPromotion({ pieceType, pieceColor }, targetSquare)) {
                        moveType = MoveType::QueenPromotion;                                            // Queen Promotion
                    }
                } else {
                    if (IsPromotion({ pieceType, pieceColor }, targetSquare)) {
                        moveType = MoveType::QueenPromotionCapture;                                     // Queen Promotion-Capture
                    } else if (attackedSquare.GetPiece().GetPieceColor() != pieceColor) {
                        moveType = MoveType::Capture;                                                   // Capture
                    }
                }

                pseudoLegalMoves.push_back(CreateMove(pieceSquare, targetSquare, moveType));
            }
        }
    }

    return pseudoLegalMoves;
}
