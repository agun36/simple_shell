#include "shell.h"
/**
 * check_for_builtins - this checks for the command in the builtin variables
 * @variables: the variables
 * Return: NULL
 */
void (*check_for_builtins(vars_t *variables))(vars_t *variables)
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
		if (_strcmpr(variables->av[0], check[a].name) == 0)
			break;
		a++;
	}
	if (check[a].f != NULL)
		check[a].f(variables);
	return (check[a].f);
}

/**
 * _env - this prints the current environment
 * @variables: the struct of variables
 * Return: Nothing
 */

void _env(vars_t *variables)
{
	unsigned int a = 0;

	while (variables->envi[a])
	{
		_puts(variables->envi[a]);
		_puts("\n");
		a++;
	}
	variables->status = 0;
}

/**
 * new_unsetenv - this removes an environment variable
 * @variables: variables
 * Return: Nothing
 */

void new_unsetenv(vars_t *variables)
{
	char **name, **environ;
	unsigned int a, b;

	if (variables->av[1] == NULL)
	{
		print_error(variables, ": Incorrect\n");
		variables->status = 2;
		return;
	}
	name = find_key(variables->env, variables->av[1])
	if (name == NULL)
	{
		print_error(variables, ": No variable");
		return;
	}
	for (a = 0; variables->envi[a] != NULL; a++)
		;
	environ = malloc(sizeof(char *) * a);
	if (environ == NULL)
	{
		print_error(variables, NULL);
		variables->status = 98;
		new_exit(variables);
	}
	a = 0;
	while (variables->envi[a] != *name)
	{
		environ[a] = variables->envi[a];
		a++; }
	b = a + 1;
	while (variables->envi[b] != NULL)
	{
		environ[a] = variables->envi[b];
			a++;
			b++; }
	environ[a] = NULL;
	free(*name);
	free(variables->envi);
	variables->envi = environ;
	variables->status = 0;
}

/**
 * new_exit - this exits the program
 * @variables: these are the variables
 * Return: Nothing
 */
void new_exit(vars_t *variables)
{
	int stat;
	int a = 0;

	while (_strcmpr(variables->av[a], "exit") == 0 && variables->av[a + 1] != NULL)
	{
		stat = _atoi(variables->av[a + 1]);
		if (stat == -1)
		{
			variables->status = 2;
			print_error(variables, ": Illicit number: ");
			_puts2(variables->av[a + 1]);
			_puts2("\n");
			free(variables->commands);
			variables->commands = NULL;
			return;
		}
		variables->status = stat;
		a++;
	}
	free(variables->buf);
	free(variables->av);
	free(variables->commands);
	free_env(variables->envi);
	exit(variables->status);
}

/**
 * new_setenv - this edits an existing variables
 * @variables: variables
 * Return: Nothing
 */

void new_setenv(vars_t *variables)
{
	char *variables;
	char **name;

	if (variables->av[2] == NULL)
	{
		variables->status = 2;
		print_error(variables, "No correct number\n")
		;
	}
	if (variables->av[1] == NULL)
	{
		variables->status == 2;
		print_error(variables, "Error\n")
		;
	}
	name = find_key(variables->envi,  variables->av[1]);
	if (!name)
		add_key(variables);

	else
	{
		variables = add_value(variables->av[1], variables->av[2]);
		if (!variable)
		{
			free(variables->buf);
			free(variables->av);
			free(variables->commands);
			print_error(variables, NULL);
			free_env(variables->envi);
			exit(98);
		}
		free(*name);
		*name = variables;
	}
	variables->status = 0;
}


