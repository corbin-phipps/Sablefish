#ifndef MOVE_GENERATOR_HPP
#define MOVE_GENERATOR_HPP

#include "Bitboard.hpp"
#include "Square.hpp"

namespace sablefish::moves
{
class MoveGenerator
{
public:
    MoveGenerator() = default;

    const Bitboard GeneratePseudoLegalMoves(const sablefish::board::Square& square, const Bitboard playerPiecesBitboard);

private:

};
} // namespace sablefish::moves

#endif // MOVE_GENERATOR_HPP
