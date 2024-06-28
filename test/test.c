#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <sys/resource.h>
#include "filehandle.h"


int main() 
{

    char *filename = "/home/ndp/Documents/FileHandler/test_file/test.txt";
    char *insert_text = "TEST INSERT";
    int line = 2;
    
    char *line_content = malloc(1000);
    int ret = filehandle_get_line_content(filename, line, line_content);
    
    if(ret == 0)
    { 
        printf("%s", line_content);
    }

    else
    {
        printf("Get line content fail!\n");
    }
   
    free(line_content);
}