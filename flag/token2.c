#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TOKEN_MAX 100

typedef struct {
    char *words[TOKEN_MAX];
    size_t size;
    char delim;
} token_t;

int nullterminate(char *buffer, ssize_t n, token_t *token)
{
    ssize_t i;
    bool is_space = true;

    if (!buffer) /* if buffer is empty, return null */
        return -1;

    token->size = 0;

    for (i = 0; i < n; i++)
    {
        if (is_space)
        {
            if (buffer[i] != token->delim)
            {
                token->words[token->size] = &buffer[i];
                token->size++;
                is_space = false;
            }
        }
        else
        {
            if (buffer[i] == token->delim || buffer[i] == '\n')
            {
                buffer[i] = '\0';
                is_space = true;
            }
        }
    }

    return 0;
}

int main() {
    char buffer[] = "what the hell    o     n    p";
    token_t token;
    size_t i;

    token.delim = ' ';

    nullterminate(buffer, sizeof(buffer), &token);

    printf("word size: %ld\n", token.size);
    for (i = 0; i < token.size; i++) {
        printf("Word %ld: %s\n", i, token.words[i]);
    }

    return 0;
}
