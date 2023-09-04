#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** words;
    size_t* word_size;
    size_t size;
    char delim;
} token_t;

int nullterminate(char* buffer, ssize_t n, token_t* token) {
	ssize_t i;
    size_t buffer_length;
    size_t word_count = 0;
    size_t word_length = 0;
    bool inside_word = false;

	if (!buffer || !token)
        return -1;

	buffer_length = strlen(buffer);
    token->words = malloc(sizeof(char*) * buffer_length);
    token->word_size = malloc(sizeof(size_t) * buffer_length);
    if (!token->words || !token->word_size)
        return -1;


    for (i = 0; i < n; i++) {
        if (buffer[i] == '\n')
            break;

        if (buffer[i] == token->delim) {
            if (inside_word) {
                token->word_size[word_count] = word_length;
                token->words[word_count] = &buffer[i - word_length];
                word_count++;
                word_length = 0;
                inside_word = false;
            }
        } else {
            word_length++;
            inside_word = true;
        }
    }

    /* Handle the last word if it doesn't end with a delimiter */
    if (inside_word) {
        token->word_size[word_count] = word_length;
        token->words[word_count] = &buffer[n - word_length];
        word_count++;
    }

    token->size = word_count;

    return 0;
}

int main() {
    char buffer[] = "what the hell    o     n    p";
    token_t token;
	size_t i;
    token.words = NULL;
    token.word_size = NULL;
    token.size = 0;
    token.delim = ' ';

    nullterminate(buffer, sizeof(buffer), &token);

	printf("word size: %ld\n", token.size);
    for (i = 0; i < token.size; i++) {
        printf("Word %ld: %.*s\n", i, (int)token.word_size[i], token.words[i]);
    }

    free(token.words);
    free(token.word_size);

    return 0;
}
