#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <array>
#include <cstdint>
#include <unordered_map>

#include "Bitboard.hpp"
#include "Piece.hpp"
#include "Square.hpp"

namespace sablefish::constants
{
using sablefish::board::BoardSquare;
using sablefish::board::PieceType;
using sablefish::board::PieceColor;

constexpr size_t NUM_RANKS = 8;
constexpr size_t NUM_FILES = 8;
constexpr size_t NUM_SQUARES = NUM_RANKS * NUM_FILES;
constexpr size_t NUM_PIECE_TYPES = 6;                  // Pawn, Rook, Knight, Bishop, Queen, King
constexpr size_t NUM_COLORS = 2;                       // White and Black

constexpr size_t RANK_1 = 0;
constexpr size_t RANK_2 = 1;
constexpr size_t RANK_3 = 2;
constexpr size_t RANK_4 = 3;
constexpr size_t RANK_5 = 4;
constexpr size_t RANK_6 = 5;
constexpr size_t RANK_7 = 6;
constexpr size_t RANK_8 = 7;

constexpr size_t FILE_A = 0;
constexpr size_t FILE_B = 1;
constexpr size_t FILE_C = 2;
constexpr size_t FILE_D = 3;
constexpr size_t FILE_E = 4;
constexpr size_t FILE_F = 5;
constexpr size_t FILE_G = 6;
constexpr size_t FILE_H = 7;

// Represents every possible combination of Piece.
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

// Represents the starting Pieces on the board.
constexpr std::array<std::pair<PieceType, PieceColor>, NUM_SQUARES> STARTING_BOARD_SQUARE_DATA = {
    { { PieceType::Rook, PieceColor::White },
      { PieceType::Knight, PieceColor::White },
      { PieceType::Bishop, PieceColor::White },
      { PieceType::Queen, PieceColor::White },
      { PieceType::King, PieceColor::White },
      { PieceType::Bishop, PieceColor::White },
      { PieceType::Knight, PieceColor::White },
      { PieceType::Rook, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Pawn, PieceColor::White },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Empty, PieceColor::Empty },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Pawn, PieceColor::Black },
      { PieceType::Rook, PieceColor::Black },
      { PieceType::Knight, PieceColor::Black },
      { PieceType::Bishop, PieceColor::Black },
      { PieceType::Queen, PieceColor::Black },
      { PieceType::King, PieceColor::Black },
      { PieceType::Bishop, PieceColor::Black },
      { PieceType::Knight, PieceColor::Black },
      { PieceType::Rook, PieceColor::Black } }
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

constexpr Bitboard EMPTY_BITBOARD = 0ULL;
constexpr Bitboard FULL_BITBOARD = 0xFFFFFFFFFFFFFFFFULL;
} // namespace sablefish::constants::bitfields

namespace sablefish::constants::functions
{
constexpr void SetBit(Bitboard& bitboard, const sablefish::board::BoardSquare boardSquare)
{
    bitboard |= (1ULL << static_cast<size_t>(boardSquare));
}

constexpr void ClearBit(Bitboard& bitboard, const sablefish::board::BoardSquare boardSquare)
{
    bitboard &= ~(1ULL << static_cast<size_t>(boardSquare));
}

constexpr sablefish::board::BoardSquare PopLsb(Bitboard& bitboard)
{
    if (bitboard == 0ULL) {
        // TODO: Log error
        return sablefish::board::BoardSquare::A1;
    }
    size_t lsb = 0;
    Bitboard mask = 1ULL;
    while ((bitboard & mask) == 0) {
        mask <<= 1ULL;
        lsb++;
    }

    bitboard &= ~mask;

    return static_cast<sablefish::board::BoardSquare>(lsb);
}
} // namespace sablefish::constants::functions

// This namespace defines the pre-computed lookup tables of pseudo-legal moves
namespace
{
using namespace sablefish::constants;
using namespace sablefish::constants::functions;
using sablefish::board::BoardSquare;

// Definitions
template <sablefish::board::PieceColor pieceColor>
constexpr std::array<Bitboard, NUM_SQUARES>
GeneratePawnNonCaptureMoves()
{
    std::array<Bitboard, NUM_SQUARES> pawnMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard pawnBitboard = 0;
        size_t pawnRank = square / NUM_RANKS;
        size_t pawnFile = square % NUM_FILES;

        if (pieceColor == sablefish::board::PieceColor::White) {
            if (pawnRank < RANK_8) {
                // Quiet move
                BoardSquare targetSquare = static_cast<BoardSquare>(((pawnRank + 1) * NUM_RANKS) + pawnFile);
                SetBit(pawnBitboard, targetSquare);

                // Double Pawn Push
                if (pawnRank == RANK_2) {
                    targetSquare = static_cast<BoardSquare>((RANK_4 * NUM_RANKS) + pawnFile);
                    SetBit(pawnBitboard, targetSquare);
                }
            }
        } else if (pieceColor == sablefish::board::PieceColor::Black) {
            if (pawnRank > RANK_1) {
                // Quiet move
                BoardSquare targetSquare = static_cast<BoardSquare>(((pawnRank - 1) * NUM_RANKS) + pawnFile);
                SetBit(pawnBitboard, targetSquare);

                // Double Pawn Push
                if (pawnRank == RANK_7) {
                    targetSquare = static_cast<BoardSquare>((RANK_5 * NUM_RANKS) + pawnFile);
                    SetBit(pawnBitboard, targetSquare);
                }
            }
        } else {
            // TODO: Log error
        }

        pawnMoves.at(square) = pawnBitboard;
    }

