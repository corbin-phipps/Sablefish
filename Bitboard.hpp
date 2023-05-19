#pragma once

#include <cstdint>

// A Bitboard is a 64-bit rank-by-rank representation of all board positions. Each color of each piece 
// type has a corresponding Bitboard, where a '0' represents a position not occupied by the piece type,
// and a '1' represents a position occupied by the piece type.
//
// The right-most bit is the Least Significant Bit (LSB) and represents the board position A1.
// The left-most bit is the Most Significant Bit (MSB) and represents the board position H8.
//
// e.g. The starting position of the white pawns take up board positions A2-H2:
// 0000000000000000000000000000000000000000000000001111111100000000
using Bitboard = uint64_t;
