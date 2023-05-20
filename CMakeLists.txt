cmake_minimum_required(VERSION 3.25)

project(sablefish 
    LANGUAGES CXX
    VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(apps)
