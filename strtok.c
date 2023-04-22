#include "shell.h"

/**
 * check_match - checks if the string and the character matches
 * @z: the character to check
 * @string: the string to be check
 * Return: 0 if it doesnt match, else 1.
 */

unsigned int check_match(char z, const char *string)
{
	int a = 0;
	/* interating through the string to compare the string character*/
	while (string[a] != '\0')
	{
		if (z == string[a])
		{
			a++;
			return (1);
	}
		else
		{
			return (0);
		}
	}
	return (0);
}

/**
 * new_strtok- the new strtok
 * @string: the string we want to tokenize
 * @delimiter: delimiter
 * Return: NULL
 */

char *new_strtok(char *string, const char *delimiter)
{
	static char *first_token;
	static char *cur_t;
	unsigned int i;

	if (string != NULL)
	cur_t = string;
	first_token = cur_t;
	if (first_token == NULL)
	return (NULL);

	i = 0;
	while (cur_t[i] != '\0')
	{
		if (check_match(cur_t[i], delimiter) == 0)
			break;
			i++;
	}
	if (cur_t[i] == '\0' || cur_t[i] == '#')
	{
		cur_t = NULL;
		return (NULL);
	}
	first_token = cur_t + i;
	cur_t = first_token;

	i = 0;
	while (cur_t[i] != '\0')
	{
		while (check_match(cur_t[i], delimiter) != 1)
		{
			i++;
		}
		i++;
	}
	if (cur_t[i] == '\0')
	cur_t = NULL;
	else
	{
		cur_t[i] = '\0';
		cur_t = cur_t + i + 1;
		if (*cur_t == '\0')
		cur_t = NULL;
	}
	return (first_token);
}

