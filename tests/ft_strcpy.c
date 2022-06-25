#include <stdio.h>
#include <string.h>
#include "tests.h"

static const size_t longStrSize = 10000;

void testStrcpy(void) {

    // SETUP
    char longStr[longStrSize + 1];
    longStr[longStrSize] = '\0';
    memset(longStr, '0', longStrSize);
    const char* strs[] = { "", "1", "Hello World", longStr, NULL };
    char testDest[longStrSize + 1] = {0};
    char myDest[longStrSize + 1] = {0};

    // RUN
    printf("ft_strcpy:");
    for (size_t i = 0; strs[i]; i++) {
        const char* testOutput = strcpy(testDest, strs[i]);
        const char* myOutput = ft_strcpy(myDest, strs[i]);
        if (strcmp(testOutput, myOutput)) {
            printf(" %sKO%s (expected %s, got %s)", RED, RESET, testOutput, myOutput);
        } else {
            printf(" %sOK%s", GREEN, RESET);
        }
    }
    printf("\n");

}