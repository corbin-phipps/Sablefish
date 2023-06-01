#include <catch2/catch.hpp>
#include <sablefish/Board.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Piece.hpp>
#include <sablefish/Square.hpp>
#include <sablefish/Utilities.hpp>

#include "TestBoard.hpp"

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

TEST_CASE("Board can be constructed and initialized") {
    TestBoard board = TestBoard();
    
    SECTION("Initial Bitboard representation is correct") {
        for (const auto& [pieceType, pieceColor] : PIECE_DATA) {
            Bitboard actualBitboard = board.GetBitboard({ pieceType, pieceColor });
            Bitboard expectedBitboard = ConvertPieceDataToStartingBitboard(pieceType, pieceColor);
            REQUIRE(actualBitboard == expectedBitboard);
        }
    }

    SECTION("Initial array of Squares representation is correct") {
        for (size_t i = 0; i < NUM_SQUARES; i++) {
            BoardSquare boardSquare = static_cast<BoardSquare>(i);

            Square actualSquare = board.GetSquare(boardSquare);
            Square expectedSquare = ConvertBoardSquareToStartingSquare(boardSquare);

            REQUIRE(actualSquare == expectedSquare);
        }
    }
}

TEST_CASE("Board representations can be viewed and modified") {
    TestBoard board = TestBoard();
    SECTION("Get Bitboard") {
        Bitboard startingWhitePawnBitboard = board.GetBitboard({ PieceType::Pawn, PieceColor::White });
        REQUIRE(startingWhitePawnBitboard == WHITE_PAWNS_START);
    }

    SECTION("Get Square") {
        Square startingA1Square = board.GetSquare(BoardSquare::A1);
        REQUIRE(startingA1Square == Square({ PieceType::Rook, PieceColor::White }, BoardSquare::A1));
    }

    SECTION("Clear Board") {
        board.Clear();

        // Check Bitboards
        for (const auto& [pieceType, pieceData] : PIECE_DATA) {
            REQUIRE(board.GetBitboard({ pieceType, pieceData }) == EMPTY_BITBOARD);
        }

        // Check Squares
        Square emptySquare = Square();
        for (size_t i = 0; i < NUM_SQUARES; i++) {
            REQUIRE(board.GetSquare(static_cast<BoardSquare>(i)) == emptySquare);
        }
    }

    SECTION("IsEmpty works correctly") {
        // From starting Board
        REQUIRE(!board.IsEmpty());

        // Clear Board
        board.Clear();
        REQUIRE(board.IsEmpty());
    }
}
