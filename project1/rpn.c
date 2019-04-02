#include <stdio.h>

#define DEBUG(message) printf("Line [%d] - %s\n", __LINE__, message);

int main(int argc, char *argv[])
{
  DEBUG("test");
  return 0;
}
