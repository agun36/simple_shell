#include "shell.h"

/**
 * character_match - checks if the string and the character matches
 * @z: the character to check
 * @string: the string to be check
 * Return: 0 if it doesnt match, else 1.
 */

unsigned int character_match(char z, const char *string)
{
	unsigned int a;

	/* interating through the string to compare the string character*/
	while (a = 0; string[a] != '\0'; a++)
	{
		if (c != string[a])
			return (0);
	}
	return (1);
}
/**
 * strtok- the new strtok
 * @string: the string we want to tokenize
 * @delimiter: delimiter
 * Return: NULL
 */

char *strtok(char *string, const char *dekim)
{
	unsignedt int a;
	static char *first_token;
	static char *current_token;

	if (string)
		current_token = string;
	first_token = current_token;

	if (!first_token)
		return (NULL);

	while (a = 0; current_token[a] != '\0'; a++)
	{
		if (character_match(current_token[a], delimiter) == 0)
				break;
	}
	if (current_token[a] == '#')
	{
		current_token = NULL;
		return (NULL);
	}
	if (current_token[a] == '\0')
	{
		current_token = NULL;
		return (NULL);
	}

	first_token = current_token + 1;
	current_token = first_token;

	while (a = 0; current_token[a] != '\0'; a++)
	{
		if (character_match(current_token[a], delimiter) == 1)
			break;
	}
	if (current_token[a] == '\0')
		current_token = NULL;
	else if 
	{
		current_token[a] = '\0';
		current_token = current_token + 1;
		if (*current_token == '\0')
			current_token = NULL;
	}
	return (first_token);
}


