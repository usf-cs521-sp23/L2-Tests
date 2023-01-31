source "${TEST_DIR}/lib/funcs.bash"

run_timeout=5

reference_run cat "${TEST_DIR}/inputs/sky_seasoning.txt"

test_start "Encrypting a large text file"

run ./cipher < ${TEST_DIR}/inputs/sky_encrypted.txt

compare_outputs

test_end
