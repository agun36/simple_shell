#include "shell.h"

/**
 * print_error - this prints the error to standard error
 * @vars: pointer to the struct of the variables
 * @message: the message to be printed out
 * Return: Nothing
 */

void print_error(vars_t *varial, char *message)
{
	char *num;

	_putstring(varial->argv[0]);
	_putstring("- ");

	num = _uitoa(varial->count);
	_putstring(num);
	free(num);
	_putstring("- ");

	_putstring(varial->av[0]);
	if (message != NULL)
		_putstring(message);

	else
		perror("this is a serious Error");
}

/**
 * _putstring - this prints the string to standard error
 * @string: the string to be printed
 * Return: nothing
 */

void _putstring(char *string)
{
	ssize_t lenght;
	ssize_t bab;

	bab = _strlen(string);
	lenght = write(STDERR_FILENO, string, bab);

	while (bab != lenght)
	{
		perror("this is error");
		exit(1);
	}
}

/**
 * _uitoa - this converts the unsigned int to a sttring
 * @num: the numbers of unsigned int to convert
 * Return: pimter to the string thats converted
 */

char *_uitoa(unsigned int num)
{
	char *conv_string;
	unsigned int fid, n;
	fid = num;
	n = 0;

	while (fid != 0)
	{
		n++;
		fid /= 10;
	}
	conv_string = malloc(sizeof(char) * (n + 1));
	if (!conv_string)
	{
		perror("Error1");
		exit(98);
	}
	conv_string[n] = '\0';
	while (n)
	{
		conv_string[--n] = (num % 10) + '0';
		num /= 10;
	}
	return (conv_string);
}
	
