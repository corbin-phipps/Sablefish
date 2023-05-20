#pragma once

#include <array>
#include <cstdint>
#include <unordered_map>

#include "Bitboard.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::constants
{
using sablefish::board::BoardSquare;
using sablefish::board::piece::PieceType;
using sablefish::board::piece::PieceColor;

constexpr size_t NUM_RANKS = 8;
constexpr size_t NUM_FILES = 8;
constexpr size_t NUM_SQUARES = NUM_RANKS * NUM_FILES;
constexpr size_t NUM_PIECE_TYPES = 6;                  // Pawn, Rook, Knight, Bishop, Queen, King
constexpr size_t NUM_COLORS = 2;                       // White and Black

constexpr std::array<std::pair<PieceType, PieceColor>, NUM_PIECE_TYPES * NUM_COLORS> PIECE_DATA = {
    { { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Rook, PieceColor::White },
      { PieceType::Rook, PieceColor::Black },
      { PieceType::Knight, PieceColor::White },
      { PieceType::Knight, PieceColor::Black },
      { PieceType::Bishop, PieceColor::White },
      { PieceType::Bishop, PieceColor::Black },
      { PieceType::Queen, PieceColor::White },
      { PieceType::Queen, PieceColor::Black },
      { PieceType::King, PieceColor::White },
      { PieceType::King, PieceColor::Black } }
};

// TODO: Since std::unordered_map can't be constexpr, then there's no point in hardcoding it like this
const std::unordered_map<BoardSquare, sablefish::board::piece::Piece> STARTING_BOARDSQUARE_TO_PIECE_MAP = {
    {BoardSquare::A1, {PieceType::Rook, PieceColor::White}},
    {BoardSquare::B1, {PieceType::Knight, PieceColor::White}},
    {BoardSquare::C1, {PieceType::Bishop, PieceColor::White}},
    {BoardSquare::D1, {PieceType::Queen, PieceColor::White}},
    {BoardSquare::E1, {PieceType::King, PieceColor::White}},
    {BoardSquare::F1, {PieceType::Bishop, PieceColor::White}},
    {BoardSquare::G1, {PieceType::Knight, PieceColor::White}},
    {BoardSquare::H1, {PieceType::Rook, PieceColor::White}},

    {BoardSquare::A2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::B2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::C2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::D2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::E2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::F2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::G2, {PieceType::Pawn, PieceColor::White}},
    {BoardSquare::H2, {PieceType::Pawn, PieceColor::White}},

    {BoardSquare::A3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::B3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::C3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::D3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::E3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::F3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::G3, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::H3, {PieceType::Empty, PieceColor::Empty}},

    {BoardSquare::A4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::B4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::C4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::D4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::E4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::F4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::G4, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::H4, {PieceType::Empty, PieceColor::Empty}},

    {BoardSquare::A5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::B5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::C5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::D5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::E5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::F5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::G5, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::H5, {PieceType::Empty, PieceColor::Empty}},

    {BoardSquare::A6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::B6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::C6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::D6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::E6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::F6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::G6, {PieceType::Empty, PieceColor::Empty}},
    {BoardSquare::H6, {PieceType::Empty, PieceColor::Empty}},

    {BoardSquare::A7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::B7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::C7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::D7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::E7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::F7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::G7, {PieceType::Pawn, PieceColor::Black}},
    {BoardSquare::H7, {PieceType::Pawn, PieceColor::Black}},

    {BoardSquare::A8, {PieceType::Rook, PieceColor::Black}},
    {BoardSquare::B8, {PieceType::Knight, PieceColor::Black}},
    {BoardSquare::C8, {PieceType::Bishop, PieceColor::Black}},
    {BoardSquare::D8, {PieceType::Queen, PieceColor::Black}},
    {BoardSquare::E8, {PieceType::King, PieceColor::Black}},
    {BoardSquare::F8, {PieceType::Bishop, PieceColor::Black}},
    {BoardSquare::G8, {PieceType::Knight, PieceColor::Black}},
    {BoardSquare::H8, {PieceType::Rook, PieceColor::Black}},
};
} // namespace sablefish::constants

namespace sablefish::constants::bitfields
{
constexpr Bitboard RANK_1 = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111;
constexpr Bitboard RANK_2 = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
constexpr Bitboard RANK_3 = 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000;
constexpr Bitboard RANK_4 = 0b00000000'00000000'00000000'00000000'11111111'00000000'00000000'00000000;
constexpr Bitboard RANK_5 = 0b00000000'00000000'00000000'11111111'00000000'00000000'00000000'00000000;
constexpr Bitboard RANK_6 = 0b00000000'00000000'11111111'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard RANK_7 = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard RANK_8 = 0b11111111'00000000'00000000'00000000'00000000'00000000'00000000'00000000;

constexpr Bitboard FILE_A = 0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'00000001;
constexpr Bitboard FILE_B = 0b00000010'00000010'00000010'00000010'00000010'00000010'00000010'00000010;
constexpr Bitboard FILE_C = 0b00000100'00000100'00000100'00000100'00000100'00000100'00000100'00000100;
constexpr Bitboard FILE_D = 0b00001000'00001000'00001000'00001000'00001000'00001000'00001000'00001000;
constexpr Bitboard FILE_E = 0b00010000'00010000'00010000'00010000'00010000'00010000'00010000'00010000;
constexpr Bitboard FILE_F = 0b00100000'00100000'00100000'00100000'00100000'00100000'00100000'00100000;
constexpr Bitboard FILE_G = 0b01000000'01000000'01000000'01000000'01000000'01000000'01000000'01000000;
constexpr Bitboard FILE_H = 0b10000000'10000000'10000000'10000000'10000000'10000000'10000000'10000000;

constexpr Bitboard WHITE_PAWNS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
constexpr Bitboard BLACK_PAWNS_START = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard WHITE_ROOKS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'10000001;
constexpr Bitboard BLACK_ROOKS_START = 0b10000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard WHITE_KNIGHTS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'01000010;
constexpr Bitboard BLACK_KNIGHTS_START = 0b01000010'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard WHITE_BISHOPS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00100100;
constexpr Bitboard BLACK_BISHOPS_START = 0b00100100'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard WHITE_QUEEN_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00001000;
constexpr Bitboard BLACK_QUEEN_START = 0b00001000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr Bitboard WHITE_KING_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00010000;
constexpr Bitboard BLACK_KING_START = 0b00010000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
} // namespace sablefish::constants::bitfields

