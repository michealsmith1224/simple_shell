#include "simpleshell.h"

/**
 * _strncpy - copy n char of a source string to dest
 *@src: the source string
 *@dest: the destination string
 * @n: the number of elements to copy
 *
 *Return: pointer to the dest string
 **/
char	*_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	if (!dest || !src)
		return (dest);
	while (i < n)
	{
		dest[i] = *src;
		if (*src)
			++src;
		++i;
	}
	return (dest);
}

/**
  * stralloc - creates a new lav node and add it
  * @str: the pointer to the string to copy
  * @i: the size of the new string
  * @flag: the delimeter
  * @llav: the head of llav ll
  *
  * Return: -1 if error 1 otherwise
  **/
int	stralloc(char *str, int i, char flag, cmd_lst_lst_t *llav)
{
	char	*buf;

	buf = (char *)malloc(i + 1);
	if (!buf)
		return (-1);
	buf = _strncpy(buf, str, i);
	buf[i] = '\0';
	add_cmd_lst(buf, &llav->head, flag);
	return (1);
}
