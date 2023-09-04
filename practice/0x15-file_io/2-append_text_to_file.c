#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - Create a function that creates a file
 * @filename: const char pointer
 * @text_content: char pointer
 * Return: int
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t tsize;

	fd = open(filename, O_WRONLY|O_APPEND, 0x664);

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
