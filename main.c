#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();

int main(int argc, char** argv) {
	if (argc == 1) {
		help();
		return 0;
	}
	for (int i=1;i<argc;i++) {
		char* arg = argv[i];
		if (arg[0] == '-' && arg[1] == '-') {
			// Option
		} else if (arg[0] == '-') {
			// Flags
		} else {
			// File
		}
	}

	return 0;
}

void help() {
	puts("Help text!");
}

