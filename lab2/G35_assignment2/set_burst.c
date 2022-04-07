#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	int pid, tm;
	if(argc < 3){
		printf(2,"Error: Format should be set_burst pid burst_time\n");
		exit();
	}
	pid = atoi(argv[1]);
	tm = atoi(argv[2]);
	if(tm < 0){
		printf(2,"Invalid time: time should be greater than 0\n");
		exit();
	}
	set_btime(pid,tm);
	exit();
}
