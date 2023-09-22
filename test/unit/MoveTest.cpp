#include <catch2/catch.hpp>
#include <sablefish/Move.hpp>

#include "TestBoard.hpp"

using namespace sablefish::board;
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

TEST_CASE("Promotions can be identified correctly") {
    SECTION("White pawn promotion") {
        Piece whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D8;
        bool promotion = IsPromotion(whitePawn, promotionSquare);
        REQUIRE(promotion);
    }

    SECTION("Black pawn promotion") {
        Piece blackPawn = Piece(PieceType::Pawn, PieceColor::Black);
        BoardSquare promotionSquare = BoardSquare::D1;
        bool promotion = IsPromotion(blackPawn, promotionSquare);
        REQUIRE(promotion);
    }

    SECTION("Wrong PieceType") {
        Piece whiteQueen = Piece(PieceType::Queen, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D8;
        bool promotion = IsPromotion(whiteQueen, promotionSquare);
        REQUIRE(!promotion);
    }

    SECTION("Wrong PieceColor + promotion square") {
        Piece whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D1;
        bool promotion = IsPromotion(whitePawn, promotionSquare);
        REQUIRE(!promotion);
    }

    SECTION("Wrong promotion square") {
        Piece whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D4;
        bool promotion = IsPromotion(whitePawn, promotionSquare);
        REQUIRE(!promotion);
    }
}

TEST_CASE("Move data can be extracted correctly from a Move") {
    Move move = CreateMove(BoardSquare::A2, BoardSquare::A3, MoveType::Quiet);
    auto [startingSquare, targetSquare, moveType] = GetMoveData(move);

    REQUIRE(startingSquare == BoardSquare::A2);
    REQUIRE(targetSquare == BoardSquare::A3);
    REQUIRE(moveType == MoveType::Quiet);
}
