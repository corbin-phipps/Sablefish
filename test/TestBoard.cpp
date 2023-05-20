#include <catch2/catch.hpp>
#include <sablefish/Board.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Piece.hpp>
#include <sablefish/Square.hpp>
#include <sablefish/Utilities.hpp>

#include <iostream>

using namespace sablefish::board;
using namespace sablefish::board::piece;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

TEST_CASE("Board can be constructed and initialized") {
    Board board = Board();
    
    SECTION("Initial Bitboard representation is correct") {
        for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
            Bitboard actualBitboard = board.GetBitboard(pieceType, pieceColor);
            Bitboard expectedBitboard = ConvertPieceDataToStartingBitboard(pieceType, pieceColor);
            REQUIRE(actualBitboard == expectedBitboard);
        }
    }

    SECTION("Initial array of Squares representation is correct") {
        for (size_t i = 0; i < static_cast<size_t>(BoardSquare::H8) + 1; i++) {
            BoardSquare boardSquare = static_cast<BoardSquare>(i);

            Square actualSquare = board.GetSquare(boardSquare);
            Square expectedSquare = Square(STARTING_BOARDSQUARE_TO_PIECE_MAP.at(boardSquare));
            REQUIRE(actualSquare == expectedSquare);
        }
    }
}
