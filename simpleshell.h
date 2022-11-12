#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

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

/**
  * struct cmd_lst_lst_s - the list of control op cutted list of cmd
  * @list: the former string
  * @head: the first element of it' s cmd_lst_s ll
  * @next: the next element in the ll
  **/

typedef struct	cmd_lst_lst_s
{
		char *list;
		cmd_lst_t *head;
		struct cmd_lst_lst_s *next;
}	cmd_lst_lst_t;

int add_cmd_lst(char *cmd, cmd_lst_t **head, char flag);
int strsplit(cmd_lst_lst_t *llav, char *str);

/**
 * struct data_s - the data structure
 *
 * @env: environment
 * @mode: interactive, non interactive or from file
 * @bash: the argv[0]
 * @alias: the aliases
 * @line: the address of the getline line
 * @lines: index of the executed line
 * @llav_head: the head of the llav linked list
 */

typedef struct data_s
{
	char **env;
	char **alias;
	char **line;
	int mode;
	int lines;
	char *bash;
	cmd_lst_lst_t *llav_head;
} data_t;

/* SH_GETLINE  */
int sh_getline(char **line, int fd);

/* EXPANSION */
int expansion(data_t *data, cmd_lst_lst_t **head);
void expansion_path(char **arg, char *path_var);
char *parse_env_var(char *s, char **env);

/* PARSER */
int add_cmd_lst(char *cmd, cmd_lst_t **head, char flag);
int add_cmd_lst_lst(char *list, cmd_lst_lst_t **head);
int parse_logic_op(cmd_lst_lst_t **llav_head);
int parse_ctrl_op(char *input, cmd_lst_lst_t **head);
int parser(char *input, cmd_lst_lst_t **llav_head);

/* UTIL_DATA */
data_t *sh_data_new(char **argv, char **env);
void *sh_data_delete(data_t *data);

/* UTIL_ENV */
char **sh_get_env(char **env);
void sh_delete_env(char **env);
char *sh_get_env_var(char *var, char **env);

/* UTIL_MEM */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif /* SIMPLESHELL_H */

