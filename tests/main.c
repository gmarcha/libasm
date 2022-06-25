#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int main(void) {

    printf(YELLOW);
    printf("==============================================\n");
    printf("██╗     ██╗██████╗  █████╗ ███████╗███╗   ███╗\n");
    printf("██║     ██║██╔══██╗██╔══██╗██╔════╝████╗ ████║\n");
    printf("██║     ██║██████╔╝███████║███████╗██╔████╔██║\n");
    printf("██║     ██║██╔══██╗██╔══██║╚════██║██║╚██╔╝██║\n");
    printf("███████╗██║██████╔╝██║  ██║███████║██║ ╚═╝ ██║\n");
    printf("╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n");
    printf("==============================================\n");
    printf(RESET);
                                              
    testStrlen();
    testStrcpy();
    testStrcmp();
    testWrite();
    testRead();
    testStrdup();
    return EXIT_SUCCESS;
}