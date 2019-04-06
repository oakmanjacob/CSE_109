// Sleep in c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	int i = 2;
	if (argc > 1 && isdigit(argv[1][0]))
	{
		sscanf(argv[1], "%d", &i);
	}

	printf("Sleeping for %i seconds\n", i);
	fflush(stdout);
	sleep(i);
	printf("Woke up!!\n");
	return 0;
}