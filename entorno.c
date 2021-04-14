#include "holberton.h"

/**
 * _getenv - gets an environment variable
 * @name: The name of environment variable to gets.
 *
 * Return: The string of the envioroment variable
 */
char *_getenv(const char *name)
{
	int i = 0, j = 0, control = 1;
	char **var = environ;
	char *path = NULL;

	while (var[i])
	{
		j = 0;
		for ( ; name[j]; j++)
		{
			if (var[i][j] != name[j])
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
		if (var[i][j] == '=' && control == 1)
		{
			var[i] += j + 1;
			path = var[i];
			return (path);
		}
		i++;
	}
	return (0);
}

/**
 * add_node - Adds new node at the beginning of a list.
 *
 * @head: Pointer to list head.
 * @str: The string to copy in str element of the node.
 * Return: The address of the new element or NULL if it failed.
 */
dir *add_node(dir **head, const char *str)
{
	dir *new;

	if (head == 0)
	return (0);
	new = malloc(sizeof(dir));
	if (new == 0)
	{
		free(new);
		return (0);
	}
	new->directory = _strdup(str);
	if (new->directory == 0)
	{
		free(new);
		return (0);
	}
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * free_list - frees a listint_t list.
 *
 * @head: address of pointer to linkedlist head.
 */
void free_list(dir **head)
{
	dir *tmp;

	if (head == NULL || *head == NULL)
	return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp->directory);
		free(tmp);
	}
}

/**
 * path_directories - Builds a linked list of the PATH directories.
 *
 * Return: Pointer to head of linkedlist head.
 */
dir *path_directories(void)
{
	char *path = NULL;
	dir *head;

	head = NULL;
	path = _getenv("PATH");
	path = strtok(path, ":");
	add_node(&head, path);

	while (path != NULL)
	{
		add_node(&head, path);
		path = strtok(NULL, ":");
	}

	return (head);
}
