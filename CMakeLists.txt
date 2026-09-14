cmake_minimum_required(VERSION 3.10.0)
project(stay-out-test-assignment VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(stayout_core
    src/Parser.cpp
    src/Sorter.cpp
    src/Printer.cpp
)
target_include_directories(stayout_core PUBLIC include)

add_executable(stayout_parcer src/main.cpp)
target_link_libraries(stayout_parcer PRIVATE stayout_core)

enable_testing()
add_subdirectory(tests)
