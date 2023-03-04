#include "compiler.h"

int compile_file(const char* filename_in, const char* filename_out, int flags)
{
    struct compile_process *process = compile_process_create(filename_in, filename_out, flags);

    if(!process)
    {
        return COMPILER_FAILED_WITH_ERRORS;
    }

    // perform lexical analysis

    // perform parsing

    // perform code generation
    
    return COMPILER_FILE_COMPILED_OK;
}