#include <catch2/catch.hpp>
#include <sablefish/Player.hpp>

using namespace sablefish;
using namespace sablefish::board;

TEST_CASE("Player objects can be constructed") {
    SECTION("Specific Player") {
        auto whitePlayer = Player(PieceColor::White);
        REQUIRE(whitePlayer.GetPlayerPieceColor() == PieceColor::White);
        REQUIRE(whitePlayer.GetCompletedMovesCount() == 0);
    }
}
