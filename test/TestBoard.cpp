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
            Bitboard actualBitboard = board.GetBitboard(pieceType, pieceColor);
            Bitboard expectedBitboard = ConvertPieceDataToStartingBitboard(pieceType, pieceColor);
            REQUIRE(actualBitboard == expectedBitboard);
        }
    }

    SECTION("Initial array of Squares representation is correct") {
        for (size_t i = 0; i < NUM_SQUARES; i++) {
            BoardSquare boardSquare = static_cast<BoardSquare>(i);

            Square actualSquare = board.GetSquare(boardSquare);
            Square expectedSquare = Square(ConvertBoardSquareToStartingPiece(boardSquare));
            REQUIRE(actualSquare == expectedSquare);
        }
    }
}

TEST_CASE("Board representations can be viewed and modified") {
    Board board = Board();
    SECTION("Get and set Bitboards") {
        Bitboard startingWhitePawnBitboard = board.GetBitboard(PieceType::Pawn, PieceColor::White);
        REQUIRE(startingWhitePawnBitboard == WHITE_PAWNS_START);

        board.SetBitboard(PieceType::Pawn, PieceColor::White, 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000);
        Bitboard modifiedWhitePawnBitboard = board.GetBitboard(PieceType::Pawn, PieceColor::White);
        REQUIRE(modifiedWhitePawnBitboard == 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000);
    }

    SECTION("Get and set Squares") {
        Square startingA1Square = board.GetSquare(BoardSquare::A1);
        REQUIRE(startingA1Square == Square(Piece(PieceType::Rook, PieceColor::White)));

        board.SetSquare(BoardSquare::A1, Square(Piece(PieceType::King, PieceColor::Black)));
        Square modifiedA1Square = board.GetSquare(BoardSquare::A1);
        REQUIRE(modifiedA1Square == Square(Piece(PieceType::King, PieceColor::Black)));
    }
}
