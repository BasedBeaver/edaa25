#include <stdio.h>

#define DEBUG(message) printf("Line [%d] - %s\n", __LINE__, message);

typedef struct {
  int *stack;
  size_t used;
  size_t size;
} dynamicStack;

void initStack(dynamicStack *a, size_t initialSize) {
  a->stack = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertStack(dynamicStack *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size
  if (a->used == a->size) {
    a->size *= 2;
    a->stack = (int *)realloc(a->stack, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(dynamicStack *a) {
  free(a->stack);
  a->stack = NULL;
  a->used = a->size = 0;
}

int main(int argc, char *argv[])
{
        return 0;
}
