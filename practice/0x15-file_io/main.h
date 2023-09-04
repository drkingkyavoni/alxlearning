#ifndef FILE_IO_H
#define FILE_IO_H
#include <stddef.h>
#include <sys/types.h>

/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: const char pointer
 * @letters: size_t
 * Return: ss
*/
ssize_t read_textfile(const char *filename, size_t letters);

/**
 * create_file - Create a function that creates a file
 * @filename: const char pointer
 * @text_content: char pointer
 * Return: int
*/
int create_file(const char *filename, char *text_content);

/**
 * append_text_to_file - Create a function that appennds a file
 * @filename: const char pointer
 * @text_content: char pointer
 * Return: int
*/
int append_text_to_file(const char *filename, char *text_content);

#endif /* FILE_IO_H */