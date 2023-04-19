#include "shell.h"

/**
 * _puts - writes a string to the standard output stream
 * @string: the string to write
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
 * @strt_memo: the string to double
 *
 * Return: a pointer to the newly-allocated string, or NULL if memory
 * allocation fails
 */
char *_strdup(char *strt_memo)
{
	char *new_memo;
	size_t i, lenght = 0;

	while (strt_memo[lenght])
		lenght++;

	new_memo = malloc((lenght + 1) * sizeof(char));

	if (new_memo == NULL)
		return (NULL);

	for (i = 0; i < lenght; i++)
		new_memo[i] = strt_memo[i];
	new_memo[lenght] = '\0';
	return (new_memo);
}

/**
 * _strcmpr - compares two strings
 * @strcmp_str: the first string to compare
 * @strcmp_str2: the second string to compare
 *
 * Return: an integer indicating the result of the comparison
 */
int _strcmpr(char *strcmp_str, char *strcmp_str2)
{
	while (*strcmp_str != '\0' && *strcmp_str2 != '\0')
	{
		while (*strcmp_str == *strcmp_str2)
		{
			strcmp_str++;
			strcmp_str2++;
		}
	}
	return (*strcmp_str - *strcmp_str2);
}

/**
 * _strcat - concatenates two strings
 * @strcat_str: the first string to concatenate
 * @strcat_str2: the second string to concatenate
 *
 * Return: a pointer to the newly-allocated str containing the concatenation,
 * or NULL if memory allocation fails
 */
char *_strcat(char *strcat_str, char *strcat_str2)
{
	size_t i, j, lenght1 = 0, lenght2 = 0;
	char *newcat_str = malloc((lenght1 + lenght2 + 1) * sizeof(char));

	while (strcat_str[lenght1])
		lenght1++;
	while (strcat_str2[lenght2])
		lenght2++;

	if (newcat_str == NULL)
		return (NULL);

	for (i = 0; i < lenght1; i++)
		newcat_str[i] = strcat_str[i];
	for (j = 0; j < lenght2; j++, i++)
		newcat_str[i] = strcat_str2[j];

	newcat_str[lenght1 + lenght2] = '\0';

	return (newcat_str);
}


/**
 * _strlen - returns the length of a string
 * @string: the string to measure
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
