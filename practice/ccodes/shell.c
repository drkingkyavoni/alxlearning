#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>

#define LSIZE 1024
#define S_PROMPT ""


/**
 * struct tokened - tokened struct
 * @delim: char
 * @elements: size_t
 * @words: char pointer vector
 */
struct tokened
{
	char delim;
	size_t elements;
	char **words;
};

typedef struct tokened token_t;

/**
 * setthestage - set the preparatory
 *
 * @ptoken: struct token
 * @path_token: struct token
 * Return: int
 */
int setthestage(char **env, token_t *ptoken, token_t *path_token);

/**
 * get_ssize - function to get size of string
 * @s: char pointer
 * Return: ssize_t
*/
size_t get_ssize(char *s);

/**
 * _perror - print error
 * @msg: char pointer
 * Return: void
*/
void _perror(char *msg);

/**
 * create_tokens - function to create tokens from line buffer
 * @buf: const char pointer
 * @pt: struct ptoken_t pointer
 * Return: int
*/
int create_tokens(char *buf, token_t *pt);

/**
 * nullterminate - replaces all spaces with delimiter
 * @buffer: char pointer
 * @n: ssize_t
 * @token: struct token_t
 * Return: int
*/
int nullterminate(char *buffer, size_t n, token_t *token);

/**
 * file_exists - Check if a file exists
 *
 * @env: char pointer array
 * @ptoken: struct token
 * @path_token: struct token
 * Return: int
 */
int file_exists(char **env, token_t *ptoken, token_t *path_token);

/**
 * _getsubstring - check if substring exists
 * @str: char pointer
 * @sub_string: char pointer
 * Return: int
 */
int getsubstring(char *str, char *sub_string);

/**
 * check_filepath - check file path if file exists
 *
 * @token: struct token
 * @buffer: char pointer
 * @path_token: struct token
 * Return: int
 */
int check_filepath(token_t *token, char *buffer, token_t *path_token);

/**
 * _realloc - function to realloc token pointer
 *
 * @token: struct token_t
 * Return: void
 */
void _realloc(token_t *token);

/**
 * _free - free dynamically allocated memory
 *
 * @token: struct token_t
 * Return: void
 */
void _free(token_t *token);

/**
 * _strndup - duplicate a string of length n
 *
 * @str: char pointer
 * @n: size_t
 * Return: char pointer
 */
char *_strndup(char *str, size_t n);

/**
 * _strpathcat - concatenate file path
 *
 * @path: char pointer
 * @file: char pointer
 * Return: char pointer
 */
char *_strpathcat(char *path, char *file);

/**
 * _execute_command - execute command string
 *
 * @token: struct token_t pointer
 * @env: char pointer vector
 * Return: int
 */
int _execute_command(token_t *token, char **env);

/**
 * custom_getline - custom getline
 *
 * Return: char pointer
 */
char *custom_getline(void);

/**
 * _strncmp - compare two strings
 *
 * @str: char pointer
 * @astr: char pointer
 * Return: int
 */
int _strcmp(char *str, char *astr);

/**
 * validate_builtin - validate builtin function
 *
 * @token: struct token_t
 * Return: void
 */
void validate_builtin(token_t *token);

/**
 * strtoint - convert string to int
 *
 * @s: char pointer
 * Return: int
 */
int strtoint(char *s);

