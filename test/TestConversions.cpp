#include <catch2/catch.hpp>
#include <sablefish/Board.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

TEST_CASE("Bitboard can be converted to a list of BoardSquares") {
    SECTION("Empty Bitboard") {
        Bitboard emptyBitboard = 0ULL;
        auto boardSquares = ConvertBitboardToBoardSquares(emptyBitboard);

        REQUIRE(boardSquares.size() == 0);
    }

    SECTION("Full Bitboard") {
        Bitboard fullBitboard = 0b11111111'11111111'11111111'11111111'11111111'11111111'11111111'11111111;
        auto boardSquares = ConvertBitboardToBoardSquares(fullBitboard);

        REQUIRE(boardSquares.size() == NUM_SQUARES);
    }

    SECTION("Realistic Bitboard - White pawns starting position") {
        auto boardSquares = ConvertBitboardToBoardSquares(WHITE_PAWNS_START);

        REQUIRE(boardSquares.size() == NUM_FILES);

        REQUIRE(boardSquares[0] == BoardSquare::A2);
        REQUIRE(boardSquares[1] == BoardSquare::B2);
        REQUIRE(boardSquares[2] == BoardSquare::C2);
        REQUIRE(boardSquares[3] == BoardSquare::D2);
        REQUIRE(boardSquares[4] == BoardSquare::E2);
        REQUIRE(boardSquares[5] == BoardSquare::F2);
        REQUIRE(boardSquares[6] == BoardSquare::G2);
        REQUIRE(boardSquares[7] == BoardSquare::H2);
    }
}

TEST_CASE("Piece data can be mapped to the appropriate starting position Bitboard") {
    SECTION("Specific Piece") {
        auto whitePawnStartingBitboard = ConvertPieceDataToStartingBitboard(PieceType::Pawn, PieceColor::White);
        REQUIRE(whitePawnStartingBitboard == WHITE_PAWNS_START);
    }
}
