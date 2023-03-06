#include <stdio.h>
#include "main.h"

/**
  * _memset - a function that fills memory with a constant byte.
  * @s:pointer to the bytes of the memory area
  * @b: constant byte
  * @n:number of bytes of the memory area pointed to by s
  * Return: pointer to the memory area s
  */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < n; m++)
	{
		s[m] = b;
	}
	return (s);
}
