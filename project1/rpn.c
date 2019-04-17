#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define DEBUG(message) printf("Line [%d] - %s\n", __LINE__, message);

typedef struct stack_node stack_node;

struct stack_node
{
        signed int data;
        stack_node *prev;
};

void print_list(stack_node *stack_ptr)
{
        stack_node *tmp = stack_ptr;
        printf("List: \n");
        while(tmp != NULL)
        {
                printf("[%d, %p] -> ", tmp-> data, tmp-> prev);
                tmp = tmp-> prev;
        }
        printf("\n");
}

stack_node *new_stack(int data)
{
        stack_node *first = malloc(sizeof(stack_node));
        first-> prev = NULL;
        first-> data = data;
        return first;
}

void push(stack_node **stack_ptr, int data)
{
        stack_node *new = malloc(sizeof(stack_node));

        new-> prev = *stack_ptr;
        new-> data = data;

        *stack_ptr = new;
}

int pop(stack_node **stack_ptr)
{
        int res;
        stack_node *tmp = *stack_ptr;
        *stack_ptr = (*stack_ptr)-> prev;
        res = tmp-> data;
        free(tmp);
        return res;
}

int isoperand(int c)
{
        int res = 0;
        if (c == '+' || c == '-' || c == '*' || c == '/') {
                res = 1;
        }
        return res;
}

void free_stack(int size, stack_node **stack_ptr)
{
        int i = 0;
        while (i < size - 1) {
                int tmp = pop(&stack_ptr);
                free(tmp);
                i++;
        }
}

int main()
{
        int stack_size = 1;
        int max_size = 10;
        int c = '\0';
        int count = 0;
        int i = 0;
        int last_digit = 0;
        stack_node *stack = new_stack(0);
        _Bool should_push = false;

        while((c = getchar()) != EOF) {
                if (isdigit(c)) {
                        should_push = true;
                        i = i*10 + (c - '0');
                        last_digit = c - '0';
                }
                if (!isdigit(c)) {
                        if (!isoperand(c) && !isspace(c)) {
                                printf("line %d: error at %c\n", ++count, (char)c);
                                break;
                        } else if (should_push) {
                                if (stack_size < 10) {
                                        push(&stack, i);
                                        stack_size++;
                                } else {
                                        printf("line %d: error at %d\n", ++count, last_digit);
                                        break;
                                }
                        }
                        i = 0;
                        should_push = false;
                }
                if (isoperand(c)) {
                        char op = (char)c;
                        if (stack_size > 2) {
                                int res;
                                int b = pop(&stack);
                                stack_size--;
                                int a = pop(&stack);
                                stack_size--;
                                switch (op) {
                                        case '*':
                                                res = a*b;
                                                break;
                                        case '/':
                                                if (b == 0) {
                                                        printf("line %d: error at %c\n", ++count, op);
                                                        break;
                                                } else {
                                                        res = a/b;
                                                }
                                                break;
                                        case '+':
                                                res = a+b;
                                                break;
                                        case '-':
                                                res = a-b;
                                                break;
                                }
                                push(&stack, res);
                                stack_size++;
                        } else {
                                printf("line %d: error at %c\n", ++count, op);
                                break;
                        }
                }
                if (c == '\n') {
                        if (stack_size > 1) {
                                int res = pop(&stack);
                                printf("line %d: %d\n", ++count, res);
                        } else {
                                printf("line %d: error at %s\n", ++count, "\\n");
                        }
                        printf("stack_size : %d\n", stack_size);
                        free_stack(stack_size, &stack);
                        printf("stack_size : %d\n", stack_size);
                }
        }
        return 0;
}
