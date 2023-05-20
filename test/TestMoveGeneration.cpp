#include <catch2/catch.hpp>
#include <sablefish/Constants.hpp>

using namespace sablefish::constants::moves;

TEST_CASE("Pseudo-legal rook moves are generated correctly") {
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

TEST_CASE("Pseudo-legal knight moves are generated correctly") {
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

TEST_CASE("Pseudo-legal bishop moves are generated correctly") {
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

TEST_CASE("Pseudo-legal queen moves are generated correctly") {
    
}

TEST_CASE("Pseudo-legal king moves are generated correctly") {
    
}

TEST_CASE("Pseudo-legal pawn moves are generated correctly") {
    
}