namespace sablefish::constants::functions
{
constexpr void SetBit(Bitboard& bitboard, sablefish::board::BoardSquare square)
{
    bitboard |= (1ULL << static_cast<size_t>(square));
}
} // namespace sablefish::constants::bitmanipulations

// This namespace defines the pre-computed lookup tables of pseudo-legal moves
namespace sablefish::constants::moves
{
using sablefish::board::BoardSquare;
using namespace sablefish::constants::functions;

// Definitions
constexpr std::array<Bitboard, NUM_SQUARES>
GenerateRookMoves()
{
    std::array<Bitboard, NUM_SQUARES> rookMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard rookBitboard = 0;
        size_t rookRank = square / NUM_RANKS;
        size_t rookFile = square % NUM_FILES;

        for (size_t rank = 0; rank < NUM_RANKS; rank++) {
            if (rank != rookRank) {
                BoardSquare targetSquare = static_cast<BoardSquare>((rank * NUM_RANKS) + rookFile);
                SetBit(rookBitboard, targetSquare);
            }
        }

        for (size_t file = 0; file < NUM_FILES; file++) {
            if (file != rookFile) {
                BoardSquare targetSquare = static_cast<BoardSquare>((rookRank * NUM_RANKS) + file);
                SetBit(rookBitboard, targetSquare);
            }
        }

        rookMoves[square] = rookBitboard;
    }

    return rookMoves;
}

constexpr std::array<Bitboard, NUM_SQUARES>
GenerateKnightMoves()
{
    std::array<Bitboard, NUM_SQUARES> knightMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard knightBitboard = 0;
        size_t knightRank = square / NUM_RANKS;
        size_t knightFile = square % NUM_FILES;

        std::array<std::array<size_t, 2>, 8> possibleKnightMoves = {{
            {knightRank + 1, knightFile + 2},
            {knightRank + 2, knightFile + 1},
            {knightRank + 1, knightFile - 2},
            {knightRank + 2, knightFile - 1},
            {knightRank - 1, knightFile + 2},
            {knightRank - 2, knightFile + 1},
            {knightRank - 1, knightFile - 2},
            {knightRank - 2, knightFile - 1}
        }};

        for (const auto& [targetRank, targetFile] : possibleKnightMoves) {
            if (targetRank >= 0 && targetRank < NUM_RANKS && targetFile >= 0 && targetFile < NUM_FILES) {
                BoardSquare targetSquare = static_cast<BoardSquare>((targetRank * NUM_RANKS) + targetFile);
                SetBit(knightBitboard, targetSquare);
            }
        }

        knightMoves[square] = knightBitboard;
    }

    return knightMoves;
}

constexpr std::array<Bitboard, NUM_SQUARES>
GenerateBishopMoves()
{
    std::array<Bitboard, NUM_SQUARES> bishopMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard bishopBitboard = 0;
        int bishopRank = square / NUM_RANKS;
        int bishopFile = square % NUM_FILES;

        // Positive rank; positive file
        int offset = 1;
        while (bishopRank + offset < NUM_RANKS && bishopFile + offset < NUM_FILES) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank + offset) * NUM_RANKS) + (bishopFile + offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Positive rank; negative file
        while (bishopRank + offset < NUM_RANKS && bishopFile - offset >= 0) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank + offset) * NUM_RANKS) + (bishopFile - offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Negative rank; positive file
        while (bishopRank - offset >= 0 && bishopFile + offset < NUM_FILES) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank - offset) * NUM_RANKS) + (bishopFile + offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Negative rank; negative file
        while (bishopRank - offset >= 0 && bishopFile - offset >= 0) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank - offset) * NUM_RANKS) + (bishopFile - offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }

        bishopMoves[square] = bishopBitboard;
    }

    return bishopMoves;
}

// Declarations
constexpr std::array<Bitboard, NUM_SQUARES> ROOK_MOVES = GenerateRookMoves();
constexpr std::array<Bitboard, NUM_SQUARES> KNIGHT_MOVES = GenerateKnightMoves();
constexpr std::array<Bitboard, NUM_SQUARES> BISHOP_MOVES = GenerateBishopMoves();
} // namespace sablefish::constants::moves
