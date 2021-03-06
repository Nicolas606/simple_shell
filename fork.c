#include "holberton.h"

/**
 * comp - Check if command exist in directory or environment.
 * @line: Number of line write by the user.
 * @salir: Exit code of the program.
 * @commands: Double pointer to string tha contains the commands.
 * @argv: Arguments string array.
 * @env: enviroment.
 * Return: 1 if exists, 0 if not.
 */
int comp(int line, int *salir, char **commands, char *argv[])
{
	int i;

	*salir = 0;
	if (access(commands[0], F_OK) != 0)
	{
		if (existencia(&commands[0]) == 0)
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
 * @path: enviroment path.
 * Return: 1 if file exists, 0 if not.
 */
int existencia(char **command_0)
{
	char str[2048], *directory, copia[2048];
	char *path = _getenv("PATH", environ);

	_strcpy(copia, path);
	directory = strtok(copia, ":");
	while (directory != NULL)
	{
		_strcpy(str, directory);
		_strcat(str, "/");
		_strcat(str, *command_0);
		if (access(str, F_OK) == 0)
		{
			free(*command_0);
			*command_0 = _strdup(str);
			return (1);
		}
		directory = strtok(NULL, ":");
	}
	return (0);
}

/**
 * call_fork - Check if a command exists, and executes it.
 * @commands: Double pointer to string tha contains the commands.
 * @salir: pinter to exit code.
 * @env: enviroment.
 * Return: 0 if succes, -1 if not.
 */
int call_fork(char **commands, int *salir)
{
	int pidC, status, i;

	pidC = fork();
	if (pidC == 0)
	{
		execve(commands[0], commands, environ);
	}
	else if (pidC > 0)
	{
		wait(&status);
		*salir = WEXITSTATUS(status);
		for (i = 0; commands[i]; i++)
			free(commands[i]);
		free(commands[i]);
		free(commands);
	}
	else
		_printf(2, "Process error"), exit(1);
	return (0);
}
