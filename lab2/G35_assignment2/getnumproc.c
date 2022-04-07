#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  printf(1,"Currently %d processes are running in your system\n",numproc());
  exit();
}
