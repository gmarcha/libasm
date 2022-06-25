#include <stdio.h>
#include <string.h>
#include "tests.h"

static const size_t longStrSize = 10000;

void testStrlen(void) {

    // SETUP
    char longStr[longStrSize + 1];
    longStr[longStrSize] = '\0';
    memset(longStr, '0', longStrSize);
    const char* strs[] = { "", "1", "Hello World", longStr, NULL };

    // RUN
    printf("ft_strlen:");
    for (size_t i = 0; strs[i]; i++) {
        const size_t testOutput = strlen(strs[i]);
        const size_t myOutput = ft_strlen(strs[i]);
        if (testOutput != myOutput) {
            printf(" %sKO%s (expected %lu, got %lu)", RED, RESET, testOutput, myOutput);
        } else {
            printf(" %sOK%s", GREEN, RESET);
        }
    }
    printf("\n");
}