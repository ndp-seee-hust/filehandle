#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "file_utils.h"
#include "unity.h"


char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";

char* read_file_content(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc(length + 1);
    if (content)
    {
        fread(content, 1, length, file);
        content[length] = '\0';
    }

    fclose(file);
    return content;
}

void setUp(void)
{
    
}

void tearDown(void)
{
    
}

/*
    TEST CASES FOR fremove_line()
*/

void test_fremove_line_FilenameIsNull(void)
{
    int result = fremove_line(NULL, 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_fremove_line_LineNumIsZero(void)
{
    int result = fremove_line(filename, 0);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_fremove_line_LineNumIsNegative(void)
{
    int result = fremove_line(filename, -1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_fremove_line_FileDoesNotExist(void)
{
    int result = fremove_line("NonExistFile.txt", 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_fremove_line_LineDoesNotExist(void)
{
    int result = fremove_line(filename, 200000);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_fremove_line_RemoveExistingLine(void)
{

    int result = fremove_line(filename, 2);
    TEST_ASSERT_EQUAL_INT(0, result);

}

void test_fremove_line_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = fremove_line(filename, 100000);
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute fremove_line: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

/*
    TEST CASES FOR mmap_fremove_line()
*/
void test_mmap_fremove_line_FilenameIsNull(void)
{
    int result = mmap_fremove_line(NULL, 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_fremove_line_LineNumIsZero(void)
{
    int result = mmap_fremove_line(filename, 0);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_fremove_line_LineNumIsNegative(void)
{
    int result = mmap_fremove_line(filename, -1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_fremove_line_FileDoesNotExist(void)
{
    int result = mmap_fremove_line("NonExistFile.txt", 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_fremove_line_LineDoesNotExist(void)
{
    int result = mmap_fremove_line(filename, 200000);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_fremove_line_RemoveExistingLine(void)
{

    int result = mmap_fremove_line(filename, 2);
    TEST_ASSERT_EQUAL_INT(0, result);

}

void test_mmap_fremove_line_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = mmap_fremove_line(filename, 100000);
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute mmap_fremove_line: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_fremove_line_FilenameIsNull);
    RUN_TEST(test_fremove_line_LineNumIsZero);
    RUN_TEST(test_fremove_line_LineNumIsNegative);
    RUN_TEST(test_fremove_line_FileDoesNotExist);
    RUN_TEST(test_fremove_line_LineDoesNotExist);
    RUN_TEST(test_fremove_line_RemoveExistingLine);
    RUN_TEST(test_fremove_line_Performance);

    RUN_TEST(test_mmap_fremove_line_FilenameIsNull);
    RUN_TEST(test_mmap_fremove_line_LineNumIsZero);
    RUN_TEST(test_mmap_fremove_line_LineNumIsNegative);
    RUN_TEST(test_mmap_fremove_line_FileDoesNotExist);
    RUN_TEST(test_mmap_fremove_line_LineDoesNotExist);
    RUN_TEST(test_mmap_fremove_line_RemoveExistingLine);
    RUN_TEST(test_mmap_fremove_line_Performance);


    return UNITY_END();
}
