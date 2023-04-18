#include "shell.h"

/**
 * _puts - writes a string to the standard output stream
 * @str: the string to write
 *
 * Return: the number of characters written, or -1 if an error occurs
 */
ssize_t _puts(char *string)
{
	ssize_t count = 0;

	while (*string != '\0')
	{
		if (putchar(*string++) == EOF)
		{
			return (-1);
		}
		count++;
	}

	return (count);
}

/**
 * _strdup - duplicates a string
 * @strtodup: the string to duplicate
 *
 * Return: a pointer to the newly-allocated string, or NULL if memory
 * allocation fails
 */
char *_strdup(char *strtodup)
{
	char *new_str;
	size_t i, len = 0;

	while (strtodup[len])
		len++;

	new_str = malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
		return NULL;

	for (i = 0; i < len; i++)
		new_str[i] = strtodup[i];
	
	new_str[len] = '\0';
	return (new_str);
}

/**
 * _strcmpr - compares two strings
 * @strcmp1: the first string to compare
 * @strcmp2: the second string to compare
 *
 * Return: an integer indicating the result of the comparison
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	while (*strcmp1 != '\0' && *strcmp2 != '\0' && *strcmp1 == *strcmp2)
	{
		strcmp1++;
		strcmp2++;
	}
	
	return (*strcmp1 - *strcmp2);
}

/**
 * _strcat - concatenates two strings
 * @strc1: the first string to concatenate
 * @strc2: the second string to concatenate
 *
 * Return: a pointer to the newly-allocated string containing the concatenation,
 * or NULL if memory allocation fails
 */
char *_strcat(char *strc1, char *strc2)
{
	char *new_str;
	size_t i, j, lenght1 = 0, lenght2 = 0;

	while (strc1[lenght1])
		len1++;
	while (strc2[lenght2])
		len2++;

	new_str = malloc((lenght1 + lenght2 + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < lenght1; i++)
		new_str[i] = strc1[i];
	for (j = 0; j < lenght2; j++, i++)
		new_str[i] = strc2[j];

	new_str[lenght1 + lenght2] = '\0';

	return (new_str);
}


/**
 * _strlen - returns the length of a string
 * @str: the string to measure
 *
 * Return: the length of the string
 */
unsigned int _strlen(char *string) 
{
	unsigned int lenght = 0;

	while (*string != '\0')
	{
		string++;
		lenght++;
	}

	return (lenght);
}
