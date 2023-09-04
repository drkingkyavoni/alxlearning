#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

extern int result;

#define INST_ARR \
	{ \
		{"add", add}, \
		{"pall", pall}, \
		{"pop", pop} \
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * process_instructions - function to process file argument
 *
 * @arg: char pointer
 */
void process_instructions(char **arg);

/**
 * parseline - function parses the line
 *
 * @line: char pointer
 * @len: size_t
 */
void parseline(char *line, size_t len);

/**
 * pint - function that prints the top
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void pint(stack_t **head, unsigned int line);

/**
 * pall - function that prints all elements in a stack
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void pall(stack_t **head, unsigned int line);

/**
 * _errexit - function that stderr a message
 *
 * @msg: char pointer
 * Return: void
 */
void _errexit(char *msg);

/**
 * _stdexit - function that stderr a message
 *
 * @msg: char pointer
 * Return: void
 */
void _stdexit(char *msg);

/**
 * pop - function that pop the top
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void pop(stack_t **head, unsigned int line);

/**
 * push - function that oush the top
 *
 * @head: struct stack_t
 * @line: unsigned int
 */
void push(stack_t **head, unsigned int line);



#endif /* MONTY_H */