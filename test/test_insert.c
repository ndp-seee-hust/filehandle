#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "file_utils.h"

int main()
{
    char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";
    char *insert_text = "TEST INSERT";
    int line = 20000;
    finsert_line(filename, line, insert_text);

}