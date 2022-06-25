#ifndef TESTS_H
#define TESTS_H

#include <unistd.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

size_t ft_strlen(const char*);
char* ft_strcpy(char*, const char*);
int ft_strcmp(const char*, const char*);
ssize_t ft_write(int, const void*, size_t);
ssize_t ft_read(int, void*, size_t);
char* ft_strdup(const char*);

void testStrlen(void);
void testStrcpy(void);
void testStrcmp(void);
void testWrite(void);
void testRead(void);
void testStrdup(void);

#endif
