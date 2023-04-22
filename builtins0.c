#include "shell.h"
/**
 * check_for_builtins - this checks for the command in the builtin variables
 * @varial: the variables
 * Return: NULL
 */
void (*check_for_builtins(vars_t *varial))(char *varial)
{
	unsigned int a = 0;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}
	};
	while (check[a].f != NULL)
	{
		if (_strcmpr(varial->av[0], check[a].name) == 0)
			break;
		a++;
	}
	if (check[a].f != NULL)
		check[a].f(varial);
	return (check[a].f);
}

/**
 * _env - this prints the current environment
 * @varial: the struct of variables
 * Return: Nothing
 */

void _env(vars_t *varial)
{
	unsigned int a = 0;

	while (varial->envi[a])
	{
		_puts(varial->envi[a]);
		_puts("\n");
		a++;
	}
	varial->stat = 0;
}

/**
 * new_unsetenv - this removes an environment variable
 * @varial: variables
 * Return: Nothing
 */

void new_unsetenv(vars_t *varial)
{
	char **name, **environ;
	unsigned int a, b;

	if (varial->av[1] == NULL)
	{
		print_error(varial, ": Incorrect\n");
		varial->stat = 2;
		return;
	}
	name = find_key(varial->envi, varial->av[1]);
	if (name == NULL)
	{
		print_error(varial, ": No variable");
		return;
	}
	for (a = 0; varial->envi[a] != NULL; a++)
		;
	environ = malloc(sizeof(char *) * a);
	if (environ == NULL)
	{
		print_error(varial, NULL);
		varial->stat = 98;
		new_exit(varial);
	}
	a = 0;
	while (varial->envi[a] != *name)
	{
		environ[a] = varial->envi[a];
		a++; }
	b = a + 1;
	while (varial->envi[b] != NULL)
	{
		environ[a] = varial->envi[b];
			a++;
			b++; }
	environ[a] = NULL;
	free(*name);
	free(varial->envi);
	varial->envi = environ;
	varial->stat = 0;
}

/**
 * new_exit - this exits the program
 * @varial: these are the variables
 * Return: Nothing
 */
void new_exit(vars_t *varial)
{
	int stat;
	int a = 0;

	while (_strcmpr(varial->av[a], "exit") == 0 && varial->av[a + 1] != NULL)
	{
		stat = _atoi(varial->av[a + 1]);
		if (stat == -1)
		{
			varial->stat = 2;
			print_error(varial, ": Illicit number: ");
			_putstring(varial->av[a + 1]);
			_putstring("\n");
			free(varial->commands);
			varial->commands = NULL;
			return;
		}
		varial->stat = stat;
		a++;
	}
	free(varial->buf);
	free(varial->av);
	free(varial->commands);
	free_env(varial->envi);
	exit(varial->stat);
}

/**
 * new_setenv - this edits an existing variables
 * @varial: variables
 * Return: Nothing
 */

void new_setenv(vars_t *varial)
{
	char *variables;
	char **name;

	if (varial->av[2] == NULL)
	{
		varial->stat = 2;
		print_error(variables, "No correct number\n")
		;
	}
	if (varial->av[1] == NULL)
	{
		varial->stat == 2;
		print_error(variables, "Error\n")
		;
	}
	name = find_key(varial->envi,  varial->av[1]);
	if (!name)
		add_key(varial);

	else
	{
		variables = add_value(varial->av[1], varial->av[2]);
		if (!variables)
		{
			free(varial->buf);
			free(varial->av);
			free(varial->commands);
			print_error(variables, NULL);
			free_env(varial->envi);
			exit(98);
		}
		free(*name);
		*name = variables;
	}
	varial->stat = 0;
}


