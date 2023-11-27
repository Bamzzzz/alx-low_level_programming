#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - create 1024 bytes for a buffer
 * @file: The file where characters used for the buffer are stored
 * Return: the buffer to the created file
 */
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

/**
 * close_file - the description says close file
 * @fd: the file descriptor must have a closed end
 */
void close_file(int fd)
{
int c;

c = close(fd);

if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - the contents should have a duplicate in another file
 * @argc: The character of arguments supplied to the file
 * @argv: An array of characters to the arguments.
 * Return: 0 if successful
 * Description: when the count of the arguments shows incorrect quit code 97
 * If file_from does not exist quit code 98
 * If file_to cannot be formed quit code 99
 * If file_to or file_from cannot be closed quit code 100
 */
int main(int argc, char *argv[])
{
int from, to, r, w;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

w = write(to, buffer, r);
if (to == -1 || w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (r > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}
