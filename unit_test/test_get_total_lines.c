#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "unity.h"
#include "filehandle.h"



void setUp(void)
{
    
}

void tearDown(void)
{
    
}

void test_filehandle_get_total_lines_null_filename(void)
{
    int result = filehandle_get_total_lines(NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_total_lines_file_not_exist(void)
{
    int result = filehandle_get_total_lines("NonExistFile.txt");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_total_lines_empty_file(void)
{
    const char *filename = "empty_file.txt";
    FILE *file = fopen(filename, "w");
    fclose(file);
    
    int result = filehandle_get_total_lines(filename);
    TEST_ASSERT_EQUAL_INT(0, result);

    remove(filename); 
}

void test_filehandle_get_total_lines_single_line(void)
{
    const char *filename = "single_line.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "a single line");
    fclose(file);

    int result = filehandle_get_total_lines(filename);
    TEST_ASSERT_EQUAL_INT(1, result);

    remove(filename);
}

void test_filehandle_get_total_lines_multiple_lines(void)
{
    const char *filename = "multiple_lines.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_total_lines(filename);
    TEST_ASSERT_EQUAL_INT(3, result);

    remove(filename);
}

void test_filehandle_get_total_lines_with_trailing_newline(void)
{
    const char *filename = "Trailing_newline.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_total_lines(filename);
    TEST_ASSERT_EQUAL_INT(3, result);

    remove(filename); 
}
void test_filehandle_get_total_lines_with_no_trailing_newline(void)
{
    const char *filename = "No_trailing_newline.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3");
    fclose(file);

    int result = filehandle_get_total_lines(filename);
    TEST_ASSERT_EQUAL_INT(3, result);

    remove(filename); 
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_filehandle_get_total_lines_null_filename);
    RUN_TEST(test_filehandle_get_total_lines_file_not_exist);
    RUN_TEST(test_filehandle_get_total_lines_empty_file);
    RUN_TEST(test_filehandle_get_total_lines_single_line);
    RUN_TEST(test_filehandle_get_total_lines_multiple_lines);
    RUN_TEST(test_filehandle_get_total_lines_with_trailing_newline);
    RUN_TEST(test_filehandle_get_total_lines_with_no_trailing_newline);

    return UNITY_END();
}
