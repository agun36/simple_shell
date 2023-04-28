#include "shell.h"

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptrEnv;
	int i, move;


	ptrEnv = NULL;
	move = 0;

	for (i = 0; _environ[i]; i++)
	{

		move = cmp_env_name(_environ[i], name);
		if (move)
		{
			ptrEnv = _environ[i];
			break;
		}
	}

	return (ptrEnv + move);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *varEnv, *nameEnv;

	for (i = 0; datash->_environ[i]; i++)
	{
		varEnv = _strdup(datash->_environ[i]);
		nameEnv = _strtok(varEnv, "=");
		if (_strcmp(nameEnv, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_info(nameEnv, value);
			free(varEnv);
			return;
		}
		free(var_env);
	}

	datash->_environ = _realloc2(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_info(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **reallocEnviron;
	char *varEnv, *nameEnv;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		varEnv = _strdup(datash->_environ[i]);
		nameEnv = _strtok(varEnv, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(varEnv);
	}
	if (k == -1)
	{
		_error(datash, -1);
		return (1);
	}
	reallocEnviron = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			reallocEnviron[j] = datash->_environ[i];
			j++;
		}
	}
	reallocEnviron[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = reallocEnviron;
	return (1);
}


