#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#ifndef __FILE_HANDLE_H__
#define __FILE_HANDLE_H__
#ifdef __cplusplus
extern "C"
{
#endif

int filehandle_get_total_lines(const char *filename);
int filehandle_get_line_content(const char *filename, int line_num, char *line_content);
int filehandle_insert(char* filename, int line_num, const char *buffer);
int filehandle_insert_v2(char* filename, int line_num, const char *buffer);
int filehandle_remove(char* filename, int line_num);
int filehandle_fix(char* filename, int line_num, const char *buffer);

int filehandle_mmap_insert(char* filename, int line_num, const char *buffer);
int filehandle_mmap_remove(char* filename, int line_num);
int filehandle_mmap_fix(char* filename, int line_num, const char *buffer);

#ifdef __cplusplus
}
#endif

#endif