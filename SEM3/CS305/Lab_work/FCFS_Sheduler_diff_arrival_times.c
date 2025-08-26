#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10
#define MAX_PROCESSES 10

volatile sig_atomic_t work_done_flag = 0;

void sigusr1_handler(int sig){
	work_done_flag = 1;
}

typedef struct{
	pid_t pid;
	int arrival_time;
	int burst_time;
	int remaining_time;
	int started;
	int finished;
	int start_time;
	int finish_time;
} process_struct;

void child_process_work(int burst){
	for(int i=0; i<burst-time; i++){
		pause();
		sleep(1);
		kill(getppid(), SIGUSR1);
	}
	exit(0);
}

void daemonize(){
	pid_t pid;

	pid = fork();
	if (pid<0) {
		perro("Could not fork\n");
		exit(EXIT_FAILURE);
	}
	if (pid>0) exit(EXIT_SUCCESS);

	umask(0);
	setsid();
	chdir("/");

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	srand(time(NULL));
	int random_number = (rand()%(MAX-MIN+1))+MIN;
	if (pid ==0) {
		printf("[Child] %d:\tDoing work\n");
		sleep(random_number);
		exit(0);
	}
	else {
		int status;
		waitpid(pid, &status, 0);
		time_t end_time = time(NULL);
	}
}

int main(){
	time_t parent_epoch = time(NULL);
	printf("[Parent]:\tEpoch at start is %ld\n", parent_epoch);
	srand(time(NULL));
	process_struct processes_info[MAX_PROCESSES];
	int completed_processes=0;
	int tick_seconds=0;
	int next_arrival_time = (rand()%(MAX-MIN+1))+MIN;
	while(completed_processes<MAX_PROCESSES){
		sleep(1);
		tick_seconds++;
	}

