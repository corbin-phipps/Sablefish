#include <catch2/catch.hpp>
#include <sablefish/Piece.hpp>

using namespace sablefish::board::piece;

TEST_CASE("Piece objects can be constructed") {
    SECTION("Empty Piece") {
        auto emptyPiece = Piece();
        REQUIRE(emptyPiece.GetPieceType() == PieceType::Empty);
        REQUIRE(emptyPiece.GetPieceColor() == PieceColor::Empty);
    }

    SECTION("Specific Piece") {
        auto whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        REQUIRE(whitePawn.GetPieceType() == PieceType::Pawn);
        REQUIRE(whitePawn.GetPieceColor() == PieceColor::White);
    }
}
