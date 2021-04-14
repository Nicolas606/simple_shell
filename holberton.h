#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>	/*getline - dprintf*/
#include <stdlib.h> /*malloc - exit*/
#include <unistd.h> /*fork - access - isatty*/
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdarg.h> /*variatic arguments*/

extern char **environ;

/* Structures */
/**
 * struct list_d - Save the PATH directories
 * @directory: One of the PATH directories
 * @next: Pointer to nex node
 */
typedef struct list_d
{
	char *directory;
	struct list_d *next;
} dir;

/**
 * struct ch_fmt - sees if the format matches
 * @c: the char of the format
 * @f: function to make
 */
typedef struct ch_fmt
{
	char c;
	int (*f)(va_list, char *, int);
} fmt_type;

/*shell.c */

int solo_spaces(char *buffer);

char **split_input(char *buffer);

void quit_spaces(char **commands);

int comprueba(int line, int *salir, char **commands, char *argv[], dir *lista);

int existencia(char **command_0, dir *lista);

/*fork.c*/

int call_fork(char **commands);

/*entorno.c*/

char *_getenv(const char *name);

dir *add_node(dir **head, const char *str);

dir *path_directories(void);

void free_list(dir **head);

/*built_ins.c*/

int b_ins(char **commands, dir **path_lista, char *buffer, int salida);

void n_exit(dir **path_lista, char *buffer, int salida);

void env(void);

/*printf.c*/

int _printf(int fd, const char * const format, ...);

int find_m(const char * const fmt, va_list list, char *buff, int p, int *i);

/*printf_char.c*/

int print_char(va_list a, char *buffer, int index);

int print_string(va_list a, char *buffer, int index);

/*printf_int.c*/

int print_int(va_list a, char *buffer, int index);

int len_dig(long int num);

int print_u_int(va_list a, char *buffer, int index);

/* string.c */

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

char *_strcat(char *dest, char *src);

char *_strdup(const char *str);

#endif
