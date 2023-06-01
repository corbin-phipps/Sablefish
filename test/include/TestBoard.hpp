#ifndef TEST_BOARD_HPP
#define TEST_BOARD_HPP

#include <sablefish/Board.hpp>

namespace sablefish::board
{
// A TestBoard is a type of Board with extra functionality that is used for
// testing standard Board functionality.
class TestBoard : public Board
{
public:
    void Clear();
    void UpdateSquare(const Square& square);
    bool IsEmpty();
};
} // namespace sablefish::board

#endif // TEST_BOARD_HPP
