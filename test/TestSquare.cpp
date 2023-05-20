#include <catch2/catch.hpp>
#include <sablefish/Piece.hpp>
#include <sablefish/Square.hpp>

using namespace sablefish::board;
using namespace sablefish::board::piece;

TEST_CASE("Square objects can be constructed") {
    SECTION("Empty Square") {
        auto emptySquare = Square();
        auto piece = emptySquare.GetPiece();
        auto isOccupied = emptySquare.IsOccupied();

        REQUIRE(piece.GetPieceType() == PieceType::Empty);
        REQUIRE(piece.GetPieceColor() == PieceColor::Empty);
        REQUIRE(!isOccupied);
    }

    SECTION("Specific Square") {
        auto whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        auto square = Square(whitePawn);

        REQUIRE(whitePawn.GetPieceType() == PieceType::Pawn);
        REQUIRE(whitePawn.GetPieceColor() == PieceColor::White);
        REQUIRE(square.IsOccupied());
    }
}
