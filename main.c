#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();

int main(int argc, char** argv) {

	// Print the help menu if no arguments were supplied
	if (argc == 1) {
		help();
		return 0;
	}

	// Track the amount of options, flags, and files supplied
	int opt_count = 0, flg_count = 0, file_count = 0;

	// First iteration
	// Determine the amount of options, flangs, and files
	for (int i=1;i<argc;i++) {
		char* arg = argv[i];
		if (arg[0] == '-' && arg[1] == '-') {
			// Increment option counter
			opt_count++;
		} else if (arg[0] == '-') {
			// Increment flag counter
			for (int j=1;j<strlen(arg);j++) {
				flg_count++;
			}
		} else {
			// Increment file counter
			file_count++;
		}
	}

	// Create arrays of the correct size
	char* options[opt_count];
	char flags[flg_count];
	char* filenames[file_count];
	// Decrement one for correct array indexing
	opt_count--;
	flg_count--;
	file_count--;

	// Second iteration
	// The count variables are decremented, so
	// items are stored in the arrays backwards
	for (int i=1;i<argc;i++) {
		char* arg = argv[i];
		if (arg[0] == '-' && arg[1] == '-') {
			// Add option (--) to array
			options[opt_count] = arg;
			opt_count--;
		} else if (arg[0] == '-') {
			// Add flag (-) to array
			for (int j=1;j<strlen(arg);j++) {
				char c = arg[j];
				flags[flg_count] = c;
				flg_count--;
			}
		} else {
			// Add file to array
			filenames[file_count] = arg;
			file_count--;
		}
	}
	return 0;
}

// Help function
// Replace text with appropriate help
void help() {
	puts("Help text!");
}

