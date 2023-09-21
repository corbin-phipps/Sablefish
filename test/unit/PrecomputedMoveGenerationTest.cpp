#include <catch2/catch.hpp>
#include <sablefish/Constants.hpp>

using namespace sablefish::board;

TEST_CASE("Pre-computed non-capture pawn moves are generated correctly") {
    SECTION("White Pawn in starting position") {
        Bitboard generatedPawnMoves = PAWN_NON_CAPTURE_MOVES_WHITE.at(static_cast<size_t>(BoardSquare::A2));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00000000'00000000'00000001'00000001'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }

    SECTION("White Pawn in middle") {
        Bitboard generatedPawnMoves = PAWN_NON_CAPTURE_MOVES_WHITE.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00010000'00000000'00000000'00000000'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }

    SECTION("Black Pawn in starting position") {
        Bitboard generatedPawnMoves = PAWN_NON_CAPTURE_MOVES_BLACK.at(static_cast<size_t>(BoardSquare::A7));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00000001'00000001'00000000'00000000'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }

    SECTION("Black Pawn in middle") {
        Bitboard generatedPawnMoves = PAWN_NON_CAPTURE_MOVES_BLACK.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00000000'00000000'00010000'00000000'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }
}

TEST_CASE("Pre-computed regular capture pawn moves are generated correctly") {
    SECTION("White Pawn in starting position") {
        Bitboard generatedPawnMoves = PAWN_CAPTURE_MOVES_WHITE.at(static_cast<size_t>(BoardSquare::A2));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00000000'00000000'00000000'00000010'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }

    SECTION("White Pawn in middle") {
        Bitboard generatedPawnMoves = PAWN_CAPTURE_MOVES_WHITE.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00101000'00000000'00000000'00000000'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }

    SECTION("Black Pawn in starting position") {
        Bitboard generatedPawnMoves = PAWN_CAPTURE_MOVES_BLACK.at(static_cast<size_t>(BoardSquare::A7));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00000010'00000000'00000000'00000000'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }

    SECTION("Black Pawn in middle") {
        Bitboard generatedPawnMoves = PAWN_CAPTURE_MOVES_BLACK.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedPawnMoves = 0b00000000'00000000'00000000'00000000'00101000'00000000'00000000'00000000;
        REQUIRE(generatedPawnMoves == expectedPawnMoves);
    }
}

TEST_CASE("Pre-computed rook moves are generated correctly") {
    SECTION("Rook in corner") {
        Bitboard generatedRookMoves = ROOK_MOVES.at(static_cast<size_t>(BoardSquare::A1));
        Bitboard expectedRookMoves = 0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'11111110;
        REQUIRE(generatedRookMoves == expectedRookMoves);
    }

    SECTION("Rook in middle") {
        Bitboard generatedRookMoves = ROOK_MOVES.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedRookMoves = 0b00010000'00010000'00010000'11101111'00010000'00010000'00010000'00010000;
        REQUIRE(generatedRookMoves == expectedRookMoves);
    }
}

TEST_CASE("Pre-computed knight moves are generated correctly") {
    SECTION("Knight in corner") {
        Bitboard generatedKnightMoves = KNIGHT_MOVES.at(static_cast<size_t>(BoardSquare::A1));
        Bitboard expectedKnightMoves = 0b00000000'00000000'00000000'00000000'00000000'00000010'00000100'00000000;
        REQUIRE(generatedKnightMoves == expectedKnightMoves);
    }

    SECTION("Knight in middle") {
        Bitboard generatedKnightMoves = KNIGHT_MOVES.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedKnightMoves = 0b00000000'00101000'01000100'00000000'01000100'00101000'00000000'00000000;
        REQUIRE(generatedKnightMoves == expectedKnightMoves);
    }
}

TEST_CASE("Pre-computed bishop moves are generated correctly") {
    SECTION("Bishop in corner") {
        Bitboard generatedBishopMoves = BISHOP_MOVES.at(static_cast<size_t>(BoardSquare::A1));
        Bitboard expectedBishopMoves = 0b10000000'01000000'00100000'00010000'00001000'00000100'00000010'00000000;
        REQUIRE(generatedBishopMoves == expectedBishopMoves);
    }

    SECTION("Bishop in middle") {
        Bitboard generatedBishopMoves = BISHOP_MOVES.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedBishopMoves = 0b10000010'01000100'00101000'00000000'00101000'01000100'10000010'00000001;
        REQUIRE(generatedBishopMoves == expectedBishopMoves);
    }
}

TEST_CASE("Pre-computed queen moves are generated correctly") {
    SECTION("Queen in corner") {
        Bitboard generatedQueenMoves = QUEEN_MOVES.at(static_cast<size_t>(BoardSquare::A1));
        Bitboard expectedQueenMoves = 0b10000001'01000001'00100001'00010001'00001001'00000101'00000011'11111110;
        REQUIRE(generatedQueenMoves == expectedQueenMoves);
    }

    SECTION("Queen in middle") {
        Bitboard generatedQueenMoves = QUEEN_MOVES.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedQueenMoves = 0b10010010'01010100'00111000'11101111'00111000'01010100'10010010'00010001;
        REQUIRE(generatedQueenMoves == expectedQueenMoves);
    }
}

TEST_CASE("Pre-computed king moves are generated correctly") {
    SECTION("King in corner") {
        Bitboard generatedKingMoves = KING_MOVES.at(static_cast<size_t>(BoardSquare::A1));
        Bitboard expectedKingMoves = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000011'00000010;
        REQUIRE(generatedKingMoves == expectedKingMoves);
    }

    SECTION("King in middle") {
        Bitboard generatedKingMoves = KING_MOVES.at(static_cast<size_t>(BoardSquare::E5));
        Bitboard expectedKingMoves = 0b00000000'00000000'00111000'00101000'00111000'00000000'00000000'00000000;
        REQUIRE(generatedKingMoves == expectedKingMoves);
    }
}
