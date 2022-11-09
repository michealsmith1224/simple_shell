#include "simpleshell.h"

/**
  * parser - takes a string as input and output a llav linked list
  * @input: the input string
  * @llav_head: the address of the first elem of llav ll
  *
  * Return: -1 if error 1 otherwise
  **/
int	parser(char *input, cmd_lst_lst_t **llav_head)
{
	cmd_lst_lst_t	*llav_node;
	cmd_lst_t	*node;

	if (!input)
		return (-1);
	if (parse_ctrl_op(input, llav_head) == -1)
		return (-1);
	if (parse_logic_op(llav_head) == -1)
		return (-1);
	llav_node = *llav_head;
	while (llav_node)
	{
		node = llav_node->head;
		while (node)
		{
			if (!node->av || !node->av[0])
			{
				free_all(llav_head);
				return (-1);
			}
			node = node->next;
		}
		llav_node = llav_node->next;
	}
	return (1);
}
