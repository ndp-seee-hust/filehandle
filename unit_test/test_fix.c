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

char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";

/*
    TEST CASES FOR filehandle_fix();
*/

void test_filehandle_fix_FilenameIsNull(void)
{
    int result = filehandle_fix(NULL, 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_fix_LineNumIsZero(void)
{
    int result = filehandle_fix(filename, 0, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_fix_LineNumIsNegative(void)
{
    int result = filehandle_fix(filename, -1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_fix_BufferIsNull(void)
{
    int result = filehandle_fix(filename, 2, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_fix_FileDoesNotExist(void)
{
    int result = filehandle_fix("NonExistFile.txt", 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_fix_LineDoesNotExist(void)
{
    int total_lines = filehandle_get_total_lines(filename);
    int result = filehandle_fix(filename, total_lines+2, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_fix_FixExistingLine(void)
{

    int result = filehandle_fix(filename, 2, "New Line");
    TEST_ASSERT_EQUAL_INT(0, result);

}


void test_filehandle_fix_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = filehandle_fix(filename, 100000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute filehandle_fix: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

/*
    TEST CASES FOR filehandle_mmap_fix();
*/
void test_filehandle_mmap_fix_FilenameIsNull(void)
{
    int result = filehandle_mmap_fix(NULL, 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_fix_LineNumIsZero(void)
{
    int result = filehandle_mmap_fix(filename, 0, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_fix_LineNumIsNegative(void)
{
    int result = filehandle_mmap_fix(filename, -1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_fix_BufferIsNull(void)
{
    int result = filehandle_mmap_fix(filename, 2, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_fix_FileDoesNotExist(void)
{
    int result = filehandle_mmap_fix("NonExistFile.txt", 1, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_fix_LineDoesNotExist(void)
{
    int total_lines = filehandle_get_total_lines(filename);
    int result = filehandle_mmap_fix(filename, total_lines+2, "New Line");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_fix_FixExistingLine(void)
{

    int result = filehandle_mmap_fix(filename, 2, "New Line");
    TEST_ASSERT_EQUAL_INT(0, result);

}

void test_filehandle_mmap_fix_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = filehandle_mmap_fix(filename, 100000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute filehandle_mmap_fix: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_filehandle_fix_FilenameIsNull);
    RUN_TEST(test_filehandle_fix_LineNumIsZero);
    RUN_TEST(test_filehandle_fix_LineNumIsNegative);
    RUN_TEST(test_filehandle_fix_BufferIsNull);
    RUN_TEST(test_filehandle_fix_FileDoesNotExist);
    RUN_TEST(test_filehandle_fix_LineDoesNotExist);
    RUN_TEST(test_filehandle_fix_FixExistingLine);
    RUN_TEST(test_filehandle_fix_Performance);

    RUN_TEST(test_filehandle_mmap_fix_FilenameIsNull);
    RUN_TEST(test_filehandle_mmap_fix_LineNumIsZero);
    RUN_TEST(test_filehandle_mmap_fix_LineNumIsNegative);
    RUN_TEST(test_filehandle_mmap_fix_BufferIsNull);
    RUN_TEST(test_filehandle_mmap_fix_FileDoesNotExist);
    RUN_TEST(test_filehandle_mmap_fix_LineDoesNotExist);
    RUN_TEST(test_filehandle_mmap_fix_FixExistingLine);
    RUN_TEST(test_filehandle_mmap_fix_Performance);

    return UNITY_END();
}
