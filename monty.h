#ifndef _MONTY_H_
#define _MONTY_H_

/* Defines */

/* boolean */
#define true			1
#define false			0
/* errors */
#define	ERR_ARGCOUNT	0
#define	ERR_FOPEN		1
#define	ERR_MALLOC		2
#define	ERR_INSTRUCTION	3

/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

/* Structs */

/**
 * struct node_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct node_s
{
        int n;
        struct node_s *prev;
        struct node_s *next;
} node_t;

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
        void (*f)(node_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_invoke)(node_t **, unsigned int);

/* External Variables */
extern node_t *node;

/* Function Prototypes */
/* Node Functions */
node_t *create_node(int num);
void destroy_nodes(void);

void exit_error(unsigned int id, ...);
int file_reader(char *filename);
int tokenize(char *buffer, unsigned int line);
int run_opcode(char *op, char *value, unsigned int line);
int invoke(char *op, char *value, op_invoke f, unsigned int line);
void push(node_t **new, unsigned int line);
void pall(node_t **new, unsigned int line);
void nop(node_t **new, unsigned int line);

#endif
