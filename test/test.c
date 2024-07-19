#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "filehandle.h"
#include "unity.h"



int main() 
{
    char *filename = "/home/ndp/Documents/FileHandler/test_file/test.txt";
    int line_num = 10;
    char *insert_text = "test insert api file handle";
    int ret = filehandle_insert_v2(filename, line_num, insert_text);
    if(!ret)
    {
        printf("insert successfully!\n");

    }
    else
    {
        printf("Failed!\n");
    }
    
    
    
}
