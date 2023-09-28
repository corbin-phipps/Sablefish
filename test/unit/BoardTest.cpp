#include <catch2/catch.hpp>
#include <sablefish/Move.hpp>
#include <sablefish/Utilities.hpp>

#include "TestBoard.hpp"

using namespace sablefish::board;
using namespace sablefish::constants::bitfields;
using namespace sablefish::moves;

TEST_CASE("Board can be constructed and initialized") {
    TestBoard board = TestBoard();
    
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
            Square expectedSquare = ConvertBoardSquareToStartingSquare(boardSquare);

            REQUIRE(actualSquare == expectedSquare);
        }
    }
}

TEST_CASE("Board representations can be viewed and modified") {
    TestBoard board = TestBoard();
    SECTION("Get Bitboard") {
        Bitboard startingWhitePawnBitboard = board.GetBitboard(PieceType::Pawn, PieceColor::White);
        REQUIRE(startingWhitePawnBitboard == WHITE_PAWNS_START);
    }

    SECTION("Get Square") {
        Square startingA1Square = board.GetSquare(BoardSquare::A1);
        REQUIRE(startingA1Square == Square({ PieceType::Rook, PieceColor::White }, BoardSquare::A1));
    }

    SECTION("Clear Square") {
        board.ClearSquare(BoardSquare::A1);
        REQUIRE(board.GetSquare(BoardSquare::A1) == Square());
    }
}

TEST_CASE("Board can be updated") {
    TestBoard board = TestBoard();
    SECTION("Simple Quiet move") {
        // Verify starting Board state
        auto a2Square = board.GetSquare(BoardSquare::A2);
        auto a3Square = board.GetSquare(BoardSquare::A3);
        REQUIRE(a2Square.IsOccupied());
        REQUIRE(!a3Square.IsOccupied());

        REQUIRE(a2Square.GetPiece() == Piece(PieceType::Pawn, PieceColor::White));
        REQUIRE(board.GetBitboard(a2Square.GetPiece()) == WHITE_PAWNS_START);
        REQUIRE(a3Square.GetPiece() == Piece());
        REQUIRE_THROWS(board.GetBitboard(a3Square.GetPiece()));

        // Make move
        Move pawnQuietMove = CreateMove(BoardSquare::A2, BoardSquare::A3, MoveType::Quiet);
        board.UpdateBoard(pawnQuietMove, PieceColor::White);

        // Verify resulting Board state
        a2Square = board.GetSquare(BoardSquare::A2);
        a3Square = board.GetSquare(BoardSquare::A3);
        REQUIRE(!a2Square.IsOccupied());
        REQUIRE(a3Square.IsOccupied());

        REQUIRE(a2Square.GetPiece() == Piece());
        REQUIRE_THROWS(board.GetBitboard(a2Square.GetPiece()));
        REQUIRE(a3Square.GetPiece() == Piece(PieceType::Pawn, PieceColor::White));
        REQUIRE(board.GetBitboard(a3Square.GetPiece()) == 0b00000000'00000000'00000000'00000000'00000000'00000001'11111110'00000000);
    }

    SECTION("Simple Capture move") {
        // Setup Board
        board.Clear();
        Square whiteRook = Square(Piece(PieceType::Rook, PieceColor::White), BoardSquare::A1);
        Square blackQueen = Square(Piece(PieceType::Queen, PieceColor::Black), BoardSquare::A8);
        board.UpdateSquare(whiteRook);
        board.UpdateSquare(blackQueen);

        // Verify starting Board state
        auto a1Square = board.GetSquare(BoardSquare::A1);
        auto a8Square = board.GetSquare(BoardSquare::A8);
        REQUIRE(a1Square.IsOccupied());
        REQUIRE(a8Square.IsOccupied());

        REQUIRE(a1Square.GetPiece() == Piece(PieceType::Rook, PieceColor::White));
        REQUIRE(board.GetBitboard(a1Square.GetPiece()) == 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00000001);
        REQUIRE(a8Square.GetPiece() == Piece(PieceType::Queen, PieceColor::Black));
        REQUIRE(board.GetBitboard(a8Square.GetPiece()) == 0b00000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000);

        // Make move
        Move rookCaptureMove = CreateMove(BoardSquare::A1, BoardSquare::A8, MoveType::Capture);
        board.UpdateBoard(rookCaptureMove, PieceColor::White);

        // Verify resulting Board state
        a1Square = board.GetSquare(BoardSquare::A1);
        a8Square = board.GetSquare(BoardSquare::A8);
        REQUIRE(!a1Square.IsOccupied());
        REQUIRE(a8Square.IsOccupied());

        REQUIRE(a1Square.GetPiece() == Piece());
        REQUIRE_THROWS(board.GetBitboard(a1Square.GetPiece()));
        REQUIRE(a8Square.GetPiece() == Piece(PieceType::Rook, PieceColor::White));
        REQUIRE(board.GetBitboard(a8Square.GetPiece()) == 0b00000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000);
        REQUIRE(board.GetBitboard(PieceType::Queen, PieceColor::Black) == EMPTY_BITBOARD);
    }

    // TODO: Other MoveTypes
}

TEST_CASE("TestBoard-specific functionality works correctly") {
    TestBoard board = TestBoard();
    SECTION("Clear works correctly") {
        board.Clear();

        // Check Bitboards
        for (const auto& [pieceType, pieceData] : PIECE_DATA) {
            REQUIRE(board.GetBitboard(pieceType, pieceData) == EMPTY_BITBOARD);
        }

        // Check Squares
        Square emptySquare = Square();
        for (size_t i = 0; i < NUM_SQUARES; i++) {
            REQUIRE(board.GetSquare(static_cast<BoardSquare>(i)) == emptySquare);
        }
    }

    SECTION("UpdateSquare works correctly") {
        board.Clear();

        Piece whiteRook = Piece(PieceType::Rook, PieceColor::White);
        BoardSquare whiteRookBoardSquare = BoardSquare::A1;
        Square startingRookSquare = Square(whiteRook, whiteRookBoardSquare);
        board.UpdateSquare(startingRookSquare);

        // Check Bitboard representation
        REQUIRE(board.GetBitboard(whiteRook) == 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00000001);

        // Check Square representation
        REQUIRE(board.GetSquare(whiteRookBoardSquare) == startingRookSquare);
    }

    SECTION("IsEmpty works correctly") {
        // From starting Board
        REQUIRE(!board.IsEmpty());

        // Clear Board
        board.Clear();
        REQUIRE(board.IsEmpty());
    }
}
