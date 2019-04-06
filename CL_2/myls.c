/*
	Simple ls program
	Jacob Oakman
	Brian Zhao
*/

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
	struct dirent *directory_entry; // Pointer for directory entry

	// opendir() returns a pointer for DIR type.
	DIR *directory = opendir(".");

	if (directory == NULL)
	{
		printf("Could not open current direcotory");
		return 0;
	}

	bool showall = false;
	bool printl = false;
	unsigned int i;

	/**
	 * Checks arguments for -l and -a flags
	 * Break if both are found to save time
	 */
	for (i = 1; i < argc; i++)
	{
		if (!printl && strcmp(argv[i], "-l") == 0)
		{
			printl = true;
		}

		if (!showall && strcmp(argv[i], "-a") == 0)
		{
			showall = true;
		}

		if (printl && showall)
		{
			break;
		}
	}

	/*
	Only show hidden files when the -a flag is used
	hidden files have names that start with .
	If the -l flag is used indicate whether the entry is a file or folder
	*/
	while ((directory_entry = readdir(directory)) != NULL)
	{
		if (directory_entry->d_type != 0 && (directory_entry->d_name[0] != '.' || showall))
		{
			if (printl)
			{
				printf("%s ", (directory_entry->d_type == 4) ? "Folder" : "File");
			}
			printf("%s\n", directory_entry->d_name);
		}
	}

	closedir(directory);
	return 0;
}
