include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.18.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # for windows
FetchContent_MakeAvailable(googletest)

add_executable(stayout_utests
    test_parser.cpp
    test_sorter.cpp
    test_printer.cpp
)
target_link_libraries(stayout_utests PRIVATE stalker_core GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(stayout_utests
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
