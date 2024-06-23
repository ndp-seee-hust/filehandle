#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "file_utils.h"

int main()
{
    char *filename = "/home/ndp/Documents/FileHandler/test_file/big.txt";
    int line = 20000;
    fremove_line(filename, line);

}