#include <catch2/catch.hpp>
#include <sablefish/Constants.hpp>
#include <sablefish/Move.hpp>
#include <sablefish/MoveGenerator.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::constants::bitfields;
using namespace sablefish::moves;

TEST_CASE("Move can be created properly") {
    SECTION("Simple Move test") {
        BoardSquare startingSquare = BoardSquare::A1;
        BoardSquare targetSquare = BoardSquare::H8;
        MoveType moveType = MoveType::Quiet;

        Move move = CreateMove(startingSquare, targetSquare, moveType);
        Move expectedMove = 0b00000011'11110000;
        REQUIRE(move == expectedMove);
    }
}

TEST_CASE("Special moves can be identified correctly") {
    SECTION("White pawn promotion") {
        Piece whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D8;
        bool promotion = IsPromotion(whitePawn, promotionSquare);
        REQUIRE(promotion);
    }

    SECTION("Black pawn promotion") {
        Piece blackPawn = Piece(PieceType::Pawn, PieceColor::Black);
        BoardSquare promotionSquare = BoardSquare::D1;
        bool promotion = IsPromotion(blackPawn, promotionSquare);
        REQUIRE(promotion);
    }

    SECTION("Wrong PieceType") {
        Piece whiteQueen = Piece(PieceType::Queen, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D8;
        bool promotion = IsPromotion(whiteQueen, promotionSquare);
        REQUIRE(!promotion);
    }

    SECTION("Wrong PieceColor + promotion square") {
        Piece whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D1;
        bool promotion = IsPromotion(whitePawn, promotionSquare);
        REQUIRE(!promotion);
    }

    SECTION("Wrong promotion square") {
        Piece whitePawn = Piece(PieceType::Pawn, PieceColor::White);
        BoardSquare promotionSquare = BoardSquare::D4;
        bool promotion = IsPromotion(whitePawn, promotionSquare);
        REQUIRE(!promotion);
    }
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Pawn moves") {
    std::shared_ptr<Board> board = std::make_shared<Board>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    // TODO
}

TEST_CASE("MoveGenerator can generate basic pseudo-legal Rook moves") {
    std::shared_ptr<Board> board = std::make_shared<Board>();
    MoveGenerator moveGenerator = MoveGenerator(board);

    SECTION("Simple Rook quiet moves on empty Board") {
        // Clear the default starting Board
        board->Clear();

        // Add the Rook
        // TODO: Could this be improved??
        Square startingRookSquare = Square(Piece(PieceType::Rook, PieceColor::White), BoardSquare::A1);
        Bitboard startingBoardSquare = 1ULL << static_cast<Bitboard>(startingRookSquare.GetBoardSquare());
        Bitboard startingRookBitboard = EMPTY_BITBOARD | startingBoardSquare;
        board->SetSquare(startingRookSquare);
        board->SetBitboard(startingRookSquare.GetPiece().GetPieceType(), startingRookSquare.GetPiece().GetPieceColor(), startingRookBitboard);

        // Generate actual pseudo-legal moves
        std::vector<Move> actualMoves = moveGenerator.GeneratePseudoLegalMoves(PieceColor::White);
        
        // Generate expected pseudo-legal moves
        std::vector<Move> expectedMoves{};
        auto expectedMovesBitboard = (RANK_1 | FILE_A) & ~(startingBoardSquare);
        auto expectedMovesBoardSquares = ConvertBitboardToBoardSquares(expectedMovesBitboard);
        for (const auto& targetBoardSquare : expectedMovesBoardSquares) {
            expectedMoves.push_back(CreateMove(startingRookSquare.GetBoardSquare(), targetBoardSquare, MoveType::Quiet));
        }

        REQUIRE(actualMoves == expectedMoves);
    }
}
