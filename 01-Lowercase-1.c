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

test_start("Checks basic lowercase letters");

subtest("All lowercase letters",
{
    char initial[] =  "abcdefghijklmnopqrstuvwxyz";
    char expected[] = "nopqrstuvwxyzabcdefghijklm";

    /* Since rotate() assumes integers, we need to put the string in a wider
     * container: */
    int init_storage[27];

    /* We'll copy the result back here. Inefficient, but easy to understand. */
    char result[27] = { 0 };

    for (int i = 0; i < strlen(initial); ++i) {
        init_storage[i] = (int) initial[i];
        rotate(init_storage + i, 'a', 'z');
    }

    for (int i = 0; i < strlen(initial); ++i) {
        result[i] = init_storage[i];
    }


    test_printf("%s\n", result);
    test_assert_str(result, "==", expected, 27);

});

subtest("A subset of the lowercase letters",
{
    char initial[] =  "ijabklmno";
    char expected[] = "vwnoxyzab";

    /* Since rotate() assumes integers, we need to put the string in a wider
     * container: */
    int init_storage[27];

    /* We'll copy the result back here. Inefficient, but easy to understand. */
    char result[27] = { 0 };

    for (int i = 0; i < strlen(initial); ++i) {
        init_storage[i] = (int) initial[i];
        rotate(init_storage + i, 'a', 'z');
    }

    for (int i = 0; i < strlen(initial); ++i) {
        result[i] = init_storage[i];
    }


    test_printf("%s\n", result);
    test_assert_str(result, "==", expected, 27);

});


test_end
