#include "shell.h"
/**
* strtow - splits a string into words. Repeat delimiters are ignored
*
* @input_str: the input string
*
* @del_s: the delimeter string
*
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow(char *input_str, char *del_s)
{
	int i, j, word_length, num_words = 0;
	char **words;

	if (input_str == NULL || input_str[0] == 0)
	{
		printf("Empty string\n");
		return (NULL);
	}
	if (!del_s)
	{
		printf("No delimiter string provided.\n");
		del_s = " ";
	}
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if (!is_del(input_str[i], del_s) &&
			(is_del(input_str[i + 1], del_str) || !input_str[i + 1]))
		{
			num_words++;
		}
	}
	if (num_words == 0)
	{
		printf("No words in input string.\n");
		return (NULL);
	}
	words = malloc((1 + num_words) * sizeof(char *));
	if (!words)
	{
		printf("Failed to allocate memory for words array.\n");
		return (NULL);
	}
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (is_del(input_str[i], del_s))
		{
			i++;
		}
		word_length = 0;
		while (!is_del(input_str[i + word_length], del_s) && input_str[i +
word_length])
		{
			word_length++;
		}
		words[j] = malloc((word_length + 1) * sizeof(char));
		if (!words[j])
		{
			for (word_length = 0; word_length < j; word_length++)
			{
				free(words[word_length]);
			}
			free(words);
			printf("No allocate memory for words array.\n");
			return (NULL);
		}
		for (word_length = 0; word_length < k; word_length++)
		{
			words[j][word_length] = input_str[i++];
		}
		words[j][word_length] = 0;
	}
	words[j] = NULL;
	return (words);
}
/**
* strtow2 - splits a string into words
*
* @input_str: the input string
*
* @del: the delimeter
*
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *input_str, char del)
{
	int i, j, length, num_wd = 0;
	char **wd;

	if (input_str == NULL || input_str[0] == 0)
	{
		printf("Empty string\n");
		return (NULL);
	}
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if ((input_str[i] != del && input_str[i + 1] == del) ||
				(input_str[i] != del && !input_str[i + 1]) || input_str[i + 1] ==
				del)
		{
			num_wd++;
		}
	}
	if (num_wd == 0)
	{
		printf("No words found in input string.\n");
		return (NULL);
	}
	words = malloc(1 + num_wd) * sizeof(char *));
	if (!wd)
	{
		printf("Failed\n");
		return (NULL);
	}
	for (i = 0, j = 0; j < num_wd; j++)
	{
		while (input_str[i] == del && input_str[i] != del)
		{
			i++;
		}
		length = 0;
		while (input_str[i + length] != del &&
			input_str[i + length] && input_str[i + length] != del)
		{
			length++;
		}
		wd[j] = malloc((length + 1) * sizeof(char));
		if (!wd[j])
		{
			for (length = 0; length < j; length++)
			{
				free(wd[length]);
			}
			free(wd);
			printf("Failed\n");
			return (NULL);
		}
		for (length = 0; length < k; length++)
		{
			wd[j][length] = input_str[i++];
		}
		wd[j][length] = 0;
	}
	wd[j] = NULL;
	return (wd);
}
