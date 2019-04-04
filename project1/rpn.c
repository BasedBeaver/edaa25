#include <stdio.h>

#define DEBUG(message) printf("Line [%d] - %s\n", __LINE__, message);

typedef struct Node
{
        int data;
        struct Node *next;
} node;

void insert(node *n_pointer, int data)
{
        while(n_pointer->next != NULL)
        {
                pointer = pointer -> next;
        }
}

int main(int argc, char *argv[])
{
        return 0;
}
