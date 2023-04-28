#include "shell.h"

/**
 * concat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *concat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * er_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *er_cd(data_shell *datash)
{
	int length, len_id;
	char *errNum, *virStr, *msges;

	virStr = _itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msges = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msges = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(virStr) + _strlen(msges) + len_id + 5;
	errNum = malloc(sizeof(char) * (length + 1));

	if (errNum == 0)
	{
		free(virStr);
		return (NULL);
	}

	errNum = concat_cd(datash, msges, errNum, virStr);

	free(virStr);

	return (errNum);
}

/**
 * er_not_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *er_not_found(data_shell *datash)
{
	int length;
	char *errNum;
	char *virStr;

	virStr = _itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(virStr);
	length += _strlen(datash->args[0]) + 16;
	errNum = malloc(sizeof(char) * (length + 1));
	if (errNum == 0)
	{
		free(errNum);
		free(virStr);
		return (NULL);
	}
	_strcpy(errNum, datash->av[0]);
	_strcat(errNum, ": ");
	_strcat(errNum, virStr);
	_strcat(errNum, ": ");
	_strcat(errNum, datash->args[0]);
	_strcat(errNum, ": not found\n");
	_strcat(errNum, "\0");
	free(virStr);
	return (errNum);
}

/**
 * er_exit - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *er_exit(data_shell *datash)
{
	int length;
	char *errNum;
	char *virStr;

	virStr = _itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(virStr);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	errNum = malloc(sizeof(char) * (length + 1));
	if (errNum == 0)
	{
		free(virStr);
		return (NULL);
	}
	_strcpy(errNum, datash->av[0]);
	_strcat(errNum, ": ");
	_strcat(errNum, virStr);
	_strcat(errNum, ": ");
	_strcat(errNum, datash->args[0]);
	_strcat(errNum, ": Illegal number: ");
	_strcat(errNum, datash->args[1]);
	_strcat(errNum, "\n\0");
	free(virStr);

	return (errNum);
}