    return pawnMoves;
}

template <sablefish::board::PieceColor pieceColor>
constexpr std::array<Bitboard, NUM_SQUARES>
GeneratePawnCaptureMoves()
{
    std::array<Bitboard, NUM_SQUARES> pawnMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard pawnBitboard = 0;
        size_t pawnRank = square / NUM_RANKS;
        size_t pawnFile = square % NUM_FILES;

        if (pieceColor == sablefish::board::PieceColor::White) {
            if (pawnRank < RANK_8) {
                if (pawnFile > FILE_A) {
                    // Capture left
                    BoardSquare targetSquare = static_cast<BoardSquare>(((pawnRank + 1) * NUM_RANKS) + (pawnFile - 1));
                    SetBit(pawnBitboard, targetSquare);
                }

                if (pawnFile < FILE_H) {
                    // Capture right
                    BoardSquare targetSquare = static_cast<BoardSquare>(((pawnRank + 1) * NUM_RANKS) + (pawnFile + 1));
                    SetBit(pawnBitboard, targetSquare);
                }
            }
        } else if (pieceColor == sablefish::board::PieceColor::Black) {
            if (pawnRank > RANK_1) {
                if (pawnFile > FILE_A) {
                    // Capture left
                    BoardSquare targetSquare = static_cast<BoardSquare>(((pawnRank - 1) * NUM_RANKS) + (pawnFile - 1));
                    SetBit(pawnBitboard, targetSquare);
                }

                if (pawnFile < FILE_H) {
                    // Capture right
                    BoardSquare targetSquare = static_cast<BoardSquare>(((pawnRank - 1) * NUM_RANKS) + (pawnFile + 1));
                    SetBit(pawnBitboard, targetSquare);
                }
            }
        } else {
            // TODO: Log error
        }

        pawnMoves.at(square) = pawnBitboard;
    }

    return pawnMoves;
}

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

        rookMoves.at(square) = rookBitboard;
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

        knightMoves.at(square) = knightBitboard;
    }

    return knightMoves;
}

constexpr std::array<Bitboard, NUM_SQUARES>
GenerateBishopMoves()
{
    std::array<Bitboard, NUM_SQUARES> bishopMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard bishopBitboard = 0;
        size_t bishopRank = square / NUM_RANKS;
        size_t bishopFile = square % NUM_FILES;

        // Positive rank; positive file
        size_t offset = 1;
        while (bishopRank + offset < NUM_RANKS && bishopFile + offset < NUM_FILES) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank + offset) * NUM_RANKS) + (bishopFile + offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Positive rank; negative file
        while (bishopRank + offset < NUM_RANKS && bishopFile >= offset) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank + offset) * NUM_RANKS) + (bishopFile - offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Negative rank; positive file
        while (bishopRank >= offset && bishopFile + offset < NUM_FILES) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank - offset) * NUM_RANKS) + (bishopFile + offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Negative rank; negative file
        while (bishopRank >= offset && bishopFile >= offset) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((bishopRank - offset) * NUM_RANKS) + (bishopFile - offset));
            SetBit(bishopBitboard, targetSquare);
            offset++;
        }

        bishopMoves.at(square) = bishopBitboard;
    }

    return bishopMoves;
}

