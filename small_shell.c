#include "shell.h"

/*global func*/

unsigned int sig_flag;

unsigned int flag_error;

static void sig_handler(int signal_number);


/**
 * sig_handler - Signal handler for SIGINT
 * @uuv: Unused variable
 */
static void sig_handler(int signal_number)
{
	(void)signal_number;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
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
	varial->commands = token_t(varial->buf, ";");
	for (i = 0; varial->commands && varial->commands[i] != NULL; i++)
	{
		varial->av = token_t(varial->commands[i], "\n \t\r");
		if (varial->av && varial->av[0])
			if (check_for_builtins(varial) == NULL)
				check_for_path(varial);
		free(varial->av);
	}
}

/**

initialize_vars - Initializes the variables in the vars_t structure
@vars: pointer to the vars_t structure to initialize
@argv: double pointer to an array of strings containing the arguments
@environment: double pointer to an array of strings containing the environment variables
*/
void initialize_vars(vars_t *vars, char **argv, char **environment)
{
	vars->argv = argv;
	vars->envi = environment;
	vars->count = 0;
	vars->stat = 0;
	vars->buf = NULL;
	vars->commands = NULL;
}

/**

check_is_pipe - Checks if the command input contains a pipe

@is_pipe: pointer to an unsigned int that will be set to 1 if the command input contains a pipe, 0 otherwise
*/
void check_is_pipe(unsigned int *is_pipe)
{
	char *tty;

	tty = ttyname(STDIN_FILENO);
	if (tty != NULL)
		*is_pipe = 1;
	else
		*is_pipe = 0;
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
	vars_t var = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	initialize_vars(&var, argv, environment);
	signal(SIGINT, sig_handler);
	check_is_pipe(&is_pipe);
	flag_error = 0;
	while (getline(&(var.buf), &lenght_buffer, stdin) != -1)
	{
		flag_error = 1;
		process_input(&var);
		free(var.buf);
		free(var.commands);
		flag_error = 0;
		if (is_pipe == 0)
			_puts("$ ");
		var.buf = NULL;
	}
	if (is_pipe == 0)
		_puts("\n");
	free(var.envi);
	free(var.buf);
	exit(var.stat);
}
