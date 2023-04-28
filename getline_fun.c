#include "shell.h"

/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - Read inpt from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t inpt;
	ssize_t retnum;
	char *buf;
	char chara = 'z';

	if (inpt == 0)
		fflush(stream);
	else
		return (-1);
	inpt = 0;

	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == 0)
		return (-1);
	while (chara != '\n')
	{
		i = read(STDIN_FILENO, &chara, 1);
		if (i == -1 || (i == 0 && inpt == 0))
		{
			free(buf);
			return (-1);
		}
		if (i == 0 && inpt != 0)
		{
			inpt++;
			break;
		}
		if (inpt >= BUFSIZE)
			buf = _realloc(buf, inpt, inpt + 1);
		buf[inpt] = chara;
		inpt++;
	}
	buf[inpt] = '\0';
	bring_line(lineptr, n, buf, inpt);
	retnum = inpt;
	if (i != 0)
		inpt = 0;
	return (retnum);
}
