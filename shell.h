#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * struct shell_list_p - singly linked lists
 * @ptr: a malloced address
 * @next: it points to the next node
 *
 * Description: singly linked list node structure
 * for ALX simple shell project
 */

typedef struct shell_list_p
{
	void *ptr;
	struct shell_list_p *next;
} shell_list_t;

int linum(int add);

char *get_prog_name(char *name);

void my_error(char *command, int status, char *extra);

void main_loop(char *filename);

void signal_handler(int sig);

/* Below find the linked list functions for use with do_mem */

size_t __list_len(shell_list_t *h);
shell_list_t *__add_node(shell_list_t **head, void *ptr);
shell_list_t *__add_node_end(shell_list_t **head, void *ptr);
void __free_list(shell_list_t *head);
void __free_list_full(shell_list_t *head);
shell_list_t *_insert_node(shell_list_t **head, unsigned int idx, void *ptr);
shell_list_t *__get_node_at_index(shell_list_t *head, unsigned int index);
int __delete_node_at_index(shell_list_t **head, unsigned int index);

/* Above find the linked list functions for use with do_mem* */

/**
 * struct shell_list_p2 - singly linked list
 * @ptr: a malloced string
 * @next: it points to the next node
 *
 * Description: singly linked list node structure
 * for ALX simple shell project
 */

typedef struct shell_list_p2
{
	char *ptr;
	struct shell_list_p2 *next;
} shell_list_s;

/* Below find th elined list functions */

size_t list_len(shell_list_s *h);
shell_list_s *add_node_end(shell_list_s **head, char *ptr);
shell_list_s *add_node(shell_list_s **head, char *ptr);
void free_list(shell_list_s *head);
void free_list_full(shell_list_s *head);
shell_list_s *get_node_at_index(shell_list_s *head,
unsigned int index);
shell_list_s *insert_node(shell_list_s **head, unsigned int ide,
char *ptr);
char **arrayify(shell_list_s *);
int delete_node_at_index(shell_list_s **head, unsigned int index);
shell_list_s *listify(char **);
void free_double_array(char **);

/* Above find the klinked list function */


/*  Below find the string functions */

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int word_count(char *str, char *delim);
char *_strcat(char *s1, char *s2);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
int sizeof_command(char **tokens);
int _isdigit(int c);
int has_newline(char *input);
void shiftbuffer(char *input, int newline_index, int filled);
char *_reverse(char *str, int n);
char *_itoa(int num);
char *_memset(char *s, char b, int n);

/* Above find the string functions */

void *do_mem(size_t size, void *ptr);
void do_exit(int fd, char *msg, int code);
ssize_t else_handle_input(char *lineptr, int stream, char *input, int filled);
ssize_t _getline(char *lineptr, int stream);
char **get_path();
char **_strtok(char *str, char *delim);
char *get_env_val(char *name);
char *find_path(char **path, char *command);
char *get_env_val(char *name);
char **get_env();

/* environment functions */
char **do_env(char *x, char *y);
char *get_full_command(char *path, char *command);

/* builtin functions */
int setenv_builtin(char **tokens);
int unsetenv_builtin(char **tokens);
int cd_builtin(char **tokens);
char **get_builtins();
int env_builtin(void);

/* execute functions */
int execute(char **tokens);
int exec_nb(char **tokens);
int search_ops(char **tokens);
int check_access(char *comm, char *token);
int exec_builtin(char **tokens, int bcase);
char *prep_execve(char *token);

/* file functions */
char *read_textfile(char *filename);

#endif /*SHELL_H*/