constexpr std::array<Bitboard, NUM_SQUARES>
GenerateQueenMoves()
{
    std::array<Bitboard, NUM_SQUARES> queenMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard queenBitboard = 0;
        size_t queenRank = square / NUM_RANKS;
        size_t queenFile = square % NUM_FILES;

        // Add rook-style moves
        for (size_t rank = 0; rank < NUM_RANKS; rank++) {
            if (rank != queenRank) {
                BoardSquare targetSquare = static_cast<BoardSquare>((rank * NUM_RANKS) + queenFile);
                SetBit(queenBitboard, targetSquare);
            }
        }

        for (size_t file = 0; file < NUM_FILES; file++) {
            if (file != queenFile) {
                BoardSquare targetSquare = static_cast<BoardSquare>((queenRank * NUM_RANKS) + file);
                SetBit(queenBitboard, targetSquare);
            }
        }

        // Add bishop-style moves
        // Positive rank; positive file
        size_t offset = 1;
        while (queenRank + offset < NUM_RANKS && queenFile + offset < NUM_FILES) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((queenRank + offset) * NUM_RANKS) + (queenFile + offset));
            SetBit(queenBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Positive rank; negative file
        while (queenRank + offset < NUM_RANKS && queenFile >= offset) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((queenRank + offset) * NUM_RANKS) + (queenFile - offset));
            SetBit(queenBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Negative rank; positive file
        while (queenRank >= offset && queenFile + offset < NUM_FILES) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((queenRank - offset) * NUM_RANKS) + (queenFile + offset));
            SetBit(queenBitboard, targetSquare);
            offset++;
        }
        offset = 1;

        // Negative rank; negative file
        while (queenRank >= offset && queenFile >= offset) {
            BoardSquare targetSquare = static_cast<BoardSquare>(((queenRank - offset) * NUM_RANKS) + (queenFile - offset));
            SetBit(queenBitboard, targetSquare);
            offset++;
        }

        queenMoves.at(square) = queenBitboard;
    }

    return queenMoves;
}

// TODO: Need to add castling moves
constexpr std::array<Bitboard, NUM_SQUARES>
GenerateKingMoves()
{
    std::array<Bitboard, NUM_SQUARES> kingMoves{};
    for (size_t square = 0; square < NUM_SQUARES; square++) {
        Bitboard kingBitboard = 0;
        size_t kingRank = square / NUM_RANKS;
        size_t kingFile = square % NUM_FILES;

        // Due to constexpr, at compile time, the compiler thinks "kingRank - 1" could be negative, even if placed within
        // "if (kingRank - 1 >= 0)". These conditional statements allow the code to build with unsigned integer variables (size_t).
        size_t previousKingRank = (kingRank > 0) ? (kingRank - 1) : kingRank;
        size_t previousKingFile = (kingFile > 0) ? (kingFile - 1) : kingFile;
        size_t nextKingRank = (kingRank < NUM_RANKS - 1) ? (kingRank + 1) : kingRank;
        size_t nextKingFile = (kingFile < NUM_FILES - 1) ? (kingFile + 1) : kingFile;

        // Up
        BoardSquare targetSquare = static_cast<BoardSquare>((nextKingRank * NUM_RANKS) + kingFile);
        SetBit(kingBitboard, targetSquare);

        // Down
        targetSquare = static_cast<BoardSquare>((previousKingRank * NUM_RANKS) + kingFile);
        SetBit(kingBitboard, targetSquare);

        // Right
        targetSquare = static_cast<BoardSquare>((kingRank * NUM_RANKS) + nextKingFile);
        SetBit(kingBitboard, targetSquare);

        // Left
        targetSquare = static_cast<BoardSquare>((kingRank * NUM_RANKS) + previousKingFile);
        SetBit(kingBitboard, targetSquare);

        // Up-Right
        targetSquare = static_cast<BoardSquare>((nextKingRank * NUM_RANKS) + nextKingFile);
        SetBit(kingBitboard, targetSquare);

        // Up-Left
        targetSquare = static_cast<BoardSquare>((nextKingRank * NUM_RANKS) + previousKingFile);
        SetBit(kingBitboard, targetSquare);

        // Down-Right
        targetSquare = static_cast<BoardSquare>((previousKingRank * NUM_RANKS) + nextKingFile);
        SetBit(kingBitboard, targetSquare);

        // Down-Left
        targetSquare = static_cast<BoardSquare>((previousKingRank * NUM_RANKS) + previousKingFile);
        SetBit(kingBitboard, targetSquare);

        ClearBit(kingBitboard, static_cast<BoardSquare>(square));
        kingMoves.at(square) = kingBitboard;
    }

    return kingMoves;
}
}

// Declarations
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> PAWN_NON_CAPTURE_MOVES_WHITE = GeneratePawnNonCaptureMoves<sablefish::board::PieceColor::White>();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> PAWN_NON_CAPTURE_MOVES_BLACK = GeneratePawnNonCaptureMoves<sablefish::board::PieceColor::Black>();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> PAWN_CAPTURE_MOVES_WHITE = GeneratePawnCaptureMoves<sablefish::board::PieceColor::White>();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> PAWN_CAPTURE_MOVES_BLACK = GeneratePawnCaptureMoves<sablefish::board::PieceColor::Black>();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> ROOK_MOVES = GenerateRookMoves();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> KNIGHT_MOVES = GenerateKnightMoves();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> BISHOP_MOVES = GenerateBishopMoves();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> QUEEN_MOVES = GenerateQueenMoves();
constexpr std::array<Bitboard, sablefish::constants::NUM_SQUARES> KING_MOVES = GenerateKingMoves();

#endif // CONSTANTS_HPP
