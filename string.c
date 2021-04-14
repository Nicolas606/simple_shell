#include "holberton.h"

/**
 * _strcpy -  function that copies the string pointed to by src, including
 * the terminating null byte (\0), to the buffer pointed to by dest
 * @dest: variable that the exercise gives us
 * @src: variable that the exercise give us
 * Return: int
 */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: The first string to be compared.
 * @s2: Compare the second string.
 *
 * Return: char
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int compares = 0;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			compares = s1[i] - s2[i];
			break;
		}
	}
	return (compares);
}

/**
 * _strcat-function that concatenates two strings.
 * @dest: variable that the exercise gives us
 * @src: variable that the exercise gives us
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	char *i;
	char *p;

	for (i = dest; *i != '\0'; i++)
		;

	for (p = src; *p != '\0'; p++, i++)
		*i = *p;

	*i = '\0';

	return (i);
}


/**
 * _strdup - function that returns a pointer to a newly allocated space in
 *  memory, which contains a copy of the string given as a parameter.
 *
 * @str: String that we are going to copy.
 *
 *
 *
 * Return: s
 *
 */

char *_strdup(char *str)
{
	int i;
	int length = 0;
	char *s;

	if (str == 0)
		return (0);

	while (str[length])
		length++;

	s = malloc(sizeof(char) * length + 1);

	if (s == 0)
		return (0);

	for (i = 0; i <= length; i++)
		s[i] = str[i];

	return (s);
}

