#include <catch2/catch.hpp>
#include <sablefish/Utilities.hpp>

#include "TestBoard.hpp"

using namespace sablefish::board;
using namespace sablefish::constants;

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
