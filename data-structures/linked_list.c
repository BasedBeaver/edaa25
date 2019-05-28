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

int main()
{
	return 0;
}
