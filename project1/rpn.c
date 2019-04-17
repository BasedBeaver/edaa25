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

int main()
{

        int stack_size = 1;
        int max_size = 11;
        int c = '\0';
        int count = 0;
        int i = 0;
        stack_node *stack = new_stack(0);
        _Bool should_push = false;


        while((c = getchar()) != EOF) {
                if (isdigit(c)) {
                        should_push = true;
                        i = i*10 + (c - '0');
                }
                if (!isdigit(c)) {

                        // if(stack_size < 2) {
                        //         stack_node *stack = new_stack(i);
                        //         stack_size++;
                        // } else {
                        //         push(&stack, i);
                        //         stack_size++;
                        // }

                        if (should_push) {
                                push(&stack, i);
                                //printf("i is %d when pushed too stack\n", i);
                        }
                        i = 0;
                        should_push = false;
                }
                if (isoperand(c)) {
                        char op = (char)c;
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
                                        res = a/b;
                                        break;
                                case '+':
                                        res = a+b;
                                        break;
                                case '-':
                                        res = a-b;
                                        break;
                        }
                        //printf("res is %d when pushed to stack\n", res);
                        push(&stack, res);
                        stack_size++;
                }
                if (c == '\n') {
                        int res = pop(&stack);
                        printf("line %d: %d\n", ++count, res);
                }
        }
        // print_list(stack);

        // char buff[101];
        //
        // while (fgets(buff, sizeof(buff), stdin))
        // {
        //         int n = strlen(buff);
        //         buff[n-1] = '\0';

                // int a = buff[0] - '0';
                // int b = buff[1] - '0';
                // char op = buff[2];
                // int c;
                //
                // switch (op) {
                //         case '*':
                //                 c = a*b;
                //                 break;
                //         case '/':
                //                 c = a/b;
                //                 break;
                //         case '+':
                //                 c = a+b;
                //                 break;
                //         case '-':
                //                 c = a-b;
                //                 break;
                // }
                // printf("%d %c %d = %d\n", a, op, b, c);

                // if (isdigit(c)) {
                //         push(&stack, (c-'0'));
                //         //putchar(c);
                //         //printf("\n");
                // }
                // if (operand(c)) {
                //         putchar(c);
                //         printf("\n");
                // }
                // if (isspace(c)) {
                //         //putchar(c);
                //         //printf("\n");
                // }
        // }
        // print_list(stack);
        return 0;
}
