#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();

int main(int argc, char** argv) {
	if (argc == 1) {
		help();
		return 0;
	}
	int opt_count = 0, flg_count = 0, file_count = 0;
	for (int i=1;i<argc;i++) {
		char* arg = argv[i];
		if (arg[0] == '-' && arg[1] == '-') {
			// Option
			opt_count++;
		} else if (arg[0] == '-') {
			// Flags
			for (int j=1;j<strlen(arg);j++) {
				flg_count++;
			}
		} else {
			// File
			file_count++;
		}
	}

	// DBG
	//printf("%d\n", opt_count);
	//printf("%d\n", flg_count);
	//printf("%d\n", file_count);
	// !DBG
	char* options[opt_count];
	char flags[flg_count];
	char* filenames[file_count];
	opt_count--;
	flg_count--;
	file_count--;

	for (int i=1;i<argc;i++) {
		char* arg = argv[i];
		if (arg[0] == '-' && arg[1] == '-') {
			// Option
			//printf("Option: %s\n", arg);	//DBG
			options[opt_count] = arg;
			opt_count--;
		} else if (arg[0] == '-') {
			// Flags
			for (int j=1;j<strlen(arg);j++) {
				//printf("Flag: %c\n", arg[j]);	//DBBG
				char c = arg[j];
				flags[flg_count] = c;
				flg_count--;
			}
		} else {
			// File
			//printf("File: %s\n", arg);	//DBG
			filenames[file_count] = arg;
			file_count--;
		}
	}
	return 0;
}

void help() {
	puts("Help text!");
}

