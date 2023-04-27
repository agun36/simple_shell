#include "shell.h"

/**
 * exit_shell - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int exit_shell(info_t *info)
{
	int exit_status;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * change_dir - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int change_dir(info_t *info)
{
	char *current_dir, *dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_puts("Error: getcwd failed\n");
	if (!info->argv[1])
	{
		dir = get_env_var(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = get_env_var(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_env_var(info, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(get_env_var(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = get_env_var(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "Error: can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		set_environment(info, "OLDPWD", get_env_var(info, "PWD="));
		set_environment(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * print_help - prints help message
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int print_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
