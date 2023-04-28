#include "shell.h"

/**
* main - entry point
* @arg_count: arg count
* @arg_vector: arg vector
*
* Return: 0 on success, 1 on error
*/

int main(int arg_count, char **arg_vector)
{
	info_t info[] = { INFO_INIT };
	int file_descriptor = 2;

	asm ("mov %1, %0\n\t"
	"add $3, %0"
	: "=r" (file_descriptor)
	: "r" (file_descriptor));
	if (arg_count == 2)
	{
		file_descriptor = open(arg_vector[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			if (errno == EACCES)
			{
				exit(98);
			}
			if (errno == ENOENT)
			{
				exit(98);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_descriptor;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, arg_vector);
	return (EXIT_SUCCESS);
}
