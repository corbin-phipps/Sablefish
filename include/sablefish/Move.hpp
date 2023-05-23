#ifndef MOVE_HPP
#define MOVE_HPP

#include <cstdint>

// A Move is a 16-bit representation of a chess move that stores important information
// about the move.
// The first 6 bits (64 values) store the source square (or "From" square).
// The second 6 bits store the destination square (or "To" square).
// The remaining 4 bits store flags for special types of moves, as encoded below:
//
// #  | Promotion | Capture | Special 1 | Special 0 | Description
// --------------------------------------------------------------
// 0  |    0          0           0           0       "Quiet" move
// 1  |    0          0           0           1       King side castle
// 2  |    0          0           1           0       Queen side castle
// 3  |    0          0           1           1       Double pawn push
// 4  |    0          1           0           0       Capture
// 5  |    0          1           0           1       En passant capture
// 6  | ---------------------------------------------------------
// 7  | ---------------------------------------------------------
// 8  |    1          0           0           0       Promo (knight)
// 9  |    1          0           0           1       Promo (bishop)
// 10 |    1          0           1           0       Promo (rook)
// 11 |    1          0           1           1       Promo (queen)
// 12 |    1          1           0           0       Promo-capture (knight)
// 13 |    1          1           0           1       Promo-capture (bishop)
// 14 |    1          1           1           0       Promo-capture (rook)
// 15 |    1          1           1           1       Promo-capture (queen)
using Move = uint16_t;

#endif // MOVE_HPP
