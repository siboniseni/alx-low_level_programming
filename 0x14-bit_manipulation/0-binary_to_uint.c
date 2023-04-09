#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - A finction that converts binary number
 * to an unsigned integer
 * @b: A pointer to binary string
 * Return: unsigned integer converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int d = 0;

	if (b == NULL)
		return (0);

	while (b && *b)
	{
		if (*b < '0' || *b > '1')
			return (0);

		d = d * 2 + *b - '0';
		b++;
	}

	return (d);

}

