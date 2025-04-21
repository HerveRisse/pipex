#!/bin/bash

setup_test_files() {
	echo "Hello World
Test line
Another line
Final line" > infile.txt
}

test_basic_pipe() {
	echo "Test 1 (cat | grep):"
	./pipex infile.txt "cat" "grep Hello" outfile1.txt
	cat outfile1.txt
}

test_command_pipe() {
	echo "\nTest 2 (ls | wc):"
	./pipex infile.txt "ls -l" "wc -l" outfile2.txt
	cat outfile2.txt
}

test_invalid_file() {
	echo "\nTest 3 (fichier invalide):"
	./pipex "invalid.txt" "cat" "grep test" outfile3.txt
}

test_invalid_command() {
	echo "\nTest 4 (commande invalide):"
	./pipex infile.txt "invalidcmd" "wc -l" outfile4.txt
}

cleanup() {
	rm -f infile.txt outfile*.txt
}

# Exécution des tests
setup_test_files
test_basic_pipe
test_command_pipe
test_invalid_file
test_invalid_command
cleanup
