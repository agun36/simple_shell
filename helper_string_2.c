#include "shell.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *newstr;
	size_t lenght;

	lenght = _strlen(s);
	newstr = malloc(sizeof(char) * (lenght + 1));
	if (newstr == NULL)
		return (NULL);
	_memcpy(newstr, s, lenght + 1);
	return (newstr);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len1;

	for (len1 = 0; s[len1] != 0; len1++)
	{
	}
	return (len1);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *tokenPin, *end;
	char *first_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		tokenPin = str;
		i = _strlen(str);
		end = &str[i];
	}
	first_start = tokenPin;
	if (first_start == end)
		return (NULL);

	for (bool = 0; *tokenPin; tokenPin++)
	{
		/*Breaking loop too find the next tokenpin*/
		if (tokenPin != first_start)
			if (*tokenPin && *(tokenPin - 1) == '\0')
				break;
		/*Replacing delimiter for empty char*/
		for (i = 0; delim[i]; i++)
		{
			if (*tokenPin == delim[i])
			{
				*tokenPin = '\0';
				if (tokenPin == first_start)
					first_start++;
				break;
			}
		}
		if (bool == 0 && *tokenPin)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (first_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
