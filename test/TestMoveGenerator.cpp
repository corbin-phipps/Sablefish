#include <catch2/catch.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Move.hpp>
#include <sablefish/MoveGenerator.hpp>

using namespace sablefish::board;
using namespace sablefish::constants::bitfields;
using namespace sablefish::moves;

TEST_CASE("Move can be created properly") {
    SECTION("Simple Move test") {
        BoardSquare startingSquare = BoardSquare::A1;
        BoardSquare targetSquare = BoardSquare::H8;
        MoveType moveType = MoveType::Quiet;

        Move move = CreateMove(startingSquare, targetSquare, moveType);
        Move expectedMove = 0b00000011'11110000;
        REQUIRE(move == expectedMove);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Pawn moves") {
    Board board = Board();
    MoveGenerator moveGenerator = MoveGenerator(std::make_shared<Board>(board));

    // TODO
}
/*
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
*/
