#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * custom_getline - function to readline
 * Return: line
 */

char* custom_getline()
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos = 0;
	static int bytes_in_buffer = 0;
	char* line = NULL;
	int line_pos = 0;

	while (1)
	{
		/* Check if the buffer is empty, read more characters if necessary */
		if (buffer_pos >= bytes_in_buffer)
		{
			buffer_pos = 0;
			bytes_in_buffer = read(STDIN_FILENO, buffer, BUFFER_SIZE);

			/* If the buffer is still empty, we have reached the end of input */
			if (bytes_in_buffer == 0)
			{
				/* If we have read at least one character, return the line */
				if (line_pos > 0)
				{
					break;
				}
				else
				{
					return (NULL);
				}
			}
			else if (bytes_in_buffer < 0)
			{
				perror("Error reading from input");
				exit(EXIT_FAILURE);
			}
		}

		/* Copy characters from buffer to the line until a newline is encountered */
		while (buffer_pos < bytes_in_buffer)
		{
			char c = buffer[buffer_pos++];
			if (c == '\n')
			{
				/* Null-terminate the line and return it */
				if (line == NULL)
				{
					line = (char*)malloc(line_pos + 1);
				}
				else
				{
					line = (char*)realloc(line, line_pos + 1);
				}
				line[line_pos] = '\0';
				
				return (line);
			}
			else
			{
				if (line == NULL)
				{
					line = (char*)malloc(line_pos + 1);
				}
				else
				{
					line = (char*)realloc(line, line_pos + 1);
				}
					line[line_pos++] = c;
			}
		}
	}

	return (line);
}
