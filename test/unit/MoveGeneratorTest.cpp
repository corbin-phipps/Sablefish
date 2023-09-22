#include <catch2/catch.hpp>
#include <sablefish/MoveGenerator.hpp>
#include <sablefish/Utilities.hpp>

#include "TestBoard.hpp"

using namespace sablefish::board;
using namespace sablefish::moves;

TEST_CASE("MoveGenerator can generate basic pseudo-legal Pawn moves") {
    std::shared_ptr<TestBoard> board = std::make_shared<TestBoard>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("White Pawn non-capture moves on empty Board") {
        board->Clear();

        // Add the White Pawn
        Square startingPawnSquare = Square({ PieceType::Pawn, PieceColor::White }, BoardSquare::A2);
        board->UpdateSquare(startingPawnSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        expectedMoves.push_back(CreateMove(startingPawnSquare.GetBoardSquare(), BoardSquare::A3, MoveType::Quiet));
        expectedMoves.push_back(CreateMove(startingPawnSquare.GetBoardSquare(), BoardSquare::A4, MoveType::DoublePawnPush));

        REQUIRE(actualMoves == expectedMoves);
    }

    SECTION("White Pawn regular capture moves") {
        board->Clear();

        // Add the White Pawn
        Square playerPawnSquare = Square({ PieceType::Pawn, PieceColor::White }, BoardSquare::E4);
        board->UpdateSquare(playerPawnSquare);

        // Add the opponent Black Pawns
        Square opponentBlockingPawnSquare = Square({ PieceType::Pawn, PieceColor::Black }, BoardSquare::E5);
        board->UpdateSquare(opponentBlockingPawnSquare);

        Square opponentToCapturePawnSquare = Square({ PieceType::Pawn, PieceColor::Black }, BoardSquare::D5);
        board->UpdateSquare(opponentToCapturePawnSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        expectedMoves.push_back(CreateMove(playerPawnSquare.GetBoardSquare(), BoardSquare::D5, MoveType::Capture));

        REQUIRE(actualMoves == expectedMoves);
    }

    SECTION("Black Pawn non-capture moves on empty Board") {
        board->Clear();

        // Add the Black Pawn
        Square startingPawnSquare = Square({ PieceType::Pawn, PieceColor::Black }, BoardSquare::A7);
        board->UpdateSquare(startingPawnSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::Black);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        expectedMoves.push_back(CreateMove(startingPawnSquare.GetBoardSquare(), BoardSquare::A5, MoveType::DoublePawnPush));
        expectedMoves.push_back(CreateMove(startingPawnSquare.GetBoardSquare(), BoardSquare::A6, MoveType::Quiet));

        REQUIRE(actualMoves == expectedMoves);
    }

    SECTION("Black Pawn regular capture moves") {
        board->Clear();

        // Add the Black Pawn
        Square playerPawnSquare = Square({ PieceType::Pawn, PieceColor::Black }, BoardSquare::D5);
        board->UpdateSquare(playerPawnSquare);

        // Add the opponent White Pawns
        Square opponentBlockingPawnSquare = Square({ PieceType::Pawn, PieceColor::White }, BoardSquare::D4);
        board->UpdateSquare(opponentBlockingPawnSquare);

        Square opponentToCapturePawnSquare = Square({ PieceType::Pawn, PieceColor::White }, BoardSquare::E4);
        board->UpdateSquare(opponentToCapturePawnSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::Black);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        expectedMoves.push_back(CreateMove(playerPawnSquare.GetBoardSquare(), BoardSquare::E4, MoveType::Capture));

        REQUIRE(actualMoves == expectedMoves);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Rook moves") {
    std::shared_ptr<TestBoard> board = std::make_shared<TestBoard>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("Simple Rook quiet moves on empty Board") {
        // Clear the default starting Board
        board->Clear();

        // Add the Rook
        Square startingRookSquare = Square({ PieceType::Rook, PieceColor::White }, BoardSquare::A1);
        board->UpdateSquare(startingRookSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);
        
        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        Bitboard startingBoardSquare = 1ULL << startingRookSquare.GetBoardSquare();
        auto expectedMovesBitboard = (bitfields::RANK_1 | bitfields::FILE_A) & ~(startingBoardSquare);
        auto expectedMovesBoardSquares = ConvertBitboardToBoardSquares(expectedMovesBitboard);
        for (const auto& targetBoardSquare : expectedMovesBoardSquares) {
            expectedMoves.push_back(CreateMove(startingRookSquare.GetBoardSquare(), targetBoardSquare, MoveType::Quiet));
        }

        REQUIRE(actualMoves == expectedMoves);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Knight moves") {
    std::shared_ptr<TestBoard> board = std::make_shared<TestBoard>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("Simple Knight quiet moves on empty board") {
        // Clear the default starting Board
        board->Clear();

        // Add the Knight
        Square startingKnightSquare = Square({ PieceType::Knight, PieceColor::White }, BoardSquare::B1);
        board->UpdateSquare(startingKnightSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        std::vector<BoardSquare> expectedMovesBoardSquares{ BoardSquare::D2, BoardSquare::A3, BoardSquare::C3 };
        for (const auto& targetBoardSquare : expectedMovesBoardSquares) {
            expectedMoves.push_back(CreateMove(startingKnightSquare.GetBoardSquare(), targetBoardSquare, MoveType::Quiet));
        }

        REQUIRE(actualMoves == expectedMoves);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Bishop moves") {
    std::shared_ptr<TestBoard> board = std::make_shared<TestBoard>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("Simple Bishop quiet moves on empty board") {
        // Clear the default starting Board
        board->Clear();

        // Add the Bishop
        Square startingBishopSquare = Square({ PieceType::Bishop, PieceColor::White }, BoardSquare::C1);
        board->UpdateSquare(startingBishopSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        std::vector<BoardSquare> expectedMovesBoardSquares{ BoardSquare::B2, BoardSquare::D2, BoardSquare::A3, BoardSquare::E3, BoardSquare::F4, BoardSquare::G5, BoardSquare::H6 };
        for (const auto& targetBoardSquare : expectedMovesBoardSquares) {
            expectedMoves.push_back(CreateMove(startingBishopSquare.GetBoardSquare(), targetBoardSquare, MoveType::Quiet));
        }

        REQUIRE(actualMoves == expectedMoves);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Queen moves") {
    std::shared_ptr<TestBoard> board = std::make_shared<TestBoard>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("Simple Queen quiet moves on empty board") {
        // Clear the default starting Board
        board->Clear();

        // Add the Queen
        Square startingQueenSquare = Square({ PieceType::Queen, PieceColor::White }, BoardSquare::D1);
        board->UpdateSquare(startingQueenSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        Bitboard startingBoardSquare = 1ULL << startingQueenSquare.GetBoardSquare();
        auto expectedMovesBitboard = (bitfields::RANK_1 | bitfields::FILE_D) & ~(startingBoardSquare);
        expectedMovesBitboard |= 0b00000000'00000000'00000000'10000000'01000001'00100010'00010100'00000000;
        auto expectedMovesBoardSquares = ConvertBitboardToBoardSquares(expectedMovesBitboard);
        for (const auto& targetBoardSquare : expectedMovesBoardSquares) {
            expectedMoves.push_back(CreateMove(startingQueenSquare.GetBoardSquare(), targetBoardSquare, MoveType::Quiet));
        }

        REQUIRE(actualMoves == expectedMoves);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal King moves") {
    std::shared_ptr<TestBoard> board = std::make_shared<TestBoard>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("Simple King quiet moves on empty board") {
        // Clear the default starting Board
        board->Clear();

        // Add the King
        Square startingKingSquare = Square({ PieceType::King, PieceColor::White }, BoardSquare::E1);
        board->UpdateSquare(startingKingSquare);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);

        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        std::vector<BoardSquare> expectedMovesBoardSquares{ BoardSquare::D1, BoardSquare::F1, BoardSquare::D2, BoardSquare::E2, BoardSquare::F2 };
        for (const auto& targetBoardSquare : expectedMovesBoardSquares) {
            expectedMoves.push_back(CreateMove(startingKingSquare.GetBoardSquare(), targetBoardSquare, MoveType::Quiet));
        }

        REQUIRE(actualMoves == expectedMoves);
    }
}
