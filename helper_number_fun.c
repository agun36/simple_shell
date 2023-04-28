#include "shell.h"

/**
 * get_len - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int get_len(int n)
{
	unsigned int firstNum;
	int length = 1;

	if (n < 0)
	{
		length++;
		firstNum = n * -1;
	}
	else
	{
		firstNum = n;
	}
	while (firstNum > 9)
	{
		length++;
		firstNum = firstNum / 10;
	}

	return (length);
}
/**
 * _itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *_itoa(int n)
{
	unsigned int firstNum;
	int length = get_len(n);
	char *buff;

	buff = malloc(sizeof(char) * (length + 1));
	if (buff == 0)
		return (NULL);

	*(buff + length) = '\0';

	if (n < 0)
	{
		firstNum = n * -1;
		buff[0] = '-';
	}
	else
	{
		firstNum = n;
	}

	length--;
	do {
		*(buff + length) = (firstNum % 10) + '0';
		firstNum = firstNum / 10;
		length--;
	}
	while (firstNum > 0)
		;
	return (buff);
}
/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *enterEmpty = NULL;
	size_t size_num = 0;

	*i_eof = getline(&enterEmpty, &size_num, stdin);

	return (enterEmpty);
}
