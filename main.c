#include "holberton.h"

/**
 * main - Start a UNIX command line interpreter.
 * @argc: Arguments counter.
 * @argv: Arguments string array.
 *
 * Return: Exit code of the program (salir).
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL, **commands = NULL;
	size_t bufsize = 256;
	int characters = 0, salir = 0, recorrido = 1, line = 0;
	(void)argc, (void)argv;

	signal(SIGINT, SIG_IGN);
	while (characters >= 0)
	{
		line++;
		recorrido = isatty(STDIN_FILENO);
		if (recorrido == 1)
			write(1, "~$ ", 3);
		characters = getline(&buffer, &bufsize, stdin);

		if (characters == EOF)
		{
			_printf(1, "\n", 1);
			n_exit(buffer, salir);
		}
		else if (characters == 1)
			continue;
		buffer[characters - 1] = '\0';
		if (solo_spaces(buffer) == 1)
			continue;
		commands = split_input(buffer);
		if (commands == NULL)
		{
			_printf(2, "malloc error");
			exit(1);
		}
		if (b_ins(commands, buffer, salir) == 1)
			continue;
		else if (comprueba(line, &salir, commands, argv) != 1)
			continue;
		else
			call_fork(commands, &salir);
	}
	return (salir);
}


