#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - prints a name from a given string
 * @name: string name
 * @f: fuction that defines how name is printed
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL || f != NULL)
		(*f)(name);
}
