#include "simpleshell.h"

/**
 * expansion_var_alias - expands the $X variables and replaces aliases
 *
 * @av: the arguments of our commands
 * @data: the data_t structure
 */

void expansion_var_alias(char **av, data_t *data)
{
	int i = 0, j;
	char *new = NULL, *content = NULL;
	char	*buf;

	while (av[i])
	{
		j = 0;
		new = expansion_alias(av[i], data->alias);
		if (new == NULL)
		{
			while (av[i][j])
			{
				if (av[i][j] == '$' && av[i][j + 1])
				{
					content = parse_env_var(av[i] + j, data->env);
					new = str_concat(new, content);
					j++;
					while (av[i][j] && _isgraph(av[i][j]))
						j++;
					j--;
				}
				else
					new = c_concat(new, av[i][j]);
				j++;
			}
		}
		buf = av[i];
		av[i] = _strdup(new);
		free(buf);
		free(new);
		new = NULL;
		i++;
	}
}
