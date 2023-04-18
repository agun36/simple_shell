#include "shell.h"

/**
 * realloc - reallocates the pointer inorder to double the space
 * @pointer: points to the old array
 * @size: pointer to the number of elements of the old array
 * Return: pointer to tge new array
 */

char **realloc(char **pointer, size_t *size)
{
	char **new_space;
	size_t b;

	new_space = malloc(sizeof(char *) * ((*size) + 12));
	if (new_space != NULL)
	{
		for (b = 0; b < (*size); b++)
			new_space[b] = pointer[b];
	}
	else
	{
		free(pointer);
		return (NULL);
	}
	*size = *size + 12;
	free(pointer);
	return (new_space);
}
