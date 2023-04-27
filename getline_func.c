#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buffer: address of buffer
 * @buffer_length: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buffer(info_t *info, char **buffer, size_t *buffer_length)
{
	ssize_t read_bytes = 0;
	size_t length_param = 0;

	if (!*buffer_length)
<<<<<<< HEAD
	{
=======
	{ 
		// if nothing left in the buffer, fill it
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		read_bytes = getline(buffer, &length_param, stdin);
#else
		read_bytes = _getline(info, buffer, &length_param);
#endif
		if (read_bytes > 0)
		{
			if ((*buffer)[read_bytes - 1] == '\n')
			{
<<<<<<< HEAD
				(*buffer)[read_bytes - 1] = '\0'; 
=======
				(*buffer)[read_bytes - 1] = '\0';
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
				read_bytes--;
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			{
				*buffer_length = read_bytes;
				info->cmd_buf = buffer;
			}
		}
	}
	return (read_bytes);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buffer; /* the ';' command chain buffer */
	static size_t buffer_index, iterator, buffer_length;
	ssize_t read_bytes = 0;
	char **buffer_pointer = &(info->arg), *pointer;

	_putchar(BUF_FLUSH);
	read_bytes = input_buf(info, &buffer, &buffer_length);
	if (read_bytes == -1)
<<<<<<< HEAD
	{
=======
	{ 
		/* EOF */
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
		log_message("Reached end of file");
		return (-1);
	}
	if (buffer_length)
	{
<<<<<<< HEAD
		iterator = buffer_index;
		pointer = buffer + buffer_index; 

		check_chain(info, buffer, &iterator, buffer_index, buffer_length);
		while (iterator < buffer_length)
		{
=======
		/* we have commands left in the chain buffer */
		iterator = buffer_index; /* init new iterator to current buffer position */
		pointer = buffer + buffer_index; /* get pointer for return */
		check_chain(info, buffer, &iterator, buffer_index, buffer_length);
		while (iterator < buffer_length) 
		{ 
			/* iterate to semicolon or end */
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
			if (is_chain(info, buffer, &iterator))
				break;
			iterator++;
		}

<<<<<<< HEAD
		buffer_index = iterator + 1;
		if (buffer_index >= buffer_length)
		{
=======
		buffer_index = iterator + 1; /* increment past nulled ';'' */
		if (buffer_index >= buffer_length)
		{
			/* reached end of buffer? */
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
			buffer_index = buffer_length = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buffer_pointer = pointer;
		return (_strlen(pointer));
	}

	*buffer_pointer = buffer;
	return (read_bytes);
}

/**
 * read_buffer - reads a buffer
 * @info: parameter struct
 * @buffer: buffer
 * @buffer_size: size
 *
 * Return: read_status
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *buffer_size)
{
	ssize_t read_status = 0;

	if (*buffer_size)
		return (0);

	read_status = read(info->readfd, buffer, READ_BUF_SIZE);
	if (read_status >= 0)
		*buffer_size = read_status;
	return (read_status);
}

/**
 * get_line - gets the next line of input from STDIN
 * @info: parameter struct
 * @buffer_ptr: address of pointer to buffer, preallocated or NULL
 * @buffer_length: size of preallocated buffer_ptr buffer if not NULL
 *
 * Return: buffer_length
 */
int get_line(info_t *info, char **buffer_ptr, size_t *buffer_length)
{
	static char buf[READ_BUF_SIZE];
	static size_t buf_index, buf_len;
	size_t in_len;
	ssize_t read_status = 0, bf_st = 0;
	char *pbf = NULL, *new_buffer = NULL, *new_line_char;

<<<<<<< HEAD
	pbf = *buffer_ptr;
	if (pbf && buffer_length)
		bf_st = *buffer_length;

	if (buf_index == buf_len)
		buf_index = buf_len = 0;

=======
	buffer = *buffer_ptr;
	if (buffer && buffer_length)
		buffer_length_status = *buffer_length;
	if (buf_index == buf_len)
		buf_index = buf_len = 0;
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
	read_status = read_buffer(info, buf, &buf_len);
	if (read_status == -1 || (read_status == 0 && buf_len == 0))
		return (-1);

	new_line_char = _strchr(buf + buf_index, '\n');
<<<<<<< HEAD
	line_len = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(pbf, bf_st, bf_st ? bf_stat + in_len : line_len + 1);
	if (!new_p)
		return (pbf ? free(pbf), -1 : -1);

	if (!new_buffer)
	{
=======
	line_len = new_line_char ? 1 + (unsigned int)(new_line_char - buf) : buf_len;
	new_buffer = _realloc(buffer, buffer_length_status, buffer_length_status ? buffer_length_status + line_len : line_len + 1);
	if (!new_buffer)
	{ 
		/* MALLOC FAILURE! */
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
		fprintf(stderr, "Malloc failed!\n");
		return (pbf ? free(pbf), -1 : -1);
	}

<<<<<<< HEAD
	if (bf_st) 
	{
		_strncat(new_buffer, buf + buf_index, in_len - buf_index);
	} 
	else 
	{
		_strncpy(new_buffer, buf + buf_index, in_len - buf_index + 1);
=======
	if (buffer_length_status)
	{
		_strncat(new_buffer, buf + buf_index, line_len - buf_index);
	} 
	else
	{
		_strncpy(new_buffer, buf + buf_index, line_len - buf_index + 1);
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
	}

	bf_st += in_len - buf_index;
	buf_index = in_len;
	pbf = new_buffer;

	if (buffer_length)
<<<<<<< HEAD
	{
		*buffer_length = bf_st;
		return;
	}
	*buffer_ptr = pbf;
	return (bf_st);
=======
		*buffer_length = buffer_length_status;
	*buffer_ptr = buffer;
	return (buffer_length_status);
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
}

/**
 * handle_sigint - Handles SIGINT signal (Ctrl+C)
 * @signal_number: The signal number
 *
 * Return: void
 */
void handle_sigint(int signal_number)
{
<<<<<<< HEAD
	printf("\n");
	printf("$ ");
	fflush(stdout);
=======
    printf("\n");
    printf("$ ");
    fflush(stdout);
>>>>>>> 04d4340021aaa40824eaa7d9d3b5789c7973613f
}
