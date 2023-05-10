#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}
/**
 * close_file - Closes file descriptors.
 *
 * @fd: The file descriptor to be closed.
 */
void close_file(int f)
{
	if (close(f) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close f %d\n", f);
		exit(100);
	}
}
/**
 * main - Copies contents of file to
 *	 another file.
 * @argc: number of arguments supplied to the program.
 * @argv: An array of pointers to arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - 
 * 	exit code 97.
 * If file_from does not exist or cannot be read - 
 * 	exit code 98.
 * If file_to cannot be created or written to -
 * 	 exit code 99.
 * If file_to or file_from cannot be closed - 
 * 	exit code 100.
 *
 */
int main(int argc, char *argv[])
{
	int from, to, re, rw;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create(argv[2]);
	from = open(argv[1], O_RDONLY);
	re = read(from, buffer, BUFFER_SIZE);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || re == -1)
		{

			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[2]);
			free(buffer);
			exit(98);
		}
		rw = write(to, buffer, re);

		if (to == -1 || rw == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		re = read(from, buffer, BUFFER_SIZE);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rw > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
