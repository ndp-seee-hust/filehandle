#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "file_utils.h"

int main()
{
    char *filename = "/home/ndp/Documents/FileHandler/test_file/test.txt";
    int line = 10;
    int ret = mmap_fremove_line(filename, line);
    if(ret == 0)
    {
        printf("Line removed successfully.\n");
    }
    else
    {
        printf("Failed to remove line.\n");
    }
    
    return ret;
}