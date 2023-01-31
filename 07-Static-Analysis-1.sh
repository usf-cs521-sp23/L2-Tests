source "${TEST_DIR}/lib/funcs.bash"

test_start "Static Analysis" \
    "Checks for programming and stylistic errors with cppcheck and gcc/clang"

if ! ( which cppcheck &> /dev/null ); then
    # "cppcheck is not installed. Please install (as root) with:"
    # "pacman -Sy cppcheck"
    test_end 1
fi

cppcheck --enable=warning,performance \
    --error-exitcode=1 \
    "${TEST_DIR}/../cipher.c" || test_end 1

cc -Wall -Werror "${TEST_DIR}"/../cipher.c || test_end 1

test_end
