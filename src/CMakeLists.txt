add_library(sablefish STATIC "")

target_sources(sablefish
    PRIVATE
        Board.cpp
        Piece.cpp
        Square.cpp
        Utilities.cpp
)

target_include_directories(sablefish
    PUBLIC
        ../include
)
