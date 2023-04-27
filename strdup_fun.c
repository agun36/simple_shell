#include "shell.h"

/**
 * _strdup - Returns a ptr to a newly allocated string which is a duplicate of
 * the string pointed to by `str`.
 *
 * @str: The string to duplicate.
 *
 * Return: On success, a ptr to the duplicated string is returned. On failure,
 * NULL is returned.
 */
int *_strdup(void **str)
{
	size_t len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
		return (NULL);

	memcpy(new_str, str, len);
	return (new_str);
}
