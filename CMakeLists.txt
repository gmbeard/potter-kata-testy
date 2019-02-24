cmake_minimum_required(VERSION 3.8)

project(PotterKata CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/testy/cmake)

add_library(
    potter
    src/potter.cpp
)

target_include_directories(
    potter
    PUBLIC
    include
)

target_compile_features(
    potter
    PUBLIC
    cxx_std_14
)

target_compile_options(
    potter
    PRIVATE
    -Wall -Werror -Wextra -pedantic
)

include(Testy)

enable_testing()
add_subdirectory(tests)
