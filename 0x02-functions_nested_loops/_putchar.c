#include <unistd.h>
/**
* _putchar - writes the character c to stdout
* @c: The charater to print
* Return:0n success 1
* 0n error, -1 is returned, and error is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
