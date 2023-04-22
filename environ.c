#include "shell.h"

/**
 * make_env - gets a shell environ from the one passed to main.
 * @environment: environ passed to main
 * Return: pointer to the environment created.
 */

char **make_env(char **environment)
{
	char **newenvironment = NULL;
	size_t a;

	a = 0;
	while (environment[a] != NULL)
		a++;

	newenvironment = malloc(sizeof(char *) * (a + 2));
	if (!newenvironment)
	{
		perror("This is an Error");
		exit(1);
	}
	else
	{
		a = 0;
		while (environment[a] != NULL)
		{
			newenvironment[a] = _strdup(environment[a]);
			a = a + 1;
		}
		newenvironment[a] = NULL;
		return (newenvironment);
		free(newenvironment);
		free(environment);
	}
}

