cmake_minimum_required(VERSION 3.10)
project(file_handler VERSION 1.0)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)


include_directories(include)
set(SOURCE_FILES
    src/file_utils.c
    test/test_insert.c
    test/test_fix.c
)

add_executable(test_insert test/test_insert.c src/file_utils.c)
add_executable(test_fix test/test_fix.c src/file_utils.c)
add_executable(test_remove test/test_remove.c src/file_utils.c)