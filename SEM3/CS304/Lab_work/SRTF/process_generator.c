// process_generator.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>

#define FIFO_PATH "/tmp/sched_fifo"
#define MAX_PROCESSES 7
#define MIN_BURST 1
#define MAX_BURST 5

void child_worker(pid_t scheduler_pid, int burst) {
    // Block SIGCONT so we can use sigwait
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCONT);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    for (int i = 0; i < burst; i++) {
        int sig;
        sigwait(&mask, &sig); // wait for SIGCONT

        printf("[Child %d] Working 1 sec (%d/%d)\n", getpid(), i + 1, burst);
        fflush(stdout);
        sleep(1);
        kill(scheduler_pid, SIGUSR1); // notify scheduler
    }

    exit(0);
}

int main() {
    pid_t scheduler_pid;
    printf("[Generator] Enter Scheduler PID: ");
    scanf("%d", &scheduler_pid);

    int fifo_fd = open(FIFO_PATH, O_WRONLY);
    if (fifo_fd < 0) {
        perror("Cannot open FIFO");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < MAX_PROCESSES; i++) {
        int burst = (rand() % (MAX_BURST - MIN_BURST + 1)) + MIN_BURST;

        pid_t pid = fork();
        if (pid == 0) {
            child_worker(scheduler_pid, burst);
        }

        // Send to scheduler
        write(fifo_fd, &pid, sizeof(pid_t));
        write(fifo_fd, &burst, sizeof(int));
        printf("[Generator] Sent process %d with burst %d\n", pid, burst);

        sleep(rand() % 3 + 1); // simulate random arrivals
    }

    close(fifo_fd);
    return 0;
}
