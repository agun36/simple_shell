#include "shell.h"

/**
 * token - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **token(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, count = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * count);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = new_strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == count)
		{
			tokens = _realloc(tokens, &count);
			if (tokens == NULL)
			{
				perror("Main Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
