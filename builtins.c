#include "shell.h"

/**
 * add_keys - this adds a new environment variables
 * @variables: pointer to the struct of variables
 *
 * Return: Nothing
 */

void add_key(vars_t *variables)
{
	unsigned int a;
	char **newenvironment;

	for (a = 0; variables->environment[a] != NULL; a++)
		;/* add new variable to the list of environ variables */

	newenvironment = malloc(sizeof(char *) * (a + 3));
	/*memory for the list of environ variables thats larger than the currentlist*/

	if (!newenvironment)
	{
		print_error(variables, NULL);
		variables->stat = 98;
		new_exit(variables);
	}

	for (a = 0; variables->environment[a] != NULL; a++)
		newenvironment[a] = variables->environment[a];
	newenvironment[a] = add_value(variables->av[1], variables->av[2]);
	if (!newenvironment[a])
	{
		print_error(variables, NULL);
		free(varaiables->buf);
		free(variables->commands);
		free(variables->av);
		free_env(variables->environment);
		free(newenvironment);
		exit(98);
	}
	newenvironment[a + 1] = NULL;
	free(variables->environment);
	variables->environment = newenv;
}

/**
 * atoi - this converts a string into an integer
 * @string: tgis is the string to be convertes
 * Return: the converted integer
 */

int atoi(char *string)
{
	int numbers = 0;
	int check_num;
	unsigned int a, bab;

	check_num = Max_num;

	for  (a = 0; check_num != 0; bab++)
		check_num = check_num / 10;
	for (a = 0; string[a] != '\0' && a < bab; a++)
	{
		numbers = numbers + string[a] - '0';
		if ((string[a + 1] != '\0') && (numbers > Max_num / 10) && (a == bab - 2)
				return (-1);
		numbers = numbers * 10;
		if ((string[a] - '0' > Max_num % 10) && (a == bab - 1))
			return (-1);
		if (string[a] < '0' && string[a] > 9)
			return (-1);
	}
	if (a > bab)
		return (-1);
		return (numbers);
}

/**
 * add_value - adding a new environment variable
 * @name: the variable name
 * @value: the value of the variable
 * Return: the new string
 */

char *add_value(char *name, char *value)
{
	char *key;
	unsigned int length1, length2, a, b;

	length1 = _strlen(name);
	length2 = _strlen(vakue);
	key = malloc(sizeof(char) * (length1 + length2 + 2));

	if (!key)
		return (NULL);
	for (a = 0; name[a] != '\0'; a++)
		key[a] = name[a];

	key[a] = '=';
	for (b = 0; value[b] != '\0'; b++)
		key[b + a + 1] = value[b];
	key[1 + b + a] = '\0';
		return (key);
}


/**
 * find_key - this finds a variable
 * @environment: tge environmental variables
 * @name: the environment variable to find
 * Return: address to the variable
 */

char **find_key(char **environment, char *name)
{
	unsigned int a, b;
	unsigned int length;

	length = strlen(name);
	for (a = 0; environment[a] != '\0'; a++)
	{
		for (b = 0; b < length; b++)
			if (name[b] != environment[a][b])
				break;
		if (environment[a][b] == '=' && b == length)
			return (&environment[a]);
	}
	return (NULL);
}

