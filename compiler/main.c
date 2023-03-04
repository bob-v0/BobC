#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"

int main(int argc, char* argv[])
{
    printf("BobC C Compiler, v0.0.1.\n");
    printf("\n");

    if(argc <= 1)
    {
        printf("Error:\n");
        printf("Specify source file\n");
        printf("%s <filename.c>\n", argv[0]);
        return 0;
    }


    int res = compile_file(argv[1], "./test", 0);

    if (COMPILER_FILE_COMPILED_OK == res)
    {
        printf("Compiled OK\n");
    } 
    else if (COMPILER_FAILED_WITH_ERRORS == res)
    {
        printf("Compilation failed\n");
    } 
    else 
    {
        printf("Unknown response from compile file\n");
    }

    return 0;
}
