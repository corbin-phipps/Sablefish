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
        Bitboard pieceBitboard = m_board->GetBitboard(pieceType, pieceColor);

        // Generate moves for each piece of the current PieceType and PieceColor
        while (pieceBitboard != EMPTY_BITBOARD) {
            BoardSquare square = PopLsb(pieceBitboard);

            // Generate target Bitboard for the current piece, not including pawn captures
            switch (pieceType) {
                case PieceType::Pawn:
                    GeneratePseudoLegalPawnMoves(pieceColor, square, pseudoLegalMoves);
                    break;
                case PieceType::Rook:
                    GeneratePseudoLegalRookMoves(pieceColor, square, pseudoLegalMoves);
                    break;
                case PieceType::Knight:
                    GeneratePseudoLegalKnightMoves(pieceColor, square, pseudoLegalMoves);
                    break;
                case PieceType::Bishop:
                    GeneratePseudoLegalBishopMoves(pieceColor, square, pseudoLegalMoves);
                    break;
                case PieceType::Queen:
                    GeneratePseudoLegalQueenMoves(pieceColor, square, pseudoLegalMoves);
                    break;
                case PieceType::King:
                    GeneratePseudoLegalKingMoves(pieceColor, square, pseudoLegalMoves);
                    break;
                default:
                    // TODO: Log error
                    break;
            }
        }
    }

    return pseudoLegalMoves;
}

/* private */

// Generates the pseudo-legal moves for Pawns on the given square
void
MoveGenerator::GeneratePseudoLegalPawnMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves)
{
    PieceType pieceType{ PieceType::Pawn };
    Bitboard targets;
    auto square = static_cast<size_t>(startingSquare);

    // Generate target squares for capture moves
    if (pieceColor == PieceColor::White) {
        targets = PAWN_CAPTURE_MOVES_WHITE.at(square);
    } else if (pieceColor == PieceColor::Black) {
        targets = PAWN_CAPTURE_MOVES_BLACK.at(square);
    } else {
        // TODO: Log error
    }

    // Create capture moves
    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Capture;                                  // Default MoveType is Capture
        const auto& attackedSquare = m_board->GetSquare(targetSquare);
        if (attackedSquare.IsOccupied()) {
            if (IsPromotion({ pieceType, pieceColor }, targetSquare)) {
                moveType = MoveType::QueenPromotionCapture;                     // Queen Promotion-Capture
            }

            pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
        } else {
            // TODO: En passant - attackedSquare is not occupied but the opponent's previous move must be a double pawn push landing directly next to this pawn
        }
    }

    // Generate target squares for non-capture moves
    if (pieceColor == PieceColor::White) {
        targets = PAWN_NON_CAPTURE_MOVES_WHITE.at(square);
    } else if (pieceColor == PieceColor::Black) {
        targets = PAWN_NON_CAPTURE_MOVES_BLACK.at(square);
    } else {
        // TODO: Log error
    }

    // Create non-capture moves
    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Quiet;                                    // Default MoveType is Quiet
        const auto& attackedSquare = m_board->GetSquare(targetSquare);
        if (!attackedSquare.IsOccupied()) {
            if (IsPromotion({ pieceType, pieceColor }, targetSquare)) {
                moveType = MoveType::QueenPromotion;                            // Queen Promotion
            } else {
                if (pieceColor == PieceColor::White && (targetSquare - startingSquare == NUM_FILES * 2) ||
                    pieceColor == PieceColor::Black && (startingSquare - targetSquare == NUM_FILES * 2)) {
                    moveType = MoveType::DoublePawnPush;                        // Double Pawn Push
                }
            }

            pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
        }
    }
}

// Generates the pseudo-legal moves for Rooks on the given square
void
MoveGenerator::GeneratePseudoLegalRookMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves)
{
    PieceType pieceType{ PieceType::Rook };
    auto square = static_cast<size_t>(startingSquare);
    Bitboard targets = ROOK_MOVES.at(square);

    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Quiet;
        const auto& attackedSquare = m_board->GetSquare(targetSquare);

        // Construct Move based on its MoveType
        if (attackedSquare.IsOccupied()) {
            moveType = MoveType::Capture;
        }

        pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
    }
}

// Generates the pseudo-legal moves for Knights on the given square
void
MoveGenerator::GeneratePseudoLegalKnightMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves)
{
    PieceType pieceType{ PieceType::Knight };
    auto square = static_cast<size_t>(startingSquare);
    Bitboard targets = KNIGHT_MOVES.at(square);

    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Quiet;
        const auto& attackedSquare = m_board->GetSquare(targetSquare);

        // Construct Move based on its MoveType
        if (attackedSquare.IsOccupied()) {
            moveType = MoveType::Capture;
        }

        pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
    }
}

// Generates the pseudo-legal moves for Bishops on the given square
void
MoveGenerator::GeneratePseudoLegalBishopMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves)
{
    PieceType pieceType{ PieceType::Bishop };
    auto square = static_cast<size_t>(startingSquare);
    Bitboard targets = BISHOP_MOVES.at(square);

    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Quiet;
        const auto& attackedSquare = m_board->GetSquare(targetSquare);

        // Construct Move based on its MoveType
        if (attackedSquare.IsOccupied()) {
            moveType = MoveType::Capture;
        }

        pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
    }
}

// Generates the pseudo-legal moves for Queens on the given square
void
MoveGenerator::GeneratePseudoLegalQueenMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves)
{
    PieceType pieceType{ PieceType::Queen };
    auto square = static_cast<size_t>(startingSquare);
    Bitboard targets = QUEEN_MOVES.at(square);

    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Quiet;
        const auto& attackedSquare = m_board->GetSquare(targetSquare);

        // Construct Move based on its MoveType
        if (attackedSquare.IsOccupied()) {
            moveType = MoveType::Capture;
        }

        pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
    }
}

// Generates the pseudo-legal moves for Kings on the given square
void
MoveGenerator::GeneratePseudoLegalKingMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves)
{
    PieceType pieceType{ PieceType::King };
    auto square = static_cast<size_t>(startingSquare);
    Bitboard targets = KING_MOVES.at(square);

    // TODO: Kingside/Queenside Castling moves are missing
    while (targets != EMPTY_BITBOARD) {
        BoardSquare targetSquare = PopLsb(targets);
        MoveType moveType = MoveType::Quiet;
        const auto& attackedSquare = m_board->GetSquare(targetSquare);

        // Construct Move based on its MoveType
        if (attackedSquare.IsOccupied()) {
            moveType = MoveType::Capture;
        }

        pseudoLegalMoves.push_back(CreateMove(startingSquare, targetSquare, moveType));
    }
}
