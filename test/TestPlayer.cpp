#include <catch2/catch.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Player.hpp>

using namespace sablefish;
using namespace sablefish::board;
using namespace sablefish::constants::bitfields;

TEST_CASE("Player objects can be constructed and initialized") {
    auto board = std::make_shared<Board>(Board());

    SECTION("Initial Player construction is correct") {
        auto player = Player(PieceColor::White, board);
        Bitboard actualPlayerPiecesBitboard = player.GetPlayerPiecesBitboard();
        Bitboard expectedPlayerPiecesBitboard = WHITE_PAWNS_START | WHITE_ROOKS_START | WHITE_KNIGHTS_START | 
                                                WHITE_BISHOPS_START | WHITE_QUEEN_START | WHITE_KING_START;

        REQUIRE(player.GetPlayerPieceColor() == PieceColor::White);
        REQUIRE(player.GetCompletedMovesCount() == 0);
        REQUIRE(actualPlayerPiecesBitboard == expectedPlayerPiecesBitboard);
    }
}
