#include <bitset>
#include <iostream>

#include <sablefish/Constants.hpp>
#include <sablefish/Utilities.hpp>

using namespace sablefish::board;
using namespace sablefish::constants;
using namespace sablefish::constants::bitfields;

namespace sablefish::board {
// Returns an array of BoardSquares that are occupied according to the given Bitboard.
const std::vector<BoardSquare>
ConvertBitboardToBoardSquares(const Bitboard bitboard)
{
    std::vector<BoardSquare> boardSquares{};

    std::bitset<NUM_SQUARES> bits(bitboard);
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i]) {
            boardSquares.push_back(static_cast<BoardSquare>(i));
        }
    }

    return boardSquares;
}

// Returns a Bitboard of the given BoardSquares.
const Bitboard
ConvertBoardSquaresToBitboard(const std::vector<BoardSquare>& boardSquares)
{
    std::bitset<NUM_SQUARES> bits;
    for (const auto& boardSquare : boardSquares) {
        bits.set(static_cast<size_t>(boardSquare));
    }

    return bits.to_ullong();
}

// Returns the starting Bitboard of the piece represented by the given PieceType and PieceColor.
const Bitboard
ConvertPieceDataToStartingBitboard(const PieceType pieceType, const PieceColor pieceColor)
{
    if (pieceType == PieceType::Pawn) {
        return (pieceColor == PieceColor::White) ? WHITE_PAWNS_START : BLACK_PAWNS_START;
    } else if (pieceType == PieceType::Rook) {
        return (pieceColor == PieceColor::White) ? WHITE_ROOKS_START : BLACK_ROOKS_START;
    } else if (pieceType == PieceType::Knight) {
        return (pieceColor == PieceColor::White) ? WHITE_KNIGHTS_START : BLACK_KNIGHTS_START;
    } else if (pieceType == PieceType::Bishop) {
        return (pieceColor == PieceColor::White) ? WHITE_BISHOPS_START : BLACK_BISHOPS_START;
    } else if (pieceType == PieceType::Queen) {
        return (pieceColor == PieceColor::White) ? WHITE_QUEEN_START : BLACK_QUEEN_START;
    } else if (pieceType == PieceType::King) {
        return (pieceColor == PieceColor::White) ? WHITE_KING_START : BLACK_KING_START;
    } else { // pieceType == PieceType::Empty
        std::cerr << "PieceType::Empty is unexpected" << std::endl;
        return 0ULL;
    }
}

// Creates a Square object representing the starting Square at a given BoardSquare.
Square
ConvertBoardSquareToStartingSquare(const BoardSquare boardSquare)
{
    const auto& [pieceType, pieceColor] = STARTING_BOARD_SQUARE_DATA.at(static_cast<size_t>(boardSquare));
    return Square({ pieceType, pieceColor }, boardSquare);
}

// Returns a string representation of the given Bitboard as a chess board grid.
std::string
ToString(const Bitboard bitboard)
{
    std::bitset<NUM_SQUARES> bits(bitboard);
    std::string boardString;

    for (int rank = NUM_RANKS - 1; rank >= 0; rank--) {
        for (int file = 0; file < NUM_FILES; file++) {
            auto square = rank * 8 + file;
            char squareChar = bits[square] ? '1' : '0';
            boardString += squareChar;
        }
        boardString += '\n';
    }

    return boardString;
}

// Returns a string representation of the given BoardSquare.
std::string
ToString(const BoardSquare boardSquare)
{
    switch (boardSquare) {
        case BoardSquare::A1: return "A1";
        case BoardSquare::B1: return "B1";
        case BoardSquare::C1: return "C1";
        case BoardSquare::D1: return "D1";
        case BoardSquare::E1: return "E1";
        case BoardSquare::F1: return "F1";
        case BoardSquare::G1: return "G1";
        case BoardSquare::H1: return "H1";
        case BoardSquare::A2: return "A2";
        case BoardSquare::B2: return "B2";
        case BoardSquare::C2: return "C2";
        case BoardSquare::D2: return "D2";
        case BoardSquare::E2: return "E2";
        case BoardSquare::F2: return "F2";
        case BoardSquare::G2: return "G2";
        case BoardSquare::H2: return "H2";
        case BoardSquare::A3: return "A3";
        case BoardSquare::B3: return "B3";
        case BoardSquare::C3: return "C3";
        case BoardSquare::D3: return "D3";
        case BoardSquare::E3: return "E3";
        case BoardSquare::F3: return "F3";
        case BoardSquare::G3: return "G3";
        case BoardSquare::H3: return "H3";
        case BoardSquare::A4: return "A4";
        case BoardSquare::B4: return "B4";
        case BoardSquare::C4: return "C4";
        case BoardSquare::D4: return "D4";
        case BoardSquare::E4: return "E4";
        case BoardSquare::F4: return "F4";
        case BoardSquare::G4: return "G4";
        case BoardSquare::H4: return "H4";
        case BoardSquare::A5: return "A5";
        case BoardSquare::B5: return "B5";
        case BoardSquare::C5: return "C5";
        case BoardSquare::D5: return "D5";
        case BoardSquare::E5: return "E5";
        case BoardSquare::F5: return "F5";
        case BoardSquare::G5: return "G5";
        case BoardSquare::H5: return "H5";
        case BoardSquare::A6: return "A6";
        case BoardSquare::B6: return "B6";
        case BoardSquare::C6: return "C6";
        case BoardSquare::D6: return "D6";
        case BoardSquare::E6: return "E6";
        case BoardSquare::F6: return "F6";
        case BoardSquare::G6: return "G6";
        case BoardSquare::H6: return "H6";
        case BoardSquare::A7: return "A7";
        case BoardSquare::B7: return "B7";
        case BoardSquare::C7: return "C7";
        case BoardSquare::D7: return "D7";
        case BoardSquare::E7: return "E7";
        case BoardSquare::F7: return "F7";
        case BoardSquare::G7: return "G7";
        case BoardSquare::H7: return "H7";
        case BoardSquare::A8: return "A8";
        case BoardSquare::B8: return "B8";
        case BoardSquare::C8: return "C8";
        case BoardSquare::D8: return "D8";
        case BoardSquare::E8: return "E8";
        case BoardSquare::F8: return "F8";
        case BoardSquare::G8: return "G8";
        case BoardSquare::H8: return "H8";
        default: return "Unknown BoardSquare";
    }
}
} // namespace sablefish::board
