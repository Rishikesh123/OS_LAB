
#include "types.h"
#include "stat.h"
#include "user.h"

void
child_process(void)
{
  int *mem;
  // int i;
  //Run 10 iterations and in each iteration allocate 4 KB of memory using malloc
  for(int i=0; i<10; i++){
    mem = malloc(4096);
    if (mem == 0){
      printf(1, "Out of memory. Exiting\n");
      exit();
    }
  }
  mem[0] = 1;
  printf(1, "%d\n", mem[0]);
  exit();
}

int
main(int argc, char* argv[])
{
  int i, pid;
  int pids[20]; //Array to store process ids of 20 children that will be forked

  // Fork 20 children.
  for (i = 0; i < 20; i++) {
    pid = fork();
    if (pid == 0){
      child_process();
    }
    pids[i] = pid;
  }

  printf(1, "first child pid: %d\n", pids[0]);

  while(wait() >= 0);
  exit();
}
