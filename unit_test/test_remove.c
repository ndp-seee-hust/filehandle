#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filehandle.h"
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
    TEST CASES FOR filehandle_remove()
*/

void test_filehandle_remove_FilenameIsNull(void)
{
    int result = filehandle_remove(NULL, 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_remove_LineNumIsZero(void)
{
    int result = filehandle_remove(filename, 0);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_remove_LineNumIsNegative(void)
{
    int result = filehandle_remove(filename, -1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_remove_FileDoesNotExist(void)
{
    int result = filehandle_remove("NonExistFile.txt", 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_remove_LineDoesNotExist(void)
{
    int total_lines = filehandle_get_total_lines(filename);
    int result = filehandle_remove(filename, total_lines+2);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_remove_RemoveExistingLine(void)
{

    int result = filehandle_remove(filename, 2);
    TEST_ASSERT_EQUAL_INT(0, result);

}

void test_filehandle_remove_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = filehandle_remove(filename, 100000);
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute filehandle_remove: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

/*
    TEST CASES FOR filehandle_mmap_remove()
*/
void test_filehandle_mmap_remove_FilenameIsNull(void)
{
    int result = filehandle_mmap_remove(NULL, 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_remove_LineNumIsZero(void)
{
    int result = filehandle_mmap_remove(filename, 0);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_remove_LineNumIsNegative(void)
{
    int result = filehandle_mmap_remove(filename, -1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_remove_FileDoesNotExist(void)
{
    int result = filehandle_mmap_remove("NonExistFile.txt", 1);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_remove_LineDoesNotExist(void)
{
    int total_lines = filehandle_get_total_lines(filename);
    int result = filehandle_mmap_remove(filename, total_lines+2);
    TEST_ASSERT_EQUAL_INT(-1, result);
}

void test_filehandle_mmap_remove_RemoveExistingLine(void)
{

    int result = filehandle_mmap_remove(filename, 2);
    TEST_ASSERT_EQUAL_INT(0, result);

}

void test_filehandle_mmap_remove_Performance(void)
{
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();
    int result = filehandle_mmap_remove(filename, 100000);
    end_time = clock();
    
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("Time taken to execute filehandle_mmap_remove: %f seconds\n", cpu_time_used);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_filehandle_remove_FilenameIsNull);
    RUN_TEST(test_filehandle_remove_LineNumIsZero);
    RUN_TEST(test_filehandle_remove_LineNumIsNegative);
    RUN_TEST(test_filehandle_remove_FileDoesNotExist);
    RUN_TEST(test_filehandle_remove_LineDoesNotExist);
    RUN_TEST(test_filehandle_remove_RemoveExistingLine);
    RUN_TEST(test_filehandle_remove_Performance);

    RUN_TEST(test_filehandle_mmap_remove_FilenameIsNull);
    RUN_TEST(test_filehandle_mmap_remove_LineNumIsZero);
    RUN_TEST(test_filehandle_mmap_remove_LineNumIsNegative);
    RUN_TEST(test_filehandle_mmap_remove_FileDoesNotExist);
    RUN_TEST(test_filehandle_mmap_remove_LineDoesNotExist);
    RUN_TEST(test_filehandle_mmap_remove_RemoveExistingLine);
    RUN_TEST(test_filehandle_mmap_remove_Performance);


    return UNITY_END();
}
