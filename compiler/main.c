#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"

int main(int argc, char* argv[])
{
    int res = compile_file("./test.c", "./test", 0);

    if (COMPILER_FILE_COMPILED_OK == res)
    {
        printf("Compiled OK\n");
    } 
    else if (COMPILER_FAILED_WITH_ERRORS == res)
    {
        printf("Compilation failed\n");
    } else 
    {
        printf("Unknown response from compile file\n");
    }

    return 0;
}
