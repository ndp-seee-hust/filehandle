#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "unity.h"
#include "file_utils.h"


void setUp(void)
{
    
}

void tearDown(void)
{
    
}

char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";

/*
    TEST CASES FOR ffix_line();
*/

void test_ffix_line_FilenameIsNull(void)
{
    int result = ffix_line(NULL, 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_ffix_line_LineNumIsZero(void)
{
    int result = ffix_line(filename, 0, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_ffix_line_LineNumIsNegative(void)
{
    int result = ffix_line(filename, -1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_ffix_line_BufferIsNull(void)
{
    int result = ffix_line(filename, 2, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_ffix_line_FileDoesNotExist(void)
{
    int result = ffix_line("NonExistFile.txt", 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_ffix_line_LineDoesNotExist(void)
{
    int result = ffix_line(filename, 200000, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_ffix_line_FixExistingLine(void)
{

    int result = ffix_line(filename, 2, "New Line");
    TEST_ASSERT_EQUAL_INT(0, result);

}


void test_ffix_line_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = ffix_line(filename, 100000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute ffix_line: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

/*
    TEST CASES FOR mmap_ffix_line();
*/
void test_mmap_ffix_line_FilenameIsNull(void)
{
    int result = mmap_ffix_line(NULL, 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_ffix_line_LineNumIsZero(void)
{
    int result = mmap_ffix_line(filename, 0, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_ffix_line_LineNumIsNegative(void)
{
    int result = mmap_ffix_line(filename, -1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_ffix_line_BufferIsNull(void)
{
    int result = mmap_ffix_line(filename, 2, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_ffix_line_FileDoesNotExist(void)
{
    int result = mmap_ffix_line("NonExistFile.txt", 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_ffix_line_LineDoesNotExist(void)
{
    int result = mmap_ffix_line(filename, 200000, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_ffix_line_FixExistingLine(void)
{

    int result = mmap_ffix_line(filename, 2, "New Line");
    TEST_ASSERT_EQUAL_INT(0, result);

}

void test_mmap_ffix_line_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = mmap_ffix_line(filename, 100000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute mmap_ffix_line: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_ffix_line_FilenameIsNull);
    RUN_TEST(test_ffix_line_LineNumIsZero);
    RUN_TEST(test_ffix_line_LineNumIsNegative);
    RUN_TEST(test_ffix_line_BufferIsNull);
    RUN_TEST(test_ffix_line_FileDoesNotExist);
    RUN_TEST(test_ffix_line_LineDoesNotExist);
    RUN_TEST(test_ffix_line_FixExistingLine);
    RUN_TEST(test_ffix_line_Performance);

    RUN_TEST(test_mmap_ffix_line_FilenameIsNull);
    RUN_TEST(test_mmap_ffix_line_LineNumIsZero);
    RUN_TEST(test_mmap_ffix_line_LineNumIsNegative);
    RUN_TEST(test_mmap_ffix_line_BufferIsNull);
    RUN_TEST(test_mmap_ffix_line_FileDoesNotExist);
    RUN_TEST(test_mmap_ffix_line_LineDoesNotExist);
    RUN_TEST(test_mmap_ffix_line_FixExistingLine);
    RUN_TEST(test_mmap_ffix_line_Performance);

    return UNITY_END();
}
