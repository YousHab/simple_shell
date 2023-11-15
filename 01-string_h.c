#include "shell.h"

/**
 * _strdup - a pointer to the result of duplication.
 *           
 * @s:  pointer to the string to be copied
 *
 * Return: a pointer ti new new char
 */
char *my_strdup(char *s)
{
	char *str;
	int i;

	if (s == NULL)
		return (NULL);

	str = malloc(sizeof(char) * (_strlen(s) + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < _strlen(s) + 1; i++)
		str[i] = s[i];

	return (str);
}
/**
 * _strcmp - compare two strings.
 * 
 * @s1: first string
 * @s2: second string
 * 
 * Return
 * 
*/
int my_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	return (*s1 - *s2);
}

/**
 * _strlen - return the length of a string.
 *
 * @s: the string to be evaluated.
 *
 * Return: nothing
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != 0)
	{
		len++;
	}
	return (len);
}

/**
 * _strcat - This function concatenates two strings.
 *
 * @dest: the string to be added to.
 * @src : string to be added.
 *
 * Return: a pointer to dest.
 *
 */

const char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (*(src + i) != 0)
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
}


