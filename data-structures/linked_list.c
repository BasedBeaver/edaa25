#include <stdio.h>
#include <stdlib.h>

typedef struct list_t list_t;
typedef struct node_t node_t;

struct list_t {
	node_t* first;
	node_t* last;
};

struct node_t {
	void* data;
	node_t* next;
};

list_t* new_list()
{
	list* list = malloc(sizeof(list_t));

	if (list == NULL) {
		exit(1);
	}

	list->first = NULL;
	list->last = NULL;

	return list;
}

static node_t* new_node(void* data)
{
	node_t* node = malloc(sizeof(node_t));

	if (node == NULL) {
		exit(1);
	}

	node->data = data;
	node->next = NULL;

	return node;
}

void insert_first(list_t* list, void* data)
{
	node_t* node = new_node(data);
	if (list->last = NULL) {
		list->last = node;
	}
	else {
		node->next = list->first;
	}
	list->first = node;
}

void insert_last(list_t* list, void* data)
{
	node_t* node = new_node(data);
	if (list->first = NULL) {
		list->first = node;
	}
	else {
		list->last->next = node;
	}
	list->last = node;
}

// NOT ALL CASES COVERED!!!
void* remove_first(list_t* list)
{
	void* data = list->first->data;

	list_t* tmp = list->first;
	list->first = list->first->next;
	free(tmp);

	return data;
}

int main()
{
	return 0;
}
