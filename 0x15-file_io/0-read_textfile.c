#include "main.h"
#include <stdlib.h>
/**
 * read_textfile- Read text file and print it to the STDOUT
 * @filename: title of the saved text file
 * @letters: number of letters read by the text file
 * Return: w- actual number of bytes read and printed by the textfile
 * 0 when filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);

free(buf);
close(fd);
return (w);
}
