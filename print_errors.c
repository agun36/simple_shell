#include "shell.h"

/**
 * print_error - this prints the error to standard error
 * @vars: pointer to the struct of the variables
 * @message: the message to be printed out
 * Return: Nothing
 */

print_error(vars_t *variables, char *message)
{
	char *num;

	_putstring(variables->argv[0]);
	_putstring("- ");

	num = _uitoa(variables->num);
	_putstring(num);
	free(num);
	_putstring("- ");

	_putstring(variables->av[0]);
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
	for (n = 0; fid != 0; n++)
		fid = fid / 10;

	conv_string = malloc(sizeof(char) * (n + 1));
	if (!conv_string)
	{
		perror("this is a serious error");
		exit(98);
	}
	else if (conv_string[n] = "\0")
	for (--n; num; --n)
	{
		conv_string[n] = (num % 10) + '0';
		num = num / 10;
	}
	return (conv_string);
}
