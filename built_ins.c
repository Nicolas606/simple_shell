#include "holberton.h"

/**
 * b_ins - Check if command is a build-in and executes it.
 * @commands: Double pointer of strings were commands are in.
 * @buffer: String that carry command line.
 * @salida: Exit code of the program.
 *
 * Return: 1 if command is a build-in, 0 if not.
 */
int b_ins(char **commands, char *buffer, int salida)
{
	char *nuestras[2] = {"exit", "env"};
	int i = 0;

	if ((_strcmp(nuestras[0], commands[0])) == 0)
	{
		while (commands[i])
		{
			free(commands[i]);
			i++;
		}
		free(commands[i]);
		free(commands);
		n_exit(buffer, salida);
	}
	else if ((_strcmp(nuestras[1], commands[0])) == 0)
	{
		while (commands[i])
		{
			free(commands[i]);
			i++;
		}
		free(commands[i]);
		free(commands);
		env();
		return (1);
	}
	return (0);
}

/**
 * n_exit - Free allock memory and executes exit of the program.
 * @buffer: String that carry command line.
 * @salida: Exit code of the program.
 */
void n_exit(char *buffer, int salida)
{
	free(buffer);
	exit(salida);
}

/**
 * env - Built-in function that prints the current environment.
 */
void env(void)
{
	char **var = environ;
	int i = 0;

	while (var[i])
	{
		_printf(1, "%s\n", var[i]);
		i++;
	}
}
