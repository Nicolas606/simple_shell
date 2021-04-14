#include "holberton.h"

/**
 * solo_spaces - Check if the buffer contains just spaces
 * @buffer: The buffer
 *
 * Return: 1 if are just spaces, 0  if not.
 */
int solo_spaces(char *buffer)
{
	int i = 0, control = 1;

	while (buffer[i])
	{
		if (buffer[i] != 32 && buffer[i] != 0)
			control = 0;
		i++;
	}
	return (control);
}

/**
 * split_input - Split the buffer string of commands in individual words.
 * @buffer: The array that contain the string.
 *
 * Return: Double pointer to commands string.
 */
char **split_input(char *buffer)
{
	char **commands = NULL;
	int i, control = 0, words_buff = 1;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != 32 && control == 0)
		{
			words_buff++;
			control = 1;
		}
		if (buffer[i] == 32)
			control = 0;
	}
	commands = malloc(sizeof(char *) * words_buff);
	if (commands == NULL)
		return (0);

	for (i = 0; i < words_buff - 1; i++)
	{
		commands[i] = malloc(256);
		if (commands[i] == NULL)
		{
			for (; i >= 0; i--)
				free(commands[i]);
			free(commands);
			_printf(2, "malloc error"), exit(1);
		}
		if (i == 0)
			_strcpy(commands[i], strtok(buffer, " "));
		else
			_strcpy(commands[i], strtok(NULL, " "));
	}
	commands[i] = NULL;
	quit_spaces(commands);
	return (commands);
}

/**
 * quit_spaces - Delete spaces at beginning and end of strings.
 * @commands: Double pointer to string tha contains the commands.
 */
void quit_spaces(char **commands)
{
	int i = 0, j = 0;

	while (commands[i] != NULL)
	{
		for (j = 0; commands[i][j]; j++)
		{
			if (commands[i][j] == 32)
				commands[i][j] = 0;
		}
		i++;
	}
}
