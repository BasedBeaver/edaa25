#include <stdio.h>
#include <stdlib.h>

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
<<<<<<< HEAD
                printf("[%d, %p] -> ", tmp-> data, tmp-> next);
                tmp = tmp-> next;
=======
                printf("[%d, %p] -> ", tmp-> data, tmp-> prev);
                tmp = tmp-> prev;
>>>>>>> 44facdd963901f41e65bb5e2cfa3eb512b93210a
        }
        printf("\n");
}

stack_node *new_stack(int data)
{
<<<<<<< HEAD
        node *first = malloc(sizeof(node));
        first-> next = NULL;
=======
        stack_node *first = malloc(sizeof(stack_node));
        first-> prev = NULL;
>>>>>>> 44facdd963901f41e65bb5e2cfa3eb512b93210a
        first-> data = data;
        return first;
}

//Method for single linked list instead of stack
// void append(stack_node *stack_ptr, int data)
// {
//         stack_node *tmp = stack_ptr;
//         while(tmp-> prev != NULL){
//                 tmp = tmp-> prev;
//         }
//         tmp-> prev = malloc(sizeof(stack_node));
//         tmp = tmp-> prev;
//         tmp-> prev = NULL;
//         tmp-> data = data;
// }

void push(stack_node **stack_ptr, int data)
{
        stack_node *new = malloc(sizeof(stack_node));

        new-> prev = *stack_ptr;
        new-> data = data;

        *stack_ptr = new;
}

void pop(stack_node *n_ptr)
{

}

int operand(int c)
{
        int res = 0;
        if (c == '+' || c == '-' || c == '*' || c == '/') {
                res = 1;
        }
<<<<<<< HEAD
        tmp-> next = malloc(sizeof(node));
        tmp = tmp->next;
        tmp-> next = NULL;
        tmp-> data = data;
=======
        return res;
>>>>>>> 44facdd963901f41e65bb5e2cfa3eb512b93210a
}

int main()
{
<<<<<<< HEAD
        int c = '\0';
        while ((c = getchar()) != EOF)
        {
                if (isdigit(c)){
                        printf("\n");
                }
=======

        stack_node *stack = new_stack(-1);
        push(&stack, 10);
        push(&stack, 11);
        push(&stack, 12);
        print_list(stack);

        int c, last_c = '\0';
        while ((c = getchar()) != EOF)
        {
                if (isdigit(c)) {
                        putchar(c);
                        printf("\n");
                }
                if (operand(c)) {
                        putchar(c);
                        printf("\n");
                }
>>>>>>> 44facdd963901f41e65bb5e2cfa3eb512b93210a
        }
        return 0;
}
