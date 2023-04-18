#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variables - holds various variables
 * @av: arguments from the command line
 * @buffer: command buffer
 * @environment: environment variables
 * @count: number of commands entered
 * @argv: arguments when shell was opened
 * @status: exit status
 * @commands: 2D array of commands
 */
typedef struct variables
{
	char **av; /* arguments from the command line */
	char *buffer; /* command buffer */
	char **environment; /* environment variables */
	size_t count; /* number of commands entered */
	char **argv; /* arguments when shell was opened */
	int status; /* exit status */
	char **commands; /* 2D array of commands */
} vars_t;

/**
 * struct builtins - holds information about builtin functions
 * @name: name of the builtin command
 * @f: function pointer to the corresponding builtin function
 */
typedef struct builtins
{
	char *name; /* name of the builtin command */
	/* function pointer to the corresponding builtin functn*/
	void (*f)(vars_t *);
} builtins_t;

/* Function prototype*/
char **make_env(char **environment);
void free_env(char **environment);
ssize_t _puts(char *string);
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *string);
char **token(char *buffer, char *delimiter);
char **_realloc(char **pointer, size_t *size);
char *new_strtok(char *string, const char *delimiter);

void (*check_for_builtins(vars_t *variables))(vars_t *variables);
void new_exit(vars_t *variables);
void _env(vars_t *variables);
void new_setenv(vars_t *variables);
void new_unsetenv(vars_t *variables);

void add_key(vars_t *vars);
char **find_key(char **environment, char *key);
char *add_value(char *key, char *value);
int _atoi(char *string);

void check_for_path(vars_t *variables);
int path_execute(char *command, vars_t *variables);
char *find_paths(char **environment);
int execute_cwd(vars_t *variables);
int check_for_directory(char *string);

void print_error(vars_t *variables, char *message);
void _puts2(char *string);
char *_uitoa(unsigned int count);

void process_input(vars_t *vars);
void check_is_pipe(unsigned int *is_pipe);
void initialize_vars(vars_t *vars, char **argv, char **environment);
static void sig_handler(int uuv)


#endif /* _SHELL_H_ */