#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "file_utils.h"


int finsert_line(char* filename, int line_num, const char *buffer)
{
    FILE *file = fopen(filename, "r+");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int current_line = 1;
    long int insert_pos = 0;
    char ch;

    while (current_line < line_num && (ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            current_line++;
            insert_pos = ftell(file);
        }
    }

    if (current_line < line_num)
    {
        fclose(file);
        return -1;
    }


    fseek(file, insert_pos, SEEK_SET);


    long int total_left_to_move = 0;
    while (fgetc(file) != EOF) 
    {
        total_left_to_move++;
    }
    fseek(file, insert_pos, SEEK_SET);
    printf("%ld\n", total_left_to_move);
    
    char move_buffer[1024];
    long int ammount_to_grow = strlen(buffer); 
    if (ammount_to_grow >= sizeof(move_buffer))
    {
        fclose(file);
        return -1;
    }

    fread(move_buffer, 1, 1, file);
    if (move_buffer[0] != '\n' && move_buffer[0] != EOF)
    {
        ammount_to_grow++; 
    }
    fseek(file, insert_pos, SEEK_SET); 

    for(;;) 
    {
        uint16_t ammount_to_move = sizeof(move_buffer);
        if (total_left_to_move < ammount_to_move)
        {
            ammount_to_move = total_left_to_move;
        } 

        long int read_pos = insert_pos + total_left_to_move - ammount_to_move;

        fseek(file, read_pos, SEEK_SET);
        fread(move_buffer, ammount_to_move, 1, file);
        if (ferror(file))
        {
            fclose(file);
            return ferror(file);
        } 

        fseek(file, read_pos + ammount_to_grow, SEEK_SET);
        fwrite(move_buffer, ammount_to_move, 1, file);
        if (ferror(file))
        {
            fclose(file);
            return ferror(file);
        }
         
        total_left_to_move -= ammount_to_move;
        if (!total_left_to_move) break;
    }

    fseek(file, insert_pos, SEEK_SET);
    fwrite(buffer, strlen(buffer), 1, file);
    if (ferror(file))
    {
        fclose(file);
        return ferror(file);
    } 
    fwrite("\n", 1, 1, file);
    if (ferror(file))
    {
        fclose(file);
        return ferror(file);
    }

    fclose(file);
    return 0;
}


int fremove_line(char* filename, int line_num)
{
    FILE *file = fopen(filename, "r+");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int current_line = 1;
    long int line_start = 0;
    long int line_end = 0;
    char ch;

    while (current_line < line_num && (ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            current_line++;
            if (current_line == line_num)
            {
                line_start = ftell(file);
            }
        }
    }

    if (current_line < line_num)
    {
        fclose(file);
        return -1;
    }

    line_end = line_start;
    while ((ch = fgetc(file)) != EOF && ch != '\n')
    {
        line_end = ftell(file);
    }
    if (ch == '\n')
    {
        line_end = ftell(file); 
    }

    fseek(file, 0, SEEK_END);
    long int total_left_to_move = ftell(file) - line_end;
    fseek(file, line_end, SEEK_SET);

    char move_buffer[1024];

    for (;;)
    {
        uint16_t ammount_to_move = sizeof(move_buffer);
        if (total_left_to_move < ammount_to_move)
        {
            ammount_to_move = total_left_to_move;
        }

        long int read_pos = line_end + total_left_to_move - ammount_to_move;
       
        fseek(file, read_pos, SEEK_SET);
        fread(move_buffer, ammount_to_move, 1, file);
        if (ferror(file))
        {
            fclose(file);
            return ferror(file);
        }

        fseek(file, read_pos - (line_end - line_start), SEEK_SET);
        fwrite(move_buffer, ammount_to_move, 1, file);
        if (ferror(file))
        {
            fclose(file);
            return ferror(file);
        }

        total_left_to_move -= ammount_to_move;
        if (!total_left_to_move) break;
    }

    fseek(file, 0, SEEK_END);
    long int new_file_size = ftell(file) - (line_end - line_start);
    ftruncate(fileno(file), new_file_size);

    fclose(file);
    return 0;
}

int ffix_line(char* filename, int line_num, const char *buffer)
{
    FILE *file = fopen(filename, "r+");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int current_line = 1;
    long int line_start = 0;
    long int line_end = 0;
    char ch;

    while (current_line < line_num && (ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            current_line++;
            if (current_line == line_num)
            {
                line_start = ftell(file);
            }
        }
    }

    if (current_line < line_num)
    {
        fclose(file);
        return -1; 
    }

    line_end = line_start;
    while ((ch = fgetc(file)) != EOF && ch != '\n')
    {
        line_end = ftell(file);
    }
    if (ch == '\n')
    {
        line_end = ftell(file); 
    }

    long int old_line_length = line_end - line_start;
    long int new_line_length = strlen(buffer);
    long int length_difference = new_line_length - old_line_length;

    
    fseek(file, 0, SEEK_END);
    long int total_left_to_move = ftell(file) - line_end;
    fseek(file, line_end, SEEK_SET);

    char move_buffer[1024];
    length_difference = length_difference + 1;

    if (length_difference != 0)
    {
        for (;;)
        {
            uint16_t ammount_to_move = sizeof(move_buffer);
            if (total_left_to_move < ammount_to_move)
            {
                ammount_to_move = total_left_to_move;
            }

            long int read_pos = line_end + total_left_to_move - ammount_to_move;

            fseek(file, read_pos, SEEK_SET);
            fread(move_buffer, ammount_to_move, 1, file);
            if (ferror(file))
            {
                fclose(file);
                return ferror(file);
            }

            fseek(file, read_pos + length_difference, SEEK_SET);
            fwrite(move_buffer, ammount_to_move, 1, file);
            if (ferror(file))
            {
                fclose(file);
                return ferror(file);
            }

            total_left_to_move -= ammount_to_move;
            if (!total_left_to_move) break;
        }
    }

    fseek(file, line_start, SEEK_SET);
    fwrite(buffer, strlen(buffer), 1, file);
    if (ferror(file))
    {
        fclose(file);
        return ferror(file);
    }

    fputc('\n', file);
    if (ferror(file))
    {
        fclose(file);
        return ferror(file);
    }

    if (length_difference < 0)
    {
        fseek(file, 0, SEEK_END);
        long int new_file_size = ftell(file) + length_difference;
        ftruncate(fileno(file), new_file_size);
    }

    fclose(file);
    return 0;
}