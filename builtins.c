#include "shell.h"

/**
 * add_key - this adds a new environment variables
 * @variables: pointer to the struct of variables
 *
 * Return: Nothing
 */

void add_key(vars_t *varial)
{
	unsigned int a = 0;
	char **newenvironment;

	while (varial->envi[a] != NULL)
	{
		newenvironment = malloc(sizeof(char *) * (a + 3));

		for (int i = 0; i < a; i++)
		{
	/* add new variable to the list of environ variables */

			newenvironment[i] = varial->envi[i];
		}
		newenvironment[a] = add_value(varial->av[1], varial->av[2]);
		a++;
	}
	newenvironment[a + 1] = NULL;

	free(varial->envi);
	varial->envi = newenvironment;

}

/**
 * _atoi - this converts a string into an integer
 * @string: tgis is the string to be convertes
 * Return: the converted integer
 */

int _atoi(char *string)
{
	int numbers = 0;
	int check_num;
	unsigned int a, bab;

	check_num = Max_num;
	a = 0;
	bab = 0;

	while (check_num != 0)
	{
		check_num = check_num / 10;
		bab++;
	}
	while (string[a] != '\0' && a < bab)
	{
		if (string[a + 1] != '\0') 
		{
			if (numbers > Max_num / 10 && a == bab - 2) 
			{
				return (-1);
			}
			numbers = numbers * 10;
			if (string[a] - '0' > Max_num % 10 && a == bab - 1) 
			{
				return (-1);
			}
			if (string[a] < '0' && string[a] > 9)
			{
				return (-1);
			}
		}
		a++;
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
	length2 = _strlen(value);

	key = malloc(sizeof(char) * (length1 + length2 + 2));

	if (!key)
		return (NULL);
	a = 0;

	while (name[a] != '\0')
	{
		key[a] = name[a];
			a++;
	}
	key[a] = '=';
	b = 0;

	while (value[b] != '\0')
	{
		key[b + a + 1] = value[b];
			b++;
	}
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
	unsigned int a = 0;
	unsigned int length = strlen(name);

	while (environment[a] != '\0')
	{
		unsigned int b = 0;

		while (b < length)
		{
			if (name[b] != environment[a][b])
				break;
			b++;
		}
		if (environment[a][b] == '=' && b == length)
			return (&environment[a]);
		a++;
	}
	return (NULL);
}

