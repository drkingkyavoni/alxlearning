#include <stdio.h>
#include <string.h>

int get_substring(char *str, char *substring)
{
	size_t i;

	if (!str || !substring)
		return (0);

	for (i = 0; i < strlen(substring); i++)
	{
		if (str[i] != substring[i])
			return (0);
	}

	return (1);
}

int main(int argc, char **argv, char **env)
{
	char *substring;
	(void)argc;
	(void)argv;

	substring = "PATH=";

	while (*env)
	{
		char *s = *env;
		if (get_substring(s, substring))
		{
			printf("%ld\n", strlen(s + 5));
			printf("%s\n", s + 5);
			break;
		}
		env++;
	}
	return (0);
}