#include <iostream>

#include <sablefish/Game.hpp>

int main(int argc, char* argv[])
{
    std::cout << "Welcome to Sablefish" << std::endl;

    auto game = sablefish::Game();
    std::cout << game.GetBoard()->ToString() << std::endl;

    return 0;
}
