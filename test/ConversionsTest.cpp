#include <catch2/catch.hpp>
#include <sablefish/Board.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

TEST_CASE("Bitboard can be converted to a list of BoardSquares") {
    SECTION("Empty Bitboard") {
        auto boardSquares = ConvertBitboardToBoardSquares(EMPTY_BITBOARD);
        REQUIRE(boardSquares.size() == 0);
    }

    SECTION("Full Bitboard") {
        auto boardSquares = ConvertBitboardToBoardSquares(FULL_BITBOARD);
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

TEST_CASE("List of BoardSquares can be converted to a Bitboard") {
    std::vector<BoardSquare> boardSquares{};
    SECTION("Empty list of BoardSquares") {
        REQUIRE(ConvertBoardSquaresToBitboard(boardSquares) == EMPTY_BITBOARD);
    }

    SECTION("Full list of BoardSquares") {
        for (size_t i = 0; i < NUM_SQUARES; i++) {
            boardSquares.push_back(static_cast<BoardSquare>(i));
        }

        REQUIRE(ConvertBoardSquaresToBitboard(boardSquares) == FULL_BITBOARD);
    }

    SECTION("Single rank") {
        for (size_t i = 0; i < NUM_FILES; i++) {
            boardSquares.push_back(static_cast<BoardSquare>(i));
        }

        REQUIRE(ConvertBoardSquaresToBitboard(boardSquares) == RANK_1);
    }

    SECTION("Single file") {
        for (size_t i = 0; i < NUM_RANKS; i++) {
            boardSquares.push_back(static_cast<BoardSquare>(i * NUM_RANKS));
        }

        REQUIRE(ConvertBoardSquaresToBitboard(boardSquares) == FILE_A);
    }

    SECTION("Diagonal across entire board") {
        for (size_t i = 0; i < NUM_RANKS; i++) {
            boardSquares.push_back(static_cast<BoardSquare>(i * NUM_RANKS + i));
        }

        REQUIRE(ConvertBoardSquaresToBitboard(boardSquares) == 0b10000000'01000000'00100000'00010000'00001000'00000100'00000010'00000001);
    }
}

TEST_CASE("Piece data can be mapped to the appropriate starting position Bitboard") {
    SECTION("Specific Piece") {
        auto whitePawnStartingBitboard = ConvertPieceDataToStartingBitboard(PieceType::Pawn, PieceColor::White);
        REQUIRE(whitePawnStartingBitboard == WHITE_PAWNS_START);
    }
}

TEST_CASE("BoardSquare can be mapped to the appropriate starting Square") {
    BoardSquare boardSquare = BoardSquare::A1;
    Square startingSquare = ConvertBoardSquareToStartingSquare(boardSquare);
    REQUIRE(startingSquare == Square({ PieceType::Rook, PieceColor::White }, boardSquare));
}
