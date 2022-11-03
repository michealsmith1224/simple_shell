#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#define BUFSIZE 1024

/**
  * struct cmd_lst_s - the list of logic op cutted cmd
  * @cmd: the logic op cutted cmd
  * @av: the whitespace cutted cmd
  * @exe: a boolean to know if this command was executed or not
  * @flag: the logical operator delimeter of this cmd
  * @next: the next elem in the ll
  * @prev: the previous elem in the ll
  **/

typedef struct cmd_lst_s
{
  char *cmd;
  char **av;
  int exe;
  char flag;
  struct cmd_lst_s *next;
  struct cmd_ls_s *prev;
} cmd_list_t;

#endif /* SIMPLESHELL_H */
