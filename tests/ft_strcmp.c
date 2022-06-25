#include <stdio.h>
#include <string.h>
#include "tests.h"

static const size_t strSize = 10000;

void testStrcmp(void) {

    // SETUP
    char str1[strSize + 1];
    str1[strSize] = '\0';
    memset(str1, '1', strSize);

    char str2[strSize + 1];
    str2[strSize] = '\0';
    str2[strSize - 1] = '0';
    memset(str2, '1', strSize - 1);

    char str3[strSize + 1];
    str3[strSize] = '\0';
    str3[strSize - 1] = '2';
    memset(str3, '1', strSize - 1);

    const char* strs1[] = { str1, str1, str1, NULL };

    const char* strs2[] = { str1, str2, str3, NULL };

    // RUN
    printf("ft_strcmp:");
    for (size_t i = 0; strs1[i]; i++) {

        const int testOutput = strcmp(strs1[i], strs2[i]);
        const int myOutput = ft_strcmp(strs1[i], strs2[i]);
        if (testOutput != myOutput) {
            printf(" %sKO%s (expected %d, got %d)", RED, RESET, testOutput, myOutput);
        } else {
            printf(" %sOK%s", GREEN, RESET);
        }
    }
    printf("\n");

}