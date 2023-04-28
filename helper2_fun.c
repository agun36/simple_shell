#include "shell.h"

/**
 * _helper - Help information for the builtin help.
 * Return: no return
 */
void _helper(void)
{
	char *get_line = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
}
/**
 * _aliashelp - Help information for the builtin alias.
 * Return: no return
 */
void _aliashelp(void)
{
	char *get_line = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
}
/**
 * _cdhelp - Help information for the builtin alias.
 * Return: no return
 */
void _cdhelp(void)
{
	char *get_line = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, get_line, _strlen(get_line));
	get_line = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, get_line, _strlen(get_line));
}
