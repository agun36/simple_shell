#include "shell.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int unstatus;
	int digitNum;
	int length;
	int bigDigit;

	if (datash->args[1] != NULL)
	{
		unstatus = _atoi(datash->args[1]);
		digitNum = _isdigit(datash->args[1]);
		length = _strlen(datash->args[1]);
		digitNum = unstatus > (unsigned int)INT_MAX;
		if (!digitNum || length > 10 || digitNum)
		{
			_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (unstatus % 256);
	}
	return (0);
}
/**
 * exec_line - finds builtins and commands
 *
 * @datash: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
