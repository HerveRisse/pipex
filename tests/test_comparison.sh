#!/bin/bash

setup_test_files() {
	echo "Hello World
Test line
Another line
Final line" > infile.txt
}

test_simple_pipe() {
	echo "Test 1 (cat | grep):"
	echo "Shell:" 
	< infile.txt cat | grep Hello > shell1.txt && cat shell1.txt
	echo "Pipex:" 
	./pipex infile.txt "cat" "grep Hello" pipex1.txt && cat pipex1.txt
}

test_command_pipe() {
	echo "\nTest 2 (ls | wc):"
	echo "Shell:" 
	< infile.txt ls -l | wc -l > shell2.txt && cat shell2.txt
	echo "Pipex:" 
	./pipex infile.txt "ls -l" "wc -l" pipex2.txt && cat pipex2.txt
}

cleanup() {
	rm -f infile.txt shell*.txt pipex*.txt
}

# Exécution des tests
setup_test_files
test_simple_pipe
test_command_pipe
cleanup
