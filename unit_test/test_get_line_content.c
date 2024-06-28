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

void test_filehandle_get_line_content_null_filename(void)
{
    char line_content[100];
    int result = filehandle_get_line_content(NULL, 1, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_line_content_invalid_line_num(void)
{
    char line_content[100];
    FILE *file = fopen("test_file.txt", "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content("test_file.txt", 0, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_line_content_file_not_exist(void)
{
    char line_content[100];
    int result = filehandle_get_line_content("NonExistFile.txt", 1, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_line_content_null_line_content(void)
{
    FILE *file = fopen("test_file.txt", "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content("test_file.txt", 1, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_line_content_line_exceeds_total_lines(void)
{
    char line_content[100];
    FILE *file = fopen("test_file.txt", "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content("test_file.txt", 4, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_get_line_content_valid_case(void)
{
    char line_content[100];
    FILE *file = fopen("test_file.txt", "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content("test_file.txt", 2, line_content);
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_STRING("Line 2\n", line_content);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_filehandle_get_line_content_null_filename);
    RUN_TEST(test_filehandle_get_line_content_invalid_line_num);
    RUN_TEST(test_filehandle_get_line_content_file_not_exist);
    RUN_TEST(test_filehandle_get_line_content_null_line_content);
    RUN_TEST(test_filehandle_get_line_content_line_exceeds_total_lines);
    RUN_TEST(test_filehandle_get_line_content_valid_case);

    return UNITY_END();
}
