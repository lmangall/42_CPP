#!/bin/bash

echo "Compiling the program..."
make || { echo "Compilation failed"; exit 1; }


# Test 1
echo -n "Running Test 1... "
echo "This is test file number 1. It contains some text that will be replaced." > "test_input_1.txt"
STRING_TO_REPLACE="text"
REPLACEMENT_STRING="TEXT"
echo "This is test file number 1. It contains some TEXT that will be replaced." > expected_output_1.txt
./Sed_is_for_losers "test_input_1.txt" "$STRING_TO_REPLACE" "$REPLACEMENT_STRING"
if cmp -s "expected_output_1.txt" "test_input_1.txt.replace"; then
    echo -e "\e[32mTest 1 Passed: The actual output matches the expected output.\e[0m"
else
    echo "Test 1 Failed: The actual output does not match the expected output."
    echo "Differences:"
    diff "expected_output_1.txt" "test_input_1.txt.replace"
fi

# Test 2 replaces whitespace characters (tabs and spaces) with underscores.
echo -n "Running Test 2... "
echo "This	is	test	file	number	2.	It	contains	some	text	that	will	be	replaced." > "test_input_2.txt"
STRING_TO_REPLACE="	"
REPLACEMENT_STRING="_"
echo "This_is_test_file_number_2._It_contains_some_text_that_will_be_replaced." > expected_output_2.txt
./Sed_is_for_losers "test_input_2.txt" "$STRING_TO_REPLACE" "$REPLACEMENT_STRING"
if cmp -s "expected_output_2.txt" "test_input_2.txt.replace"; then
    echo -e "\e[32mTest 2 Passed: The actual output matches the expected output.\e[0m"
else
    echo "Test 2 Failed: The actual output does not match the expected output."
    echo "Differences:"
    diff "expected_output_2.txt" "test_input_2.txt.replace"
fi

# Test 3 creates a file with only whitespace characters and replaces them with underscores.
echo -n "Running Test 3... "
echo -n "    " > "test_input_3.txt"
STRING_TO_REPLACE=" "
REPLACEMENT_STRING="_"
echo -n "____" > expected_output_3.txt
./Sed_is_for_losers "test_input_3.txt" "$STRING_TO_REPLACE" "$REPLACEMENT_STRING"
if cmp -s "expected_output_3.txt" "test_input_3.txt.replace"; then
    echo -e "\e[32mTest 3 Passed: The actual output matches the expected output.\e[0m"
else
    echo "Test 3 Failed: The actual output does not match the expected output."
    echo "Differences:"
    diff "expected_output_3.txt" "test_input_3.txt.replace"
fi

# Test 4 creates a file with newline characters and replaces them with the spaces.
echo -n "Running Test 4... "
echo -en "This is a\\nmultiline\\nfile." > "test_input_4.txt" # Escape \n
STRING_TO_REPLACE=$'\n'
REPLACEMENT_STRING=" "
echo -en "This is a multiline file." > expected_output_4.txt
./Sed_is_for_losers "test_input_4.txt" "$STRING_TO_REPLACE" "$REPLACEMENT_STRING"
if cmp -s "expected_output_4.txt" "test_input_4.txt.replace"; then
    echo -e "\e[32mTest 4 Passed: The actual output matches the expected output.\e[0m"
else
    echo "Test 4 Failed: The actual output does not match the expected output."
    echo "Differences:"
    diff "expected_output_4.txt" "test_input_4.txt.replace"
fi


# Test 5 creates a file and then changes its permissions to remove read access before attempting to replace contents
echo -n "Running Test 5... "
echo "This is test file number 5. The program should not be able to read this file." > "test_input_5.txt"
STRING_TO_REPLACE="should"
REPLACEMENT_STRING="SHOULD"
chmod 000 "test_input_5.txt" # No permissions
./Sed_is_for_losers "test_input_5.txt" "$STRING_TO_REPLACE" "$REPLACEMENT_STRING"
if [ ! -f "test_input_5.txt.replace" ]; then #"if the file test_input_5.txt.replace does not exist consider Test 5 passed
    echo -e "\e[32mTest 5 Passed: Program handled the lack of read permissions gracefully.\e[0m"
else
    echo "Test 5 Failed: The program should not generate an output file when it cannot read the input file."
fi
chmod 644 "test_input_5.txt"


# Clean up
echo "Cleaning up..."
rm -f test_input_*
rm -f expected_output_*

# Uncomment the following line if you want to remove the compiled program as well
# make fclean
