#ifndef _MONTY_H_
#define _MONTY_H_

/* Defines */
#define ERR_ARGCOUNT	0
#define ERR_FOPEN		1
/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} list_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void print_error(unsigned int id, ...);
void file_reader(char *filename);

#endif
