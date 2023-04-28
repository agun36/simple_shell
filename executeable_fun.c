#include "shell.h"

/**
 * is_cdir - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @i: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - locates a command
 *
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command.
 */
char *_which(char *cmd, char **_environ)
{
	char *path_t, *ptrPath, *tokenPath, *dir_t;
	int len_dir, len_cmd, i;
	struct stat st;

	path_t = _getenv("PATH", _environ);
	if (path_t)
	{
		ptrPath = _strdup(path);
		len_cmd = _strlen(cmd);
		tokenPath = _strtok(ptrPath, ":");
		i = 0;
		while (tokenPath != NULL)
		{
			if (is_cdir(path_t, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(tokenPath);
			dir_t = malloc(len_dir + len_cmd + 2);
			_strcpy(dir_t, tokenPath);
			_strcat(dir_t, "/");
			_strcat(dir_t, cmd);
			_strcat(dir_t, "\0");
			if (stat(dir_t, &st) == 0)
			{
				free(ptrPath);
				return (dir_t);
			}
			free(dir_t);
			tokenPath = _strtok(NULL, ":");
		}
		free(ptrPath);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - determines if is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(data_shell *datash)
{
	struct stat status;
	int i;
	char *input;

	input = datash->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &status) == 0)
	{
		return (i);
	}
	_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int s;
	int exes;
	char *dir_t;
	(void) wpd;

	exes = is_executable(datash);
	if (exes == -1)
		return (1);
	if (exes == 0)
	{
		dir_t = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(dir_t, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exes == 0)
			dir_t = _which(datash->args[0], datash->_environ);
		else
			dir_t = datash->args[0];
		execve(dir_t + exes, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &s, WUNTRACED);
		} while (!WIFEXITED(s) && !WIFSIGNALED(s));
	}

	datash->status = s / 256;
	return (1);
}
