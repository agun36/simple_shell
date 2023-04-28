#include "shell.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int l, i_eof;
	char *enterXor;

	l = 1;
	while (l == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		enterXor = read_line(&i_eof);
		if (i_eof != -1)
		{
			enterXor = without_comment(enterXor);
			if (enterXor == NULL)
				continue;

			if (check_syntax_error(datash, enterXor) == 1)
			{
				datash->status = 2;
				free(enterXor);
				continue;
			}
			enterXor = rep_var(enterXor, datash);
			l = split_commands(datash, enterXor);
			datash->counter += 1;
			free(enterXor);
		}
		else
		{
			l = 0;
			free(enterXor);
		}
	}
}
/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}
	return (i + 1);
}
/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *rec;
	int length_name, length_value, length;

	length_name = _strlen(name);
	length_value = _strlen(value);
	length = length_name + length_value + 2;
	rec = malloc(sizeof(char) * (length));
	_strcpy(rec, name);
	_strcat(rec, "=");
	_strcat(rec, value);
	_strcat(rec, "\0");

	return (rec);
}
