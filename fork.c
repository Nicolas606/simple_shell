#include "holberton.h"

/**
 * comprueba -
 * @line: Number of line write by the user.
 * @salir: Exit code of the program.
 * @commands: Double pointer to string tha contains the commands.
 * @argv: Arguments string array.
 * @lista: Pointer to linked-list that contain the PATH directories.
 * Return: 1 if exists, 0 if not.
 */
int comprueba(int line, int *salir, char **commands, char *argv[], dir *lista)
{
	int i;
	*salir = 0;

	if (access(commands[0], F_OK) != 0)
	{
		if (existencia(&commands[0], lista) == 0)
		{
			_printf(2, "%s: %d: %s: not found\n", argv[0], line, commands[0]);
			for (i =  0; commands[i]; i++)
				free(commands[i]);
			free(commands[i]);
			free(commands);
			*salir = 127;
			return (-1);
		}
	}
	if (access(commands[0], X_OK) != 0)
	{
		_printf(2, "%s: %d: %s:  Permission denied\n",
				argv[0], line, commands[0]);
		for (i =  0; commands[i]; i++)
			free(commands[i]);
		free(commands[i]);
		free(commands);
		*salir = 126;
		return (-1);
	}
	return (1);
}

/**
 * existencia - Check if a command file exist in the PATH directories.
 * @command_0: The commando to find.
 * @lista: Pointer to linked-list that contain the directories.
 *
 * Return: 1 if file exists, 0 if not.
 */
int existencia(char **command_0, dir *lista)
{
	char str[100];

	while (lista != NULL)
	{
		strcpy(str, lista->directory);
		strcat(str, "/");
		strcat(str, *command_0);
		if (access(str, F_OK) == 0)
		{
			free(*command_0);
			*command_0 = strdup(str);
			return (1);
		}
		lista = lista->next;
	}
	return (0);
}

/**
 * call_fork - Check if a command exists, and executes it.
 * @commands: Double pointer to string tha contains the commands.
 *
 * Return: 0 if succes, -1 if not.
 */
int call_fork(char **commands)
{
	int pidC, status, i;

	pidC = fork();
	if (pidC == 0)
	{
		execve(commands[0], commands, NULL);
	}
	else if (pidC > 0)
	{
		wait(&status);
		for (i = 0; commands[i]; i++)
			free(commands[i]);
		free(commands[i]);
		free(commands);
	}
	else
		_printf(2, "Process error"), exit(1);
	return (0);
}
