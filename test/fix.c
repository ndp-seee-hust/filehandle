#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

int main()
{
    char *filename = "/home/ndp/Documents/FileHandler/test_file/test.txt";
    char *fix_text = "TEST FIX";
    int line = 10;
    
    int ret = mmap_ffix_line(filename, line, fix_text);
    if(ret == 0)
    {
        printf("Fixed line successfully.\n");
    }
    else
    {
        printf("Failed to fix line.\n");
    }
}