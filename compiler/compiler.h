#ifndef __BOBC_COMPILER_H
#define __BOBC_COMPILER_H

#include <stdio.h>


enum
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS,
};

struct compile_process
{
    int flags;      // File compilation flags

    struct compile_process_input_file
    {
        FILE *fp;
        const char *abs_path;
    } file_c;

    FILE *file_out;
};

int compile_file(const char* filename_in, const char* filename_out, int flags);

struct compile_process *compile_process_create(const char *filename_in, const char *filename_out, int flags);

#endif