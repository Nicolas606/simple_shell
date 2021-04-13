#include "holberton.h"

/**
 * main - Start a UNIX command line interpreter.
 *
 * Return: Exit code of the program (salida).
 */
int main(void)
{
	char *buffer = NULL, **commands = NULL;
	size_t bufsize = 256;
	int characters, salida = 0, recorrido = 1;
	directories *path_lista = path_directories();

	signal(SIGINT, SIG_IGN);

	while (recorrido)
	{
		recorrido = isatty(STDIN_FILENO);
		if (recorrido == 1)
			write(1, "~$ ", 3);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == EOF)
		{
			n_exit(&path_lista, buffer, salida);
		}
		else if (characters == 1)
			continue;
		buffer[characters - 1] = '\0';
		if (solo_spaces(buffer) == 1)
			continue;
		commands = split_input(buffer);
		if (commands == NULL)
		{
			dprintf(2, "malloc error");
			exit(91);
		}
		if (b_ins(commands, &path_lista, buffer, salida) == 1)
			continue;
		else
			call_fork(commands, path_lista, &salida);
	}
	return (salida);
}
