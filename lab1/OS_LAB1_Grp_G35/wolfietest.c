#include "types.h"
#include "user.h"
#include "stat.h"
#include "syscall.h"
#define SIZE_OF_BUFFER 6001
int main(int argc, char *argv[]) 
{	
	//Allocate SIZE_OF_BUFFER size to buffer
	void* buffer = malloc(SIZE_OF_BUFFER); 
	//Check if wolfie system call return value greater than 0, then print the content stored in buffer
	if(wolfie (buffer, SIZE_OF_BUFFER) > 0)  printf(1,"%s\n", buffer);
	//free buffer
	free(buffer);
	exit();
}
