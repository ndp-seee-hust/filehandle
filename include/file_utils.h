#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#ifndef __FILE_UTILS_H__
#define __FILE_UTILS_H__
#ifdef __cplusplus
extern "C"
{
#endif

int finsert_line(char* filename, int line_num, const char *buffer);
int fremove_line(char* filename, int line_num);
int ffix_line(char* filename, int line_num, const char *buffer);

int mmap_finsert_line(char* filename, int line_num, const char *buffer);
int mmap_fremove_line(char* filename, int line_num);
int mmap_ffix_line(char* filename, int line_num, const char *buffer);

#ifdef __cplusplus
}
#endif

#endif