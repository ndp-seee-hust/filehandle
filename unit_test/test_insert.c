#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file_utils.h"
#include "unity.h"

void setUp(void)
{
    
}

void tearDown(void)
{
    
}


char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";


/*
    TEST CASES FOR finsert_line()
*/

void test_finsert_line_FilenameIsNull(void)
{
    int result = finsert_line(NULL, 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_finsert_line_LineNumIsZero(void)
{
    int result = finsert_line(filename, 0, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_finsert_line_LineNumIsNegative(void)
{
    int result = finsert_line(filename, -1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_finsert_line_BufferIsNull(void)
{
    int result = finsert_line(filename, 1, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_finsert_line_FileCannotBeOpened(void)
{
    int result = finsert_line("NonExistFile.txt", 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_finsert_line_LineNumGreaterThanTotalLines(void)
{

    int result = finsert_line(filename, 200000, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_finsert_line_ValidInputs(void)
{

    int result = finsert_line(filename, 2, "Inserted line");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_finsert_line_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = finsert_line(filename, 100000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute finsert_line: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}


/*
  TEST CASES FOR mmap_finsert_line()
*/

void test_mmap_finsert_line_FilenameIsNull(void)
{
    int result = mmap_finsert_line(NULL, 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_finsert_line_LineNumIsZero(void)
{
    int result = mmap_finsert_line(filename, 0, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_finsert_line_LineNumIsNegative(void)
{
    int result = mmap_finsert_line(filename, -1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_finsert_line_BufferIsNull(void)
{
    int result = mmap_finsert_line(filename, 10, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_finsert_line_FileCannotBeOpened(void)
{
    int result = mmap_finsert_line("NonExistFile.txt", 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_finsert_line_LineNumGreaterThanTotalLines(void)
{
    
    int result = mmap_finsert_line(filename, 200000, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_mmap_finsert_line_ValidInputs(void)
{
   
    int result = mmap_finsert_line(filename, 2, "Inserted line");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_mmap_finsert_line_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = mmap_finsert_line(filename, 2, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute mmap_finsert_line: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_finsert_line_FilenameIsNull);
    RUN_TEST(test_finsert_line_LineNumIsZero);
    RUN_TEST(test_finsert_line_LineNumIsNegative);
    RUN_TEST(test_finsert_line_BufferIsNull);
    RUN_TEST(test_finsert_line_FileCannotBeOpened);
    RUN_TEST(test_finsert_line_LineNumGreaterThanTotalLines);
    RUN_TEST(test_finsert_line_ValidInputs);
    RUN_TEST(test_finsert_line_Performance);


    RUN_TEST(test_mmap_finsert_line_FilenameIsNull);
    RUN_TEST(test_mmap_finsert_line_LineNumIsZero);
    RUN_TEST(test_mmap_finsert_line_LineNumIsNegative);
    RUN_TEST(test_mmap_finsert_line_BufferIsNull);
    RUN_TEST(test_mmap_finsert_line_FileCannotBeOpened);
    RUN_TEST(test_mmap_finsert_line_LineNumGreaterThanTotalLines);
    RUN_TEST(test_mmap_finsert_line_ValidInputs);
    RUN_TEST(test_mmap_finsert_line_Performance);
    
    return UNITY_END();
}
