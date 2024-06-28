cmake_minimum_required(VERSION 3.10)
project(file_handler VERSION 1.0)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)


include_directories(include)
set(SOURCE_FILES
    src/filehandle.c
    test/test_insert.c
    test/test_fix.c
)

add_executable(test test/test.c src/filehandle.c)

add_executable(test_insert unit_test/test_insert.c src/filehandle.c src/unity.c)
add_executable(test_remove unit_test/test_remove.c src/filehandle.c src/unity.c)
add_executable(test_fix unit_test/test_fix.c src/filehandle.c src/unity.c)
add_executable(test_get_total_lines unit_test/test_get_total_lines.c src/filehandle.c src/unity.c)
add_executable(test_get_line_content unit_test/test_get_line_content.c src/filehandle.c src/unity.c)