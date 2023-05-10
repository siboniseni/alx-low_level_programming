#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters) {
    // Check if filename is NULL
    if (filename == NULL) {
        return 0;
    }

    // Open the file for reading
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    // Allocate a buffer to store the file contents
    char *buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL) {
        close(fd);
        return 0;
    }

    // Read up to letters bytes from the file
    ssize_t bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        close(fd);
        free(buffer);
        return 0;
    }

    // Write the file contents to stdout
    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
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

int main() {
    // Read and print the contents of "example.txt"
    ssize_t bytes_read = read_textfile("example.txt", 1024);
    if (bytes_read == 0) {
        fprintf(stderr, "Error reading file.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

