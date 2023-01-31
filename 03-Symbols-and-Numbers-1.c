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

test_start("Checks symbols and numbers");

subtest("All symbols/numbers",
{
    char initial[] =  " !\"#$%&'()*+,-./0123456789:;<=>?";
    char expected[] = "0123456789:;<=>? !\"#$%&'()*+,-./";

    /* Since rotate() assumes integers, we need to put the string in a wider
     * container: */
    int init_storage[33];

    /* We'll copy the result back here. Inefficient, but easy to understand. */
    char result[33] = { 0 };

    for (int i = 0; i < strlen(initial); ++i) {
        init_storage[i] = (int) initial[i];
        rotate(init_storage + i, ' ', '?');
    }

    for (int i = 0; i < strlen(initial); ++i) {
        result[i] = init_storage[i];
    }


    test_printf("%s\n", result);
    test_assert_str(result, "==", expected, 33);

});

subtest("A subset of symbols/numbers",
{
    char initial[] =  "92354111...-,+& !??";
    char expected[] = ")\"#%$!!!>>>=<;601//";

    /* Since rotate() assumes integers, we need to put the string in a wider
     * container: */
    int init_storage[33];

    /* We'll copy the result back here. Inefficient, but easy to understand. */
    char result[33] = { 0 };

    for (int i = 0; i < strlen(initial); ++i) {
        init_storage[i] = (int) initial[i];
        rotate(init_storage + i, ' ', '?');
    }

    for (int i = 0; i < strlen(initial); ++i) {
        result[i] = init_storage[i];
    }


    test_printf("%s\n", result);
    test_assert_str(result, "==", expected, 33);

});


test_end
