#include <catch2/catch.hpp>
#include <sablefish/Game.hpp>

using namespace sablefish;

TEST_CASE("Game objects can be constructed and initialized") {
    SECTION("Initial Game construction is correct") {
        auto game = Game();
        auto board = game.GetBoard();
        auto whitePlayer = game.GetPlayer(PieceColor::White);
        auto blackPlayer = game.GetPlayer(PieceColor::Black);

        REQUIRE_THROWS(game.GetLastMove());
        REQUIRE_THROWS(game.GetPlayer(PieceColor::Empty));

        // Players should share same board as Game instance
        REQUIRE(whitePlayer.GetBoard() == board);
        REQUIRE(blackPlayer.GetBoard() == board);
    }
}
