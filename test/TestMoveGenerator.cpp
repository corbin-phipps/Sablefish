#include <catch2/catch.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/MoveGenerator.hpp>

using namespace sablefish::board;
using namespace sablefish::constants::bitfields;
using namespace sablefish::moves;

TEST_CASE("MoveGenerator can generate basic pseudo-legal Pawn moves") {
    MoveGenerator moveGenerator = MoveGenerator();

    // TODO
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Rook moves") {
    MoveGenerator moveGenerator = MoveGenerator();

    SECTION("Simple Rook quiet moves on empty Board") {
        Square square = Square(Piece(PieceType::Rook, PieceColor::White), BoardSquare::A1);
        auto boardSquare = 1ULL << static_cast<Bitboard>(square.GetBoardSquare());
        Bitboard piecesBitboard = EMPTY_BITBOARD | boardSquare;
        
        const Bitboard actualMoves = moveGenerator.GeneratePseudoLegalMoves(square, piecesBitboard);
        const Bitboard expectedMoves = (RANK_1 | FILE_A) & ~(boardSquare);
        REQUIRE(actualMoves == expectedMoves);
    }
}
