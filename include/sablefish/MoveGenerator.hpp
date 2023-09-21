#ifndef MOVE_GENERATOR_HPP
#define MOVE_GENERATOR_HPP

#include <memory>
#include <vector>

#include "Bitboard.hpp"
#include "Board.hpp"
#include "Move.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::moves
{
class MoveGenerator
{
public:
    MoveGenerator(std::shared_ptr<sablefish::board::Board> board);

    std::vector<Move> GeneratePseudoLegalMoves(const sablefish::board::PieceColor pieceColor);

private:
    void GeneratePseudoLegalPawnMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves);
    void GeneratePseudoLegalRookMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves);
    void GeneratePseudoLegalKnightMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves);
    void GeneratePseudoLegalBishopMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves);
    void GeneratePseudoLegalQueenMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves);
    void GeneratePseudoLegalKingMoves(const PieceColor pieceColor, const BoardSquare startingSquare, std::vector<Move>& pseudoLegalMoves);

    std::shared_ptr<sablefish::board::Board> m_board{};
};
} // namespace sablefish::moves

#endif // MOVE_GENERATOR_HPP
