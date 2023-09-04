#include "monty.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		_stdexit("USAGE: monty file");

	process_instructions(argv[1]);
	return (0);
}

void process_instructions(char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (!filename)
		_stdexit("the file name is empty");

	file = fopen(filename, "r"); /* open the file */
	/* if open is successful, read lines */
	if (file == NULL)
		_stdexit("the file couldn't be open");

	/* if read is successful, parse each line*/
	while ((read = getline(&line, &len, file)) != -1)
		parseline(line, len);

	fclose(file); /* close file at end of file */
	free(line); /* free buffered line */
}