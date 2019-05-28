#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t stack_t;
typedef struct stack_node stack_node;

struct stack_t {
	int size;
	stack_node* head;
};

struct stack_node {
	int data;
	stack_node* prev;
};

stack_t* new_stack()
{
	stack_t* stack;
	stack = malloc(sizeof(stack_t));

	if (stack == NULL) {
		exit(1);
	}

	stack->size = 0;
	stack->head = NULL;

	return stack;
}

static stack_node* new_node(int data)
{
	stack_node* node;
	node = malloc(sizeof(stack_node));

	if (node == NULL) {
		exit(1);
	}

	node->data = data;
	node->prev = NULL;

	return node;
}

void push(stack_t* stack, int data)
{
	stack_node* node = new_node(data);

	stack_node* tmp = stack->head;
	stack->head = node;
	node->prev = tmp;

	stack->size++;
}

int pop(stack_t* stack)
{
	stack_node* tmp = stack->head;

	int data = tmp->data;
	stack->head = stack->head->prev;

	free(tmp);

	stack->size--;

	return data;
}

// UNTESTED METHOD
int peek(stack_t* stack)
{
	int data;
	if (stack->size > 0) {
		data = stack->head->data;
	}
	else {
		data = NULL;
	}
	return data;
}

void free_stack(stack_t** stack)
{
	stack_t* p = *stack;

	while(p->head != NULL) {
		pop(p);
	}
	free(p);
	*stack = NULL;
}

void print_list(stack_t* stack)
{
	 stack_node* tmp = stack->head;
	 printf("List: \n");
	 while(tmp != NULL) {
		 printf("[%d, %p] -> ", tmp->data, tmp->prev);
		 tmp = tmp->prev;
	 }
	 printf("\n");
}

int main()
{
	stack_t* stack;
	int a;

	stack = new_stack();
	//print_list(stack);
	push(stack, 2014);
	//print_list(stack);
	a = pop(stack);
	//print_list(stack);
	push(stack, 10);
	//print_list(stack);
	push(stack, 30);
	//print_list(stack);
	free_stack(&stack);

	printf("res = %d\n", stack == NULL ? 0 : 1);

	return stack == NULL ? 0 : 1;
}
