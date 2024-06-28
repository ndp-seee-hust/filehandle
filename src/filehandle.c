#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "filehandle.h"

#define BUFFER_DATA_MOVE 1024

int filehandle_get_total_lines(const char *filename)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }
    
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int lines = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            lines++;
        }
    }

    fseek(file, -1, SEEK_END);
    if (fgetc(file) != '\n')
    {
        lines++;
    }

    fclose(file);
    return lines;
}

int filehandle_get_line_content(const char *filename, int line_num, char *line_content)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }
    
    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }
    
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    if (!line_content)
    {
        perror("Error allocating memory");
        fclose(file);
        return -1;
    }

    int total_lines = filehandle_get_total_lines(filename);
   
    if(line_num > total_lines)
    {
        return -1;
    }

    int current_line = 1;
    long line_length = strlen(line_content);
    while (fgets(line_content, line_length, file))
    {
        if (current_line == line_num)
        {
            fclose(file);
            return 0;
        }
        current_line++;
    }
    fclose(file);
    return 0;
}

int filehandle_insert(char* filename, int line_num, const char *buffer)
{

    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }

    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }
    
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: buffer is NULL\n");
        return -1;
    }
   
    FILE *file = fopen(filename, "r+");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int current_line = 1;
    long insert_pos = 0;
    char ch;
    char move_buffer[BUFFER_DATA_MOVE];
    
    while (current_line < line_num && (ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            current_line++;
            insert_pos = ftell(file);
        }
    }

    while (current_line < line_num)
    {
        fputc('\n', file);
        current_line++;
    }

    insert_pos = ftell(file);

    fseek(file, insert_pos, SEEK_SET);


    long total_left_to_move = 0;
    while (fgetc(file) != EOF) 
    {
        total_left_to_move++;
    }
    fseek(file, insert_pos, SEEK_SET);
    
    long ammount_to_grow = strlen(buffer); 
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

        long read_pos = insert_pos + total_left_to_move - ammount_to_move;

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


int filehandle_remove(char* filename, int line_num)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }
    
    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }
    
    FILE *file = fopen(filename, "r+");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int current_line = 1;
    long line_start = 0;
    long line_end = 0;
    char ch;
    char move_buffer[BUFFER_DATA_MOVE];

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
    long total_left_to_move = ftell(file) - line_end;
    fseek(file, line_end, SEEK_SET);


    for (;;)
    {
        uint16_t ammount_to_move = sizeof(move_buffer);
        if (total_left_to_move < ammount_to_move)
        {
            ammount_to_move = total_left_to_move;
        }

        long read_pos = line_end + total_left_to_move - ammount_to_move;
       
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
    long new_file_size = ftell(file) - (line_end - line_start);
    ftruncate(fileno(file), new_file_size);

    fclose(file);
    return 0;
}

int filehandle_fix(char* filename, int line_num, const char *buffer)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }

    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }
    
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: buffer is NULL\n");
        return -1;
    }

    FILE *file = fopen(filename, "r+");
    if (!file)
    {
        perror("Error opening file");
        return -1;
    }

    int current_line = 1;
    long line_start = 0;
    long line_end = 0;
    char ch;
    char move_buffer[BUFFER_DATA_MOVE];
    
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

    long old_line_length = line_end - line_start;
    long new_line_length = strlen(buffer);
    long length_difference = new_line_length - old_line_length;

    
    fseek(file, 0, SEEK_END);
    long total_left_to_move = ftell(file) - line_end;
    fseek(file, line_end, SEEK_SET);

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

            long read_pos = line_end + total_left_to_move - ammount_to_move;

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
        long new_file_size = ftell(file) + length_difference;
        ftruncate(fileno(file), new_file_size);
    }

    fclose(file);
    return 0;
}

