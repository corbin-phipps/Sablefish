#ifndef TEST_BOARD_HPP
#define TEST_BOARD_HPP

#include <sablefish/Board.hpp>

namespace sablefish::board
{
class TestBoard : public Board
{
public:
    void Clear();
    void UpdateSquare(const Square& square);
    bool IsEmpty();
};
} // namespace sablefish::board

#endif // TEST_BOARD_HPP
