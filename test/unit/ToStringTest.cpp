#include <catch2/catch.hpp>
#include <sablefish/Move.hpp>
#include <sablefish/Utilities.hpp>

#include "TestBoard.hpp"

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::moves;

TEST_CASE("Bitboard can be printed") {
    std::string boardString = "00000000\n"
                              "00000000\n"
                              "00000000\n"
                              "00000000\n"
                              "00000000\n"
                              "00000000\n"
                              "00000000\n"
                              "11111111\n";

    REQUIRE(ToString(bitfields::RANK_1) == boardString);
}

TEST_CASE("Board can be printed") {
    TestBoard board = TestBoard();
    std::string boardString = "rnbqkbnr\n"
                              "pppppppp\n"
                              "--------\n"
                              "--------\n"
                              "--------\n"
                              "--------\n"
                              "PPPPPPPP\n"
                              "RNBQKBNR\n";

    REQUIRE(board.ToString() == boardString);
}

TEST_CASE("BoardSquare can be printed") {
    BoardSquare boardSquare = BoardSquare::A1;
    std::string boardSquareString = "A1";

    REQUIRE(ToString(boardSquare) == boardSquareString);
}

TEST_CASE("MoveType can be printed") {
    MoveType moveType = MoveType::Quiet;
    std::string moveTypeString = "Quiet";

    REQUIRE(ToString(moveType) == moveTypeString);
}

TEST_CASE("Move can be printed") {
    BoardSquare startingBoardSquare = BoardSquare::A2;
    BoardSquare targetBoardSquare = BoardSquare::A3;
    MoveType moveType = MoveType::Quiet;

    Move move = CreateMove(startingBoardSquare, targetBoardSquare, moveType);
    std::string moveString = "Starting Square: A2\n"
                             "Target Square: A3\n"
                             "Move Type: Quiet\n";

    REQUIRE(ToString(move) == moveString);
}
