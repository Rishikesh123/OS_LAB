#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char *argv[]) 
{
     printf(1,"==========================test1==============================\n");
     int pid=-1;
     for(int k=0;k<5;k++){
      pid=fork();
      if(pid<0){
        printf(1, "%d failed in fork!\n", getpid());
        exit();
      }
      else if(pid==0)
      {
        set_btime(getpid(),50-5*k); 
        for (int ind = 0; ind < 10; ind++) 
        {
          int i = 0;
          while (i < 1000000) i++;
        }
        exit();
      }
     }
     
     for(int k=0;k<5;k++)
     {
      pid=wait();
      if(pid!=-1){
		printf(1,"\n======================Process Id: %d completed==================================\n\n", pid,get_btime(pid));
		printproc();
	}
     }
   
  exit();
}

