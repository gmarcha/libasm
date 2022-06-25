#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tests.h"

static const size_t longStrSize = 10000;

void testStrdup(void) {

    // SETUP
    char longStr[longStrSize + 1];
    longStr[longStrSize] = '\0';
    memset(longStr, '0', longStrSize);
    const char* strs[] = { "", "1", "Hello World", longStr, NULL };

    // RUN
    printf("ft_strdup:");
    for (size_t i = 0; strs[i]; i++) {
        char* testOutput = strdup(strs[i]);
        char* myOutput = ft_strdup(strs[i]);
        if (testOutput == NULL && myOutput == NULL) {
            printf(" %sOK%s", GREEN, RESET);
        } else if (testOutput == NULL || myOutput == NULL || strcmp(testOutput, myOutput)) {
            printf(" %sKO%s (expected %s, got %s)", RED, RESET, testOutput, myOutput);
        } else {
            printf(" %sOK%s", GREEN, RESET);
        }
        free(testOutput); free(myOutput);
    }
    printf("\n");

}
