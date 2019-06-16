#include <stdio.h>
#include <stdlib.h>

typedef struct list_t list_t;
typedef struct node_t node_t;

struct list_t {
	int size;
	node_t* first;
	node_t* last;
};

struct node_t {
	void* data;
	node_t* next;
	node_t* prev;
};

list_t* new_list()
{
	list* list = malloc(sizeof(list_t));

	if (list == NULL) {
		exit(1);
	}

	list->size = 0;
	list->first = NULL;
	list->last = NULL;

	return list;
}

node_t* new_node(void* data)
{
	node_t* node = malloc(sizeof(node_t));

	if (node == NULL) {
		exit(1);
	}

	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void insert_first(list_t* list, void* data)
{
	node_t* n = new_node(data);

	if (list->size == 0) {
		list->last = n;
	}
	else {
		n->next = list->first;
	}
	list->first->prev = n;
	list->first = n;
}


void print_list(list_t* list)
{
	 stack_node* tmp = list->head;
	 printf("List: \n");
	 while(tmp != NULL) {
		 printf("[%d, %p] -> ", tmp->data, tmp->prev);
		 tmp = tmp->prev;
	 }
	 printf("\n");
}


int main()
{
	return 0;
}
