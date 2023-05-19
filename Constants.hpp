#pragma once

#include <array>
#include <cstdint>

#include "Bitboard.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::constants
{
using sablefish::board::piece::PieceType;
using sablefish::board::piece::PieceColor;

constexpr int NUM_RANKS = 8;
constexpr int NUM_FILES = 8;
constexpr int NUM_SQUARES = NUM_RANKS * NUM_FILES;
constexpr int NUM_PIECE_TYPES = 6;                  // Pawn, Rook, Knight, Bishop, Queen, King
constexpr int NUM_COLORS = 2;                       // White and Black

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
} // namespace sablefish::constants

namespace sablefish::constants::bitfields
{
constexpr uint64_t RANK_1 = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111;
constexpr uint64_t RANK_2 = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
constexpr uint64_t RANK_3 = 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000;
constexpr uint64_t RANK_4 = 0b00000000'00000000'00000000'00000000'11111111'00000000'00000000'00000000;
constexpr uint64_t RANK_5 = 0b00000000'00000000'00000000'11111111'00000000'00000000'00000000'00000000;
constexpr uint64_t RANK_6 = 0b00000000'00000000'11111111'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t RANK_7 = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t RANK_8 = 0b11111111'00000000'00000000'00000000'00000000'00000000'00000000'00000000;

constexpr uint64_t FILE_A = 0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'00000001;
constexpr uint64_t FILE_B = 0b00000010'00000010'00000010'00000010'00000010'00000010'00000010'00000010;
constexpr uint64_t FILE_C = 0b00000100'00000100'00000100'00000100'00000100'00000100'00000100'00000100;
constexpr uint64_t FILE_D = 0b00001000'00001000'00001000'00001000'00001000'00001000'00001000'00001000;
constexpr uint64_t FILE_E = 0b00010000'00010000'00010000'00010000'00010000'00010000'00010000'00010000;
constexpr uint64_t FILE_F = 0b00100000'00100000'00100000'00100000'00100000'00100000'00100000'00100000;
constexpr uint64_t FILE_G = 0b01000000'01000000'01000000'01000000'01000000'01000000'01000000'01000000;
constexpr uint64_t FILE_H = 0b10000000'10000000'10000000'10000000'10000000'10000000'10000000'10000000;

constexpr uint64_t WHITE_PAWNS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
constexpr uint64_t BLACK_PAWNS_START = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t WHITE_ROOKS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'10000001;
constexpr uint64_t BLACK_ROOKS_START = 0b10000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t WHITE_KNIGHTS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'01000010;
constexpr uint64_t BLACK_KNIGHTS_START = 0b01000010'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t WHITE_BISHOPS_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00100100;
constexpr uint64_t BLACK_BISHOPS_START = 0b00100100'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t WHITE_QUEEN_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00001000;
constexpr uint64_t BLACK_QUEEN_START = 0b00001000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
constexpr uint64_t WHITE_KING_START = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00010000;
constexpr uint64_t BLACK_KING_START = 0b00010000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
} // namespace sablefish::constants::bitfields

namespace sablefish::constants::functions
{
constexpr void SetBit(uint64_t& bitboard, sablefish::board::BoardSquare square)
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
constexpr std::array<uint64_t, NUM_SQUARES> GenerateRookMoves()
{
    std::array<uint64_t, NUM_SQUARES> rookMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        uint64_t rookBitboard = 0;
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

// Declarations
constexpr std::array<uint64_t, NUM_SQUARES> ROOK_MOVES = GenerateRookMoves();
} // namespace sablefish::constants::moves
