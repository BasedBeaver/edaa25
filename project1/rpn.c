#include <stdio.h>
#include <stdlib.h>

#define DEBUG(message) printf("Line [%d] - %s\n", __LINE__, message);

typedef struct node node;

struct node
{
        int data;
        node *next;
};

void print_list(node *n_ptr)
{
        node *tmp = n_ptr;
        printf("List: \n");
        while(tmp != NULL)
        {
                printf("[%d, %p] -> ", tmp->data, tmp->next);
                tmp = tmp -> next;
        }
        printf("\n");
}

node *new_list(int data)
{
        node *first = malloc(sizeof(node));
        first->next = NULL;
        first->data = data;
        return first;
}

void append(node *n, int data)
{
        node *tmp = n;
        while(tmp->next != NULL){
                tmp = tmp->next;
        }
        tmp->next = malloc(sizeof(node));
        tmp = tmp->next;
        tmp->next = NULL;
        tmp->data = data;
}

int main()
{
        int c, last_c = '\0';
        while ((c = getchar()) != EOF)
        {
                if (!isspace(c)){
                        putchar(c);
                }
                if (!isspace(last_c)) {
                        putchar('\n');
                }
                last_c = c;
        }
        if (last_c != '\0' && !isspace(last_c)) {
                putchar('\n');
        }
        return 0;
}