int filehandle_mmap_insert(char* filename, int line_num, const char *buffer)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }

    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }

    if (buffer == NULL)
    {
        fprintf(stderr, "Error: buffer is NULL\n");
        return -1;
    }
    
    int fd;
    struct stat sb;
    char *file_contents;
    size_t file_size;
    int current_line = 1;
    off_t insert_pos = 0;
    long total_left_to_move = 0;
    size_t amount_to_grow = strlen(buffer);



    fd = open(filename, O_RDWR);
    if (fd == -1) 
    {
        perror("Error opening file");
        return -1;
    }

    if (fstat(fd, &sb) == -1) 
    {
        perror("fstat");
        close(fd);
        return -1;
    }

    file_size = sb.st_size;

    file_contents = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_contents == MAP_FAILED) 
    {
        perror("mmap");
        close(fd);
        return -1;
    }

    for (off_t i = 0; i < file_size; ++i) 
    {
        if (file_contents[i] == '\n') 
        {
            ++current_line;
            insert_pos = i + 1;
        }
        if (current_line == line_num)
            break;
    }

    // if (current_line < line_num) 
    // {
    //     munmap(file_contents, file_size);
    //     close(fd);
    //     return -1;
    // }

    total_left_to_move = file_size - insert_pos;

    memmove(file_contents + insert_pos + amount_to_grow + 1, file_contents + insert_pos, total_left_to_move);

    memcpy(file_contents + insert_pos, buffer, amount_to_grow);
    file_contents[insert_pos + amount_to_grow] = '\n';

    if (munmap(file_contents, file_size) == -1) 
    {
        perror("munmap");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

int filehandle_mmap_remove(char* filename, int line_num)
{
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }

    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }

    int fd = open(filename, O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1)
    {
        perror("Error getting the file size");
        close(fd);
        return -1;
    }
    size_t length = sb.st_size;

    char *file_content = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_content == MAP_FAILED)
    {
        perror("Error mapping the file");
        close(fd);
        return -1;
    }

    int current_line = 1;
    long line_start = 0;
    long line_end = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (current_line == line_num)
        {
            if (line_start == 0)
            {
                line_start = i;
            }
            if (file_content[i] == '\n' || i == length - 1)
            {
                line_end = i + 1;
                break;
            }
        }
        if (file_content[i] == '\n')
        {
            current_line++;
        }
    }

    if (current_line < line_num)
    {
        munmap(file_content, length);
        close(fd);
        return -1;
    }

    size_t new_length = length - (line_end - line_start);

    memmove(&file_content[line_start], &file_content[line_end], length - line_end);

    if (ftruncate(fd, new_length) == -1)
    {
        perror("Error truncating the file");
        munmap(file_content, length);
        close(fd);
        return -1;
    }

    if (munmap(file_content, length) == -1)
    {
        perror("Error unmapping the file");
    }
    close(fd);
    return 0;
}

int filehandle_mmap_fix(char* filename, int line_num, const char *buffer)
{
    
    if (filename == NULL)
    {
        fprintf(stderr, "Error: filename is NULL\n");
        return -1;
    }
    if (line_num <= 0)
    {
        fprintf(stderr, "Error: line_num must be greater than 0\n");
        return -1;
    }
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: buffer is NULL\n");
        return -1;
    }

   
    int fd = open(filename, O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1)
    {
        perror("Error getting the file size");
        close(fd);
        return -1;
    }
    size_t length = sb.st_size;

    char *file_content = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_content == MAP_FAILED)
    {
        perror("Error mapping the file");
        close(fd);
        return -1;
    }

    int current_line = 1;
    long line_start = 0;
    long line_end = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (current_line == line_num)
        {
            if (line_start == 0)
            {
                line_start = i;
            }
            if (file_content[i] == '\n' || i == length - 1)
            {
                line_end = i + 1;
                break;
            }
        }
        if (file_content[i] == '\n')
        {
            current_line++;
        }
    }

    if (current_line < line_num)
    {
        munmap(file_content, length);
        close(fd);
        return -1;
    }

    long old_line_length = line_end - line_start;
    long new_line_length = strlen(buffer) + 1;
    long length_difference = new_line_length - old_line_length;

    if (length_difference > 0)
    {
    
        if (ftruncate(fd, length + length_difference) == -1)
        {
            perror("Error extending the file");
            munmap(file_content, length);
            close(fd);
            return -1;
        }

        munmap(file_content, length);
        length += length_difference;
        file_content = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (file_content == MAP_FAILED)
        {
            perror("Error remapping the file");
            close(fd);
            return -1;
        }
    }

    if (length_difference != 0)
    {
        memmove(&file_content[line_start + new_line_length], &file_content[line_end], length - line_end - length_difference);
    }

    memcpy(&file_content[line_start], buffer, strlen(buffer));
    file_content[line_start + strlen(buffer)] = '\n';

    if (length_difference < 0)
    {
        if (ftruncate(fd, length + length_difference) == -1)
        {
            perror("Error truncating the file");
            munmap(file_content, length);
            close(fd);
            return -1;
        }
    }

    if (munmap(file_content, length) == -1)
    {
        perror("Error unmapping the file");
    }
    close(fd);
    return 0;
}