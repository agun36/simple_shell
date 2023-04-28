#include "shell.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_helper },
		{ NULL, NULL }
	};
	int j;

	for (j = 0; builtin[j].name; j++)
	{
		if (_strcmp(builtin[j].name, cmd) == 0)
			break;
	}

	return (builtin[j].f);
}
/**
 * _error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int _error(data_shell *datash, int eval)
{
	char *errNum;

	switch (eval)
	{
	case -1:
		errNum = er_env(datash);
		break;
	case 126:
		errNum = er_path_126(datash);
		break;
	case 127:
		errNum = er_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			errNum = er_exit(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			errNum = er_cd(datash);
		break;
	}

	if (errNum)
	{
		write(STDERR_FILENO, errNum, _strlen(errNum));
		free(errNum);
	}

	datash->status = eval;
	return (eval);
}
/**
 * get_helper - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_helper(data_shell *datash)
{

	if (datash->args[1] == 0)
		_generalhelp();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		_setenvir();
	else if (_strcmp(datash->args[1], "env") == 0)
		_envir();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		_unsetenvir();
	else if (_strcmp(datash->args[1], "help") == 0)
		_helper();
	else if (_strcmp(datash->args[1], "exit") == 0)
		_exithelp();
	else if (_strcmp(datash->args[1], "cd") == 0)
		_cdhelp();
	else if (_strcmp(datash->args[1], "alias") == 0)
		_aliashelp();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
/**
 * get_sign - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sign(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
