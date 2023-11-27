#include "main.h"
/**
 * create_file - Create a file for the project
 * @filename: the name of the file to create indicating as a pointer
 * @text_content: a string to write to the file indicated by the pointer
 * Return: If the function - -1 fails
 *         Otherwise leave as - 1.
 */
int create_file(const char *filename, char *text_content)
{
int fd, w, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}

fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
w = write(fd, text_content, len);

if (fd == -1 || w == -1)
return (-1);

close(fd);

return (1);
}
