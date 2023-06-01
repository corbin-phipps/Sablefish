#include <catch2/catch.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::constants;

TEST_CASE("Bitboard can be printed") {
    SECTION("Bitboard can be printed as a bit string") {
        REQUIRE(ToString(bitfields::RANK_1) == "0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111");
    }

    SECTION("Bitboard can be printed as a chess board") {
        std::string boardString = "00000000\n"
                                  "00000000\n"
                                  "00000000\n"
                                  "00000000\n"
                                  "00000000\n"
                                  "00000000\n"
                                  "00000000\n"
                                  "11111111\n";
        REQUIRE(ToBoard(bitfields::RANK_1) == boardString);
    }
}
