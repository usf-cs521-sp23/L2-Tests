#if 0
    source "${TEST_DIR}/lib/crunner" -lcipher
#endif

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include "cipher.h"

test_start("Ensures status codes are properly reported.");

subtest("Out of bounds",
{
    puts("\n>A in range a-z");
    int c = 'A';
    int status = rotate(&c, 'a', 'z');
    test_assert(status == -1);
    test_assert(c == 'A');

    puts("\n>' ' in range a-z");
    c = ' ';
    status = rotate(&c, 'a', 'z');
    test_assert(status == -1);
    test_assert(c == ' ');

    puts("\n>% in range 0-9");
    c = '%';
    status = rotate(&c, '0', '9');
    test_assert(status == -1);
    test_assert(c == '%');
});

subtest("Invalid range",
{
    puts("\n>Start of range greater than end");
    int c = 'A';
    int status = rotate(&c, 'z', 'a');
    test_assert(status == -2);
    test_assert(c == 'A');

    puts("\n>Not enough space in range (start == end)");
    status = rotate(&c, 'a', 'a');
    test_assert(status == -2);
    test_assert(c == 'A');

    puts("\n>Not evenly divisible");
    status = rotate(&c, '1', '9');
    test_assert(status == -2);
    test_assert(c == 'A');
});


test_end
