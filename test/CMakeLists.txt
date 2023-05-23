include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.10
)
FetchContent_MakeAvailable(catch2)

add_executable(sablefish-test
    Main.cpp
    TestBoard.cpp
    TestConversions.cpp
    TestPrecomputedMoveGeneration.cpp
    TestPiece.cpp
    TestSquare.cpp
)

target_link_libraries(sablefish-test PRIVATE sablefish Catch2::Catch2)

# Add the tests to the CTest framework
include(CTest)
add_test(NAME sablefish-tests COMMAND sablefish-test)
