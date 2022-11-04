#include "simpleshell.h"

/**
 * execute - function that executes the cmds
 * @data: the data structure
 * @head: the head of llav linked list
 *
 * Return: -1 if error 0 otherwise
 **/
int	execute(data_t *data, cmd_lst_lst_t **head)
{
	cmd_lst_lst_t	*llav_node;
	cmd_lst_t	*node;

	llav_node = *head;
	while (llav_node)
	{
		node = llav_node->head;
		while (node)
		{
			if (!node->av[0])
				return (-1);
			if (_strchr(node->av[0], '/'))
			{
				if (!node->flag)
					do_execve(data, node);
				else if ((node->flag == '&' && node->prev && node->prev->exe == 1))
					do_execve(data, node);
				else if ((node->flag == '|' && node->prev && node->prev->exe == 0))
					do_execve(data, node);
			}
			else
			{
				if (do_builtin(data, node) == -1)
					return (-1);
			}
			node = node->next;
		}
		llav_node = llav_node->next;
	}
	return (0);
}
