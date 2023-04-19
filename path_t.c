#include "shell.h"

/**
 * execute_cwd - current working directory
 * @vars: points to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */
int execute_cwd(vars_t *vars)
{
	pid_t sib_pid;

	if (stat(vars->av[0], &buff) == 0)
	{
		if (access(vars->av[0], X_OK) == 0)
		{
			sib_pid = fork();
			if (sib_pid == -1)
				print_error(vars, NULL);
			if (sib_pid == 0)
			{
				if (execve(vars->av[0], vars->av, vars->envi) == -1)
					print_error(vars, NULL);
			}
			else
			{
				wait(&vars->stat);
				if (WIFEXITED(vars->stat))
					vars->stat = WEXITSTATUS(vars->stat);
				if (WIFSIGNALED(vars->stat))
					if (WTERMSIG(vars->stat) == SIGINT)
						vars->stat = 130;
				return (0);
			}

			vars->stat = 127;
			return (1);
		}
		else
		{
			print_error(vars, ": trail again later\n");
			vars->stat = 126;
		}
		return (0);
	}
	print_error(vars, ": can't be found\n");
	vars->stat = 127;
	return (0);
}

/**
 * path_execute - executes a command in the path
 * @command: full path to the command
 * @vars: pointer to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */

int path_execute(char *command, vars_t *vars)
{
	pid_t sib_pid;

	if (access(command, X_OK) == 0)
	{
		sib_pid = fork();
		if (sib_pid == -1)
			print_error(vars, '\0');
		if (sib_pid == 0)
		{
			if (execve(command, vars->av, vars->envi == -1))
					print_error(vars, '\0');
					}
					else
					{

					wait(&vars->stat);
					if (WIFEXITED(vars->stat))
					vars->stat = WEXITSTATUS(vars->stat);
					if (WIFSIGNALED(vars->stat))
					{
					if (WTERMSIG(vars->stat) == SIGINT)
					vars->stat = 130;
					}

					return (0);
					}

					vars->stat = 127;
					return (1);
					}

	print_error(vars, ": Permission not granted\n");
	variables->stat = 126;

	return (0);
}

/**
 * find_path - finds the PATH variable in env
 * @env: environment variable
 *
 * Return: pointer to the PATH variable in env
 */
char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int i = 0, j;

	while (env[i] != NULL)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
		i++;
	}
	return (env[i]);
}
/**
 * check_for_path - checks if the command is in the PATH
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void check_for_path(vars_t *vars)
{
	char *path, *path_string = '\0', *check = '\0';
	unsigned int i = 0, reacty = 0;
	char **path_t;
	struct stat buf;

	if (check_for_directory(vars->av[0]))
		reacty = execute_cwd(vars);
	else
	{
		path = find_path(vars->envi);
		if (path != '\0')
		{
			path_string = _strdup(path + 5);
			path_t = token(path_dup, ":");
			for (i = 0; path_t && path_t[i]; i++, free(check))
			{
				check = _strcat(path_t[i], vars->av[0]);
				if (stat(check, &buf) == 0)
				{
					reacty = path_execute(check, vars);
					free(check);
					break;
				}
			}
			free(path_dup);
			if (!path)
			{
				vars->stat = 127;
				new_exit(vars);
			}
		}
		if (path == '\0' || path_t[i] == NULL)
		{
			print_error(vars, ": is empty\n");
			vars->stat = 127;
		}
		free(path_t);
	}
	if (reacty == 1)
		new_exit(vars);
}

/**
 * check_for_directory - checks if the command is a part of a path
 * @string: command string
 *
 * Return: 1 on success, 0 on failure
 */
int check_for_directory(char *string)
{
	unsigned int i = 0;

	while (string[i])
	{
		if (string[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
