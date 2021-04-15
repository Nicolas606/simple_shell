#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * @name: The name of environment variable to gets.
 * @env: enviroment.
 *
 * Return: The string of the envioroment variable
 */
char *_getenv(const char *name, char *env[])
{
	int i = 0, j = 0, control = 1;
	char *path = NULL;

	while (env[i])
	{
		j = 0;
		for ( ; name[j]; j++)
		{
			if (env[i][j] != name[j])
			{
				control = 0;
				break;
			}
			else
			{
				control = 1;
				continue;
			}
		}
		if (env[i][j] == '=' && control == 1)
		{
			env[i] += j + 1;
			path = env[i];
			return (path);
		}
		i++;
	}
	return (0);
}
