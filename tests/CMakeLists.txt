add_executable(
    PotterKataTestProg
    test_main.cpp
    potter_tests.cpp
)

target_link_libraries(
    PotterKataTestProg
    PRIVATE
    potter
    Testy::testy
)

target_compile_options(
    PotterKataTestProg
    PRIVATE
        -Wall -Werror -Wextra -pedantic
)

add_test(
    NAME PotterKataTests
    COMMAND PotterKataTestProg
)
