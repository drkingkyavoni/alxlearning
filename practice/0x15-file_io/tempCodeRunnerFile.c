#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define FILE_MAX 1024

/**
 * print_msg - print message
 * @err_code: int
 * @msg: char pointer
 * @arg: char pointer
 * Return: void
*/
void print_msg(int err_code, char *msg, char *arg)
{
	if (!arg)
		(void)arg;

	dprintf(STDERR_FILENO, msg, arg);
	exit(err_code);
}

/**
 * print_msg - print message
 * @err_code: int
 * @msg: char pointer
 * @arg: char pointer
 * Return: void
*/
void print_imsg(int err_code, char *msg, int i)
{
	dprintf(STDERR_FILENO, msg, i);
	exit(err_code);
}

/**
 * check_fd - check validity of file descriptor
 * @fd: int
 * @err_code: int
 * @msg: char pointer
 * @arg: char pointer
 * Return: void
*/
void check_fd(int fd, int err_code, char *msg, char *arg)
{
	if (fd == -1)
	{
		if (close(fd) == -1)
			dprintf(fd, "Error: Can't close fd %d\n", fd);
		print_msg(err_code, msg, arg);
	}
}

/**
 * main - gateway to unleashing the dragon
 * @argc: int
 * @argv: char vector
 * Return: int
*/
int main(int argc, char **argv)
{
	int fds, fdd, bsclose, bdclose;
	ssize_t bread, bwrite;
	char *buf;

	if (argc != 3) /* check for the number of arguments */
		print_msg(97, "Usage: cp file_from file_to\n", NULL);

	fds = open(argv[1], O_RDONLY); /* open source file */
	check_fd(fds, 98, "Error: Can't read from %s\n", argv[1]);

	buf = malloc(sizeof(char) * FILE_MAX); /* create buffer */
	if (!buf)
		exit(EXIT_FAILURE);

	bread = read(fds, buf, FILE_MAX); /* read source file to buffer */
	if (bread == -1)
		free(buf);
	check_fd(bread, 98, "Error: Can't read from %s\n", argv[1]);

	fdd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0664); /* create dest file */
	check_fd(fdd, 99, "Error: Can't write to %s\n", argv[2]);

	bwrite = write(fdd, buf, bread); /* write from buffer to dest file */
	if (bwrite != bread)
		free(buf);
	check_fd(bwrite, 99, "Error: Can't write to %s\n", argv[2]);

	if (buf)
		free(buf);
	bsclose = close(fds);
	if (bsclose == -1)
		print_imsg(100, "Error: Can't close fd %d\n", bsclose);
	bdclose = close(fdd);
	if (bdclose == -1)
		print_imsg(100, "Error: Can't close fd %d\n", bdclose);

	return (0);
}
