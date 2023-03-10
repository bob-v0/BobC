#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"


struct compile_process *compile_process_create(const char *filename_in, const char *filename_out, int flags)
{
    FILE *file_in = fopen(filename_in, "r");

    if (!file_in)
    {
        return NULL;
    }

    FILE *file_out = NULL;
    if (filename_out)
    {
        file_out = fopen(filename_out, "w");
        if(!file_out)
        {
            return NULL;
        }
    }

    struct compile_process *process = calloc(1, sizeof(struct compile_process));
    process->flags = flags;
    process->file_c.fp = file_in;
    process->file_out = file_out;

    return process;
}

char compile_process_next_char(struct lex_process *lex_process)
{
    struct compile_process *compiler = lex_process->compiler;
    compiler->pos.col += 1;
    char c = getc(compiler->file_c.fp);

    if ('\n' == c)
    {
        compiler->pos.line +=1;
        compiler->pos.col = 1;
    }

    return c;
}

char compile_process_peek_char(struct lex_process *lex_process)
{
    struct compile_process *compiler = lex_process->compiler;
    char c = getc(compiler->file_c.fp);
    ungetc(c, compiler->file_c.fp);
    return c;
}

void compile_process_push_char(struct lex_process *lex_process, char c)
{
    struct compile_process *compiler = lex_process->compiler;
    ungetc(c, compiler->file_c.fp);
}