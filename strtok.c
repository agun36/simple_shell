#include "shell.h"

/**
 * check_match - checks if the string and the character matches
 * @z: the character to check
 * @string: the string to be check
 * Return: 0 if it doesnt match, else 1.
 */

unsigned int check_match(char z, const char *string)
{
	unsigned int a = 0;

	/* interating through the string to compare the string character*/
	while (string[a] != '\0')
	{
		if (z != string[a])
			return (0);
			a++;
	}
	return (1);
}
/**
 * new_strtok- the new strtok
 * @string: the string we want to tokenize
 * @delimiter: delimiter
 * Return: NULL
 */

char *new_strtok(char *string, const char *delimiter)
{
	unsigned int a;
	static char *first_token;
	static char *curr_token;

	if (string)
		curr_token = string;
	first_token = curr_token;

	if (!first_token)
		return (NULL);

	a = 0;

	while (curr_token[a] != '\0' && check_match(curr_token[a], delimiter) != 1)
	{
		a++;
	}
	if (curr_token[a] == '#')
	{
		curr_token = NULL;
		return (NULL);
	}
	if (curr_token[a] == '\0')
		curr_token = NULL;

	else
	{
		curr_token[a] = '\0';
		curr_token = curr_token + a + 1;
		if (*curr_token == '\0')
		curr_token = NULL;
	}
	return (first_token);
}


