#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "filehandle.h"
#include "unity.h"

void setUp(void)
{
    
}

void tearDown(void)
{
    
}


char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";


/*
    TEST CASES FOR filehandle_insert()
*/

void test_filehandle_insert_FilenameIsNull(void)
{
    int result = filehandle_insert(NULL, 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_insert_LineNumIsZero(void)
{
    int result = filehandle_insert(filename, 0, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_insert_LineNumIsNegative(void)
{
    int result = filehandle_insert(filename, -1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_insert_BufferIsNull(void)
{
    int result = filehandle_insert(filename, 1, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_insert_FileCannotBeOpened(void)
{
    int result = filehandle_insert("NonExistFile.txt", 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_insert_LineNumGreaterThanTotalLines(void)
{

    int result = filehandle_insert(filename, 200000, "Test buffer");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_filehandle_insert_ValidInputs(void)
{

    int result = filehandle_insert(filename, 2, "Inserted line");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_filehandle_insert_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = filehandle_insert(filename, 120000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute filehandle_insert: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_ContentofLineAfterInsert(void)
{
    int result = 0;
    int line_num = 100;
    char *insert_text = "Test insert";
    int ret1 = filehandle_insert(filename, line_num, insert_text);

    char *ContentofLine = malloc(1000);
    int ret2 = filehandle_get_line_content(filename, line_num, ContentofLine);

    for(int i = 0; i < strlen(ContentofLine)-1; i++)
    {
        if(ContentofLine[i] == insert_text[i])
        {
            result = 0;
        }
        else
        {
            result = -1;
            break;
        }
    }
    free(ContentofLine);
    TEST_ASSERT_EQUAL_INT(0, result);
    

}


/*
  TEST CASES FOR filehandle_mmap_insert()
*/

void test_filehandle_mmap_insert_FilenameIsNull(void)
{
    int result = filehandle_mmap_insert(NULL, 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_insert_LineNumIsZero(void)
{
    int result = filehandle_mmap_insert(filename, 0, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_insert_LineNumIsNegative(void)
{
    int result = filehandle_mmap_insert(filename, -1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_insert_BufferIsNull(void)
{
    int result = filehandle_mmap_insert(filename, 10, NULL);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_insert_FileCannotBeOpened(void)
{
    int result = filehandle_mmap_insert("NonExistFile.txt", 1, "Test buffer");
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_insert_LineNumGreaterThanTotalLines(void)
{
    
    int result = filehandle_mmap_insert(filename, 250000, "Test buffer");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_filehandle_mmap_insert_ValidInputs(void)
{
   
    int result = filehandle_mmap_insert(filename, 2, "Inserted line");
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_filehandle_mmap_insert_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = filehandle_mmap_insert(filename, 120000, "Performance test line");
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute filehandle_mmap_insert: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_filehandle_insert_FilenameIsNull);
    RUN_TEST(test_filehandle_insert_LineNumIsZero);
    RUN_TEST(test_filehandle_insert_LineNumIsNegative);
    RUN_TEST(test_filehandle_insert_BufferIsNull);
    RUN_TEST(test_filehandle_insert_FileCannotBeOpened);
    RUN_TEST(test_filehandle_insert_LineNumGreaterThanTotalLines);
    RUN_TEST(test_filehandle_insert_ValidInputs);
    RUN_TEST(test_filehandle_insert_Performance);
    RUN_TEST(test_ContentofLineAfterInsert);

    RUN_TEST(test_filehandle_mmap_insert_FilenameIsNull);
    RUN_TEST(test_filehandle_mmap_insert_LineNumIsZero);
    RUN_TEST(test_filehandle_mmap_insert_LineNumIsNegative);
    RUN_TEST(test_filehandle_mmap_insert_BufferIsNull);
    RUN_TEST(test_filehandle_mmap_insert_FileCannotBeOpened);
    RUN_TEST(test_filehandle_mmap_insert_LineNumGreaterThanTotalLines);
    RUN_TEST(test_filehandle_mmap_insert_ValidInputs);
    RUN_TEST(test_filehandle_mmap_insert_Performance);

    

    
    return UNITY_END();
}
