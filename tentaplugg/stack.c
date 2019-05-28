#include <stdio.h>
#include <stdlib.h>

typedef struct stack_head stack_head;
typedef struct stack_t stack_t;

struct stack_head {
	int size;
	stack_t* stack;
};

struct stack_t {
	int data;
	stack_t* prev;
};


int main()
{
	stack_t* stack;
	int a;

	stack = new_stack();

	push(stack, 2014);
	a = pop(stack);
	push(stack, 10);
	push(stack, 30);
	free_stack(&stack);

	return stack == NULL ? 0 : 1;
}
