#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "tests.h"

static const size_t longStrSize = 10000;

void testWrite(void) {

    // SETUP
    char longStr[longStrSize + 1];
    longStr[longStrSize] = '\0';
    memset(longStr, '0', longStrSize);
    const char* srcs[] = { "", "0", "Hello World!", longStr, NULL };

    // RUN
    printf("ft_write :");
    for (size_t i = 0; srcs[i]; i++) {

        const size_t srcSize = strlen(srcs[i]);

        char testDest[srcSize + 1];
        testDest[srcSize] = '\0';
        char myDest[srcSize + 1];
        myDest[srcSize] = '\0';

        int testFds[2];
        int myFds[2];

        pipe(testFds);
        pipe(myFds);

        write(testFds[1], srcs[i], srcSize);
        ft_write(myFds[1], srcs[i], srcSize);

        ssize_t testRet = read(testFds[0], testDest, srcSize);
        ssize_t myRet = read(myFds[0], myDest, srcSize);

        if (testRet != myRet || strcmp(testDest, myDest)) {
            printf(" %sKO%s (expected %s, got %s)", RED, RESET, testDest, myDest);
        } else {
            printf(" %sOK%s", GREEN, RESET);
        }

        close(testFds[0]); close(testFds[1]);
        close(myFds[0]); close(myFds[1]);
    }

    errno = 0;
    write(42, *srcs, 0);
    const int testErrno = errno;
    errno = 0;
    ft_write(42, *srcs, 0);
    const int myErrno = errno;

    if (testErrno != myErrno) {
        printf(" %sKO%s (expected %d, got %d)", RED, RESET, testErrno, myErrno);
    } else {
        printf(" %sOK%s", GREEN, RESET);
    }

    printf("\n");

}
