#include "shell.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *newnode, *tmp;

	newnode = malloc(sizeof(r_var));
	if (newnode == NULL)
		return (NULL);

	newnode->len_var = lvar;
	newnode->val = val;
	newnode->len_val = lval;

	newnode->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *tmp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*head = NULL;
	}
}
/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *strings, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	strings = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(strings + j);
			*(strings + j) = *(strings + (j - 1));
			*(strings + (j - 1)) = temp;
		}
	}
}
