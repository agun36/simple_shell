#include "shell.h"

/**
 * er_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *er_env(data_shell *datash)
{
	int len;
	char *err;
	char *verstr;
	char *msges;

	verstr = _itoa(datash->counter);
	msges = ": Unable to add/remove from environment\n";
	len = _strlen(datash->av[0]) + _strlen(verstr);
	len += _strlen(datash->args[0]) + _strlen(msges) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(verstr);
		return (NULL);
	}

	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, verstr);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, msges);
	_strcat(err, "\0");
	free(verstr);

	return (err);
}
/**
 * er_path_126 - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *er_path_126(data_shell *datash)
{
	int length;
	char *virStr;
	char *errNum;

	virStr = _itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(virStr);
	length += _strlen(datash->args[0]) + 24;
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
	_strcat(errNum, ": Permission denied\n");
	_strcat(errNum, "\0");
	free(virStr);
	return (errNum);
}
