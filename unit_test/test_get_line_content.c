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
    char *line_content = malloc(1000);
    int result = filehandle_get_line_content(NULL, 1, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
    free(line_content);
}

void test_filehandle_get_line_content_invalid_line_num(void)
{
    const char *filename = "test_file.txt";
    char *line_content = malloc(1000);
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content(filename, 0, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
    free(line_content);
    remove(filename);
}

void test_filehandle_get_line_content_file_not_exist(void)
{
    char *line_content = malloc(1000);
    int result = filehandle_get_line_content("NonExistFile.txt", 1, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
    free(line_content);
}

void test_filehandle_get_line_content_null_line_content(void)
{
    const char *filename = "test_file.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content(filename, 1, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
    remove(filename);
}

void test_filehandle_get_line_content_line_exceeds_total_lines(void)
{
    const char *filename = "test_file.txt";
    char *line_content = malloc(1000);
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content(filename, 4, line_content);
    TEST_ASSERT_EQUAL_INT(-1, result);
    free(line_content);
    remove(filename);
}

void test_filehandle_get_line_content_valid_case(void)
{
    const char *filename = "test_file.txt";
    char *line_content = malloc(1000);
    FILE *file = fopen(filename, "w");
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    int result = filehandle_get_line_content(filename, 2, line_content);
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_STRING("Line 2\n", line_content);
    free(line_content);
    remove(filename);
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
