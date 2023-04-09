#include <stdio.h>
#include "main.h"

/**
  * This program converts a binary number to an unsigned int
  * b is a prointer to binary string
  * Return: integer value
  */

unsigned int binary_to_uint(const char *b)
{	

	unsigned int base;

	if (b == NULL)
		return (0);

	while (b && *b)
	{
		if (*b < '0' || *b > '1')
			return (0);

		base = base * 2 + *b - '0';
		b++
	}

	return (base)

}
