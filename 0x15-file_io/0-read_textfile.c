#include "main.h"
#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    char *buffer;
    ssize_t bytes_read, bytes_written;

    // Check if filename is NULL
    if (filename == NULL) {
        return 0;
    }

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    // Allocate a buffer to store the file contents
    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL) {
        close(fd);
        return 0;
    }

    // Read up to letters bytes from the file
    bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        close(fd);
        free(buffer);
        return 0;
    }

    // Write the file contents to stdout
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read) {
        close(fd);
        free(buffer);
        return 0;
    }

    // Clean up and return the number of bytes written
    close(fd);
    free(buffer);
    return bytes_written;
}

