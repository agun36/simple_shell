#include "shell.h"
/**
* strtow - splits a string into words. Repeat delimiters are ignored
* @input_string: the input string
* @delimiter_string: the delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow(char *input_string, char *delimiter_string)
{
	int i, j, word_length, num_words = 0;
	char **words;

	if (input_string == NULL || input_string[0] == 0)
	{
		printf("Input string is empty.\n");
		return (NULL);
	}
	if (!delimiter_string)
	{
		printf("No delimiter string provided.\n");
		delimiter_string = " ";
	}
	for (i = 0; input_string[i] != '\0'; i++)
	{
		if (!is_delim(input_string[i], delimiter_string) &&
			(is_delim(input_string[i + 1], delimiter_string) || !input_string[i + 1]))
		{
			num_words++;
		}
	}
	if (num_words == 0)
	{
		printf("No words found in input string.\n");
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
		while (is_delim(input_string[i], delimiter_string))
		{
			i++;
		}
		word_length = 0;
		while (!is_delim(input_string[i + word_length], delimiter_string) && input_string[i +
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
			printf("Failed to allocate memory for words array.\n");
			return (NULL);
		}
		for (word_length = 0; word_length < k; word_length++)
		{
			words[j][word_length] = input_string[i++];
		}
		words[j][word_length] = 0;
	}
	words[j] = NULL;
	return (words);
}
/**
* strtow2 - splits a string into words
* @input_string: the input string
* @delimiter: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *input_string, char delimiter)
{
	int i, j, word_length, num_words = 0;
	char **words;

	if (input_string == NULL || input_string[0] == 0)
	{
		printf("Input string is empty.\n");
		return (NULL);
	}
	for (i = 0; input_string[i] != '\0'; i++)
	{
		if ((input_string[i] != delimiter && input_string[i + 1] == delimiter) ||
				(input_string[i] != delimiter && !input_string[i + 1]) || input_string[i + 1] ==
				delimiter)
		{
			num_words++;
		}
	}
	if (num_words == 0)
	{
		printf("No words found in input string.\n");
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
		while (input_string[i] == delimiter && input_string[i] != delimiter)
		{
			i++;
		}
		word_length = 0;
		while (input_string[i + word_length] != delimiter &&
			input_string[i + word_length] && input_string[i + word_length] != delimiter)
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
			printf("Failed to allocate memory for words array.\n");
			return (NULL);
		}
		for (word_length = 0; word_length < k; word_length++)
		{
			words[j][word_length] = input_string[i++];
		}
		words[j][word_length] = 0;
	}
	words[j] = NULL;
	return (words);
}
