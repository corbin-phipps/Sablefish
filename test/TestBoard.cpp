#include <catch2/catch.hpp>
#include <sablefish/Board.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Piece.hpp>
#include <sablefish/Square.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

TEST_CASE("Board can be constructed and initialized") {
    Board board = Board();
    
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
    Board board = Board();
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

    SECTION("Update Board") {
        auto whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        auto startingPawnSquare = Square(whitePawn, BoardSquare::A2);
        auto targetPawnSquare = Square(whitePawn, BoardSquare::A3);
        board.Update(startingPawnSquare, targetPawnSquare);

        // Check Bitboard representation
        REQUIRE(board.GetBitboard(whitePawn) == 0b00000000'00000000'00000000'00000000'00000000'00000001'11111110'00000000);

        // Check Square representation
        REQUIRE(board.GetSquare(BoardSquare::A2) == Square({ PieceType::Empty, PieceColor::Empty }, BoardSquare::A2));
        REQUIRE(board.GetSquare(BoardSquare::A3) == targetPawnSquare);
    }
}
