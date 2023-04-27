#include "shell.h"
/**
* is_chain_delimiter - test if current char in buffer is a chain delimeter
* @info: the parameter struct
* @buf: the char buffer
* @current_position: address of current position in buf
*
* Return: 1 if chain delimeter, 0 otherwise
*/
int is_chain_delimiter(info_t *info, char *buf, size_t *current_position)
{
	size_t j = *current_position;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	return (0);
	*current_position = j;
	return (1);
}
/**
* check_chain_status - checks we should continue chaining based on last status
* @info: the parameter struct
* @buf: the char buffer
* @current_position: address of current position in buf
* @start_position: starting position in buf
* @buffer_length: length of buf
*
* Return: Void
*/
void check_chain_status(info_t *info, char *buf, size_t *current_position, size_t start_position,
size_t buffer_length)
{
	size_t j = *current_position;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[start_position] = 0;
			j = buffer_length;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[start_position] = 0;
			j = buffer_length;
		}
	}
	*current_position = j;
}
/**
* replace_alias - replaces an aliases in the tokenized string
* @info: the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
	node = node_starts_with(info->alias, info->argv[0], '=');
	if (!node)
		return (0);
	free(info->argv[0]);
	p = _strchr(node->str, '=');
	if (!p)
		return (0);
	p = _strdup(p + 1);
	if (!p)
		return (0);
	info->argv[0] = p;
	}
	return (1);
}
/**
* replace_variables - replaces vars in the tokenized string
* @info: the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_variables(info_t *info)
{
	int b = 0;
	list_t *node;

	for (b = 0; info->argv[b]; b++)
	{
		if (info->argv[b][0] != '$' || !info->argv[b][1])
			continue;
		if (!_strcmp(info->argv[b], "$?"))
		{
			replace_string(&(info->argv[b]),
			_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[b], "$$"))
		{
			replace_string(&(info->argv[b]),
			_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[b][1], '=');
		if (node)
		{
			replace_string(&(info->argv[b]),
			_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[b], _strdup(""));
	}
	return (0);
}
/**
* replace_string - replaces string
* @old: address of old string
* @new: new string
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
