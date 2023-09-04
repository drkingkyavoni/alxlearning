#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * create_file - Create a function that creates a file
 * @filename: const char pointer
 * @text_content: char pointer
 * Return: int
*/
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t tsize;

	fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	for (tsize = 0; text_content[tsize] != '\0'; tsize++)
		;

	if (write(fd, text_content, tsize) == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
