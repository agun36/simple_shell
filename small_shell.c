#include "shell.h"

/*global func*/
static void sig_handler(int uuv);
unsigned int flag_error;
/**
 * sig_handler - Signal handler for SIGINT
 * @uuv: Unused variable
 */

static void sig_handler(int uuv)
{
	(void) uuv;
	if (flag_error == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}

/**
 * initialize_vars - Initialize vars structure
 * @variables: Pointer to vars structure
 * @argv: Argument vector
 * @environment: Environment variables
 */
void initialize_vars(vars_t *variables, char **argv, char **environment)
{
	variables->argv = argv;
	variables->envi = make_env(environment);
	signal(SIGINT, sig_handler);
}

/**
 * check_is_pipe - Check if input is a pipe
 * @is_pipe: Pointer to is_pipe variable
 */
void check_is_pipe(unsigned int *is_pipe)
{
	if (!isatty(STDIN_FILENO))
		*is_pipe = 1;
	if (*is_pipe == 0)
		_puts("$ ");
}

/**
 * process_input - Process input from user
 * @variables: Pointer to vars structure
 */
void process_input(vars_t *varial);
void process_input(vars_t *varial)
{
	unsigned int i;

	varial->count++;
	varial->commands = token(varial->buf, ";");
	for (i = 0; varial->commands && varial->commands[i] != NULL; i++)
	{
		varial->av = token(varial->commands[i], "\n \t\r");
		if (varial->av && varial->av[0])
			if (check_for_builtins(varial) == NULL)
				check_for_path(varial);
		free(varial->av);
	}
}

/**
 * main - Main function
 * @argc: Argument count
 * @argv: Argument vector
 * @environment: Environment variables
 *
 * Return: 0 exit stat
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t lenght_buffer = 0;
	unsigned int is_pipe = 0;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	initialize_vars(&vars, argv, environment);
	check_is_pipe(&is_pipe);
	flag_error = 0;
	while (getline(&(vars.buf), &lenght_buffer, stdin) != -1)
	{
		flag_error = 1;
		process_input(&vars);
		free(vars.buf);
		free(vars.commands);
		flag_error = 0;
		if (is_pipe == 0)
			_puts("$ ");
		vars.buf = NULL;
	}
	if (is_pipe == 0)
		_puts("\n");
	free_env(vars.envi);
	free(vars.buf);
	exit(vars.stat);
}
