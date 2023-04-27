#include <stdlib.h>
#include "shell.h"
/**
* bfree - Frees a pointer and sets the address to NULL
* @ptr: Address of the pointer to free
*
* Return: 1 if freed, otherwise 0.
*/
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	else
	{
		return (0);
	}
}
