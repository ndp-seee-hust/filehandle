#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <sys/resource.h>
#include "file_utils.h"


int main() 
{

    char *filename = "/home/ndp/Documents/FileHandler/test_file/test.txt";
    char *insert_text = "TEST INSERT";
    int line = 125;

    int ret =  mmap_finsert_line(filename, line, insert_text);
    if (ret == 0) 
    {
        printf("Line inserted successfully.\n");
    } 
    else 
    {
        printf("Failed to insert line.\n");
    }
    return ret;
}