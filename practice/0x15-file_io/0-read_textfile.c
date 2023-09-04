#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: const char pointer
 * @letters: size_t
 * Return: ss
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t bread, bwrite;

	if (!filename || letters <= 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (!buf)
	{
		close(fd);
		return (0);
	}

	bread = read(fd, buf, letters);
	if (bread <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	bwrite = write(STDOUT_FILENO, buf, bread);
	if (bread != bwrite)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (bwrite);
}