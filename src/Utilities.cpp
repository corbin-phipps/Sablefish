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

// Displays a Bitboard as a chess board
std::string
ToBoard(const Bitboard bitboard)
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

// Displays a Bitboard as a bit string
std::string
ToString(const Bitboard bitboard)
{
    std::bitset<NUM_SQUARES> bits(bitboard);
    std::string bitsString(bits.to_string());
    for (size_t i = bitsString.length() - 8; i > 0; i -= 8) {
        bitsString.insert(i, "'");
    }

    return "0b" + bitsString;
}
} // namespace sablefish::board