/**
 * get_ssize - function to get size of string
 * @s: char pointer
 * Return: ssize_t
*/
size_t get_ssize(char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _perror - print error
 * @msg: char pointer
 * Return: void
*/
void _perror(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/**
 * getsubstring - check if substring exists
 * @str: char pointer
 * @sub_string: char pointer
 * Return: int
 */
int getsubstring(char *str, char *sub_string)
{
	size_t i;

	if (!str || !sub_string)
		return (0);

	for (i = 0; i < get_ssize(sub_string); i++)
	{
		if (str[i] != sub_string[i])
			return (0);
	}

	return (1);
}

/**
 * _strpathcat - concatenate file path
 *
 * @path: char pointer
 * @file: char pointer
 * Return: char pointer
 */
char *_strpathcat(char *path, char *file)
{
	size_t i, path_len, file_len;
	char *new_path;

	if (!path || !file)
		return (NULL);

	path_len = get_ssize(path);
	file_len = get_ssize(file);

	new_path = malloc(path_len + file_len + 2);
	if (!new_path)
	{
		perror("Error (malloc)");
		return (NULL);
	}
	for (i = 0; i < path_len; i++)
		new_path[i] = path[i];

	new_path[path_len] = '/';
	path_len++;

	for (i = 0; i < file_len; i++)
		new_path[path_len + i] = file[i];

	new_path[path_len + file_len] = '\0';

	return (new_path);
}

/**
 * _strndup - duplicate a string of length n
 *
 * @str: char pointer
 * @n: size_t
 * Return: char pointer
 */
char *_strndup(char *str, size_t n)
{
	char *new_str;
	size_t i = 0;

	if (!str)
		return (NULL);

	new_str = malloc(sizeof(char) * n);
	if (!new_str)
		return (NULL);

	for (i = 0; i < n; i++)
		new_str[i] = str[i];

	new_str[n] = '\0';

	return (new_str);
}

/**
 * _strcmp - compare two strings
 *
 * @str: char pointer
 * @astr: char pointer
 * Return: int
 */
int _strcmp(char *str, char *astr)
{
	if (get_ssize(str) != get_ssize(astr))
		return (0);

	while (*str)
	{
		if (*str ^ *astr)
			return (0);
		str++;
		astr++;
	}

	return (1);
}

/**
 * strtoint - convert string to int
 *
 * @s: char pointer
 * Return: size_t
 */
int strtoint(char *s)
{
	int res;

	if (!s)
		return (0);

	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			res = (10 * res) + (*s - '0');
		else
			break;

		s++;
	}

	return (res);
}

/**
 * create_tokens - function to create tokens from line buffer
 * @buf: const char pointer
 * @pt: struct ptoken_t pointer
 * Return: int
*/
int create_tokens(char *buf, token_t *token)
{
	if (!buf || token->words)
	{
		perror("Buffer is empty or token is full");
		return (-1);
	}

	token->elements = 0;
	token->words = NULL;

	if (nullterminate(buf, get_ssize(buf), token) == -1)
	{
		free(buf);
		_perror("Error (null terminate)");
	}

	_realloc(token);
	return (0);
}

/**
 * nullterminate - replaces all spaces with delimiter
 * @buffer: char pointer
 * @n: size_t
 * @token: struct token_t
 * Return: int
*/
int nullterminate(char *buffer, size_t n, token_t *token)
{
	size_t i, counter = 0, word_index = 0;
	char *word, **words;

	if (!buffer || !token)
		return (-1);

	word = malloc(sizeof(char) * n); /* create a blank word */
	words = malloc(sizeof(char *) * n);

	if (!word || !words)
		_perror("Error (empty words)");

	for (i = 0; i < n; i++) /* traverse char in buf */
	{
		if (buffer[i] != token->delim && buffer[i] != '\n')
		{
			word[counter] = buffer[i];
			counter++;
		}
		else
		{
			if (!counter)
				continue;

   			words[word_index] = _strndup(word, counter);
			word_index++;
			counter = 0; /* reset counter */
		}
	}
	words[word_index] = NULL;
	token->words = words;
	token->elements = word_index;

	_realloc(token);
	if (!token)
		_perror("Error (_realloc)");

	return ((!token) ? -1 : 0);
}

/**
 * _free - free dynamically allocated memory
 *
 * @token: struct token_t
 * Return: void
 */
void _free(token_t *token)
{
	if (token)
	{
		size_t i;

		if (token->words)
		{
			for (i = 0; token->words[i] != NULL; i++)
				free(token->words[i]);
			free(token->words);
		}

		token->delim = '\0';
		token->elements = 0;
	}
}

/**
 * setthestage - set the preparatory
 *
 * @ptoken: struct token
 * @path_token: struct token
 * @env: char pointer env
 * Return: int
 */
int setthestage(char **env, token_t *token, token_t *path_token)
{
	ssize_t bread;
	size_t readsize = 0;
	char *linebuf;

	if (token || path_token)
	{
		_free(token);
		_free(path_token);
	}

	linebuf = NULL;
	bread = getline(&linebuf, &readsize, stdin);

	if (bread == -1)
	{
		free(linebuf);
		_perror("Error (getline)");
	}

	if (*linebuf == '\n')
		return (1); /* return 1 for no activity */

	token->delim = ' ';
	if (create_tokens(linebuf, token) != 0)
	{
		free(linebuf);
		_perror("Error (no token)");
	}

	validate_builtin(token);

	return (file_exists(env, token, path_token));
}

/**
 * file_exists - Check if a file exists
 *
 * @env: char pointer array
 * @ptoken: struct token
 * @path_token: struct token
 * Return: int
 */
int file_exists(char **env, token_t *ptoken, token_t *path_token)
{
	char *path_buf, *search_string = "PATH=";
	size_t buf_size;

	path_token->delim = ':';
	path_token->words = NULL;

	if (!env && !ptoken)
		return (-1);
	/* check if the filename exists and return */
	if (access(ptoken->words[0], F_OK) == 0)
		return (0);
	/* if not, get the full path from env */
	while (*env)
	{
		char *s = *env;

		if (getsubstring(s, search_string)) /* check path substring */
		{
			buf_size = get_ssize(s + get_ssize(search_string));
			path_buf = malloc(sizeof(char) * buf_size);
			if (!path_buf)
				_perror("Error (malloc)");

			path_buf = s + get_ssize(search_string); /* populate buffer */
			break;
		}
		env++;
	}

	if (!path_buf)
		return (-1);

	if (check_filepath(ptoken, path_buf, path_token) != 0)
		return (-1);

	return (0);
}

/**
 * check_filepath - check file path if file exists
 *
 * @token: struct token
 * @buffer: char pointer
 * @path_token: struct token
 * Return: int
 */
int check_filepath(token_t *token, char *buffer, token_t *path_token)
{
	char *path_str, *filename, *root_path = NULL;
	size_t index;

	filename = token->words[0];
	if (!filename || !buffer || !path_token)
		return (-1);

	if (create_tokens(buffer, path_token) != 0)
	{
		free(buffer);
		_perror("Error (create token)");
	}

	for (index = 0; index < path_token->elements; index++)
	{
		root_path = path_token->words[index];
		path_str = _strpathcat(root_path, filename);
		if (access(path_str, F_OK) == 0)
		{
			token->words[0] = _strndup(path_str, get_ssize(path_str));
			return (0);
		}
	}
	free(path_str);
	return (-1);
}


/**
 * _execute_command - execute command string
 * @token: struct token_t
 * @env: char pointer vector
 * Return: int
 */
int _execute_command(token_t *token, char **env)
{
	pid_t child_proc_id;
	int wait_status;
	size_t i;

	child_proc_id = fork();
	if (child_proc_id == -1)
		_perror("Error (fork)");

	if (child_proc_id == 0)
	{
		for (i = 0; i < token->elements; i++)
			;
		execve(token->words[0], token->words, env);
		perror("Error (child)");
	}
	else
		waitpid(-1, &wait_status, 0);

	return (0);
}

/**
 * _realloc - function to realloc token pointer
 *
 * @token: struct token_t
 * Return: void
 */
void _realloc(token_t *token)
{
	char **words = NULL;
	size_t i;

	words = malloc(sizeof(char *) * token->elements);
	if (!words)
	{
		perror("Error (empty words)");
		exit(EXIT_FAILURE);
	};
	if (token->words)
	{
		for (i = 0; token->words[i] != NULL; i++)
		{
			if (token->words[i])
			{
				words[i] = _strndup(token->words[i], get_ssize(token->words[i]));
				free(token->words[i]);
			}
		}
		free(token->words);
	}
	words[token->elements] = NULL;
	token->words = words;
}

/**
 * validate_builtin - validate builtin function
 *
 * @token: struct token_t
 * Return: void
 */
void validate_builtin(token_t *token)
{
	size_t res;

	if (_strcmp(token->words[0], "exit"))
	{
		res = (token->words[1]) ? strtoint(token->words[1]) : 0;
		_free(token);
		exit(res);
	}
}


/**
 * main - primary entry point
 *
 * @argc: int
 * @argv: char pointer vector
 * @env: char pointer vector
 * Return: int
 */
int main(int argc, char **argv, char **env)
{
	token_t *token, *path_token;
	/* pid_t child_proc; */
	bool is_ftty = false;
	int flag;

	(void)argc;
	(void)argv;

	while (1 && !is_ftty)
	{
		if (!isatty(STDIN_FILENO)) /* check cmd from tty */
			is_ftty = true;
		if (write(STDOUT_FILENO, S_PROMPT, get_ssize(S_PROMPT)) == -1)
			_perror("Error (write)");
		token = malloc(sizeof(token_t));
		if (!token)
			_perror("Error (malloc token)");
		path_token = malloc(sizeof(token_t));
		if (!path_token)
			_perror("Error (malloc token)");
		flag = setthestage(env, token, path_token);
		if (flag == 1)
			continue;
		else if (flag != 0)
			perror("Error: failed to find file");
		else
		{
			if (_execute_command(token, env) != 0)
				perror("Error: bad command");
		}
		_free(token);
		_free(path_token);
	}

	return (0);
}

