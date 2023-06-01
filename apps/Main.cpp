#include <iostream>

#include <sablefish/Board.hpp>

int main(int argc, char* argv[])
{
    std::cout << "Welcome to Sablefish" << std::endl;

    auto board = sablefish::board::Board();
    std::cout << board.ToString() << std::endl;

    return 0;
}
