#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

int main()
{
    char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";
    char *fix_text = "TEST FIX";
    int line = 3000;
    ffix_line(filename, line, fix_text);
}