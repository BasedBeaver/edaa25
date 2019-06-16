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
	node_t* prev;
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


int main()
{
	return 0;
}
