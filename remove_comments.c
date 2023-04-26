#include "shell.h"

/**
 * remove_comments - removes comments from a command line
 * @line: the command line to remove comments from
 */
void remove_comments(char *line)
{
	char *hash = strchr(line, '#'); /* find the first occurrence of # */
	if (hash != NULL)
		*hash = '\0';
}

/**
 * main - entry point for the simple shell
 * @argc: the number of command-line arguments
 * @argv: an array of pointers to the command-line arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	if (argc > 1) /* check if a filename was provided */
	{
		FILE *fp = fopen(argv[1], "r"); /*open the file for reading*/
		if (fp == NULL)
		{
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}
		char command[100];
		while (fgets(command, sizeof(command), fp))
		{
			remove_comments(command);
			system(command);
		}
		fclose(fp); /* close the file */
	}
	else /* if no filename was provided, print an error message */
	{
		printf("Usage: simple_shell [filename]\n");
	}
	return (0);
}
