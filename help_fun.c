#include "shell.h"

/**
 * _envir - Help information for the builtin env
 * Return: no return
 */
void _envir(void)
{
	char *get_line = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, get_line, _strlen(get_line));

}
/**
 * _setenvir - Help information for the builtin setenv
 * Return: no return
 */
void _setenvir(void)
{

	char *getlin = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, getlin, _strlen(getlin));
	getlin = "int replace)\n\t";
	write(STDOUT_FILENO, getlin, _strlen(getlin));
	getlin = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, getlin, _strlen(getlin));
}
/**
 * _unsetenvir - Help information for the builtin unsetenv
 * Return: no return
 */
void _unsetenvir(void)
{
	char *get_line = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
}


/**
 * _generalhelp - Entry point for help information for the help builtin
 * Return: no return
 */
void _generalhelp(void)
{
	char *lin = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, lin, _strlen(lin));
	lin = "These cmds are defined internally.Type 'help' to see";
	write(STDOUT_FILENO, lin, _strlen(lin));
	lin = "Type 'help name' to find out more abt d function 'name'.\n\n ";
	write(STDOUT_FILENO, lin, _strlen(lin));
	lin = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, lin, _strlen(lin));
	lin = "[dir]\nexit: exit [n]\n env:env[option][name=value][command ";
	write(STDOUT_FILENO, lin, _strlen(lin));
	lin = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, lin, _strlen(lin));
	lin = "unsetenv [variable]\n";
	write(STDOUT_FILENO, lin, _strlen(lin));
}
/**
 * _exithelp - Help information fot the builint exit
 * Return: no return
 */
void _exithelp(void)
{
	char *get_line = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "Exits the shell with a status of N. If N is ommited, exit";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
}

