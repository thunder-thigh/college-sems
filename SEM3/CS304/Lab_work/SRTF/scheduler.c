// scheduler.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FIFO_PATH "/tmp/sched_fifo"
#define MAX_PROCESSES 7

volatile sig_atomic_t work_done_flag = 0;

typedef struct {
    pid_t pid;
    int burst;
    int remaining;
    int started;
    int finished;
} Process;

Process process_table[MAX_PROCESSES];
int process_count = 0;
int running_process = -1;

void handle_sigusr1(int sig) {
    work_done_flag = 1;
}

void cleanup() {
    unlink(FIFO_PATH);
}

int main() {
    printf("[Scheduler] PID: %d\n", getpid());
    fflush(stdout);

    signal(SIGUSR1, handle_sigusr1);
    atexit(cleanup);

    // Create FIFO for communication
    mkfifo(FIFO_PATH, 0666);
    int fifo_fd = open(FIFO_PATH, O_RDONLY);

    // Receive process info
    while (process_count < MAX_PROCESSES) {
        pid_t pid;
        int burst;

        if (read(fifo_fd, &pid, sizeof(pid_t)) <= 0) break;
        if (read(fifo_fd, &burst, sizeof(int)) <= 0) break;

        process_table[process_count].pid = pid;
        process_table[process_count].burst = burst;
        process_table[process_count].remaining = burst;
        process_table[process_count].started = 0;
        process_table[process_count].finished = 0;

        printf("[Scheduler] Registered process %d with burst %d\n", pid, burst);
        kill(pid, SIGSTOP); // pause process after creation

        process_count++;
    }

    printf("[Scheduler] All processes registered. Starting scheduling...\n");

    // Scheduler loop
    while (1) {
        int all_done = 1;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!process_table[i].finished) {
                all_done = 0;
                break;
            }
        }
        if (all_done) break;

        // Find process with shortest remaining time
        int next = -1;
        int min_remaining = 9999;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!process_table[i].finished && process_table[i].remaining < min_remaining) {
                min_remaining = process_table[i].remaining;
                next = i;
            }
        }

        if (next == -1) continue;

        // Preemption
        if (running_process != -1 && running_process != next) {
            kill(process_table[running_process].pid, SIGSTOP);
            printf("[Scheduler] Paused process %d\n", process_table[running_process].pid);
        }

        if (!process_table[next].started) {
            process_table[next].started = 1;
        }

        running_process = next;
        kill(process_table[next].pid, SIGCONT);
        printf("[Scheduler] Resumed process %d (remaining %d)\n", process_table[next].pid, process_table[next].remaining);

        // Wait for SIGUSR1 (1s of work)
        work_done_flag = 0;
        while (!work_done_flag) pause();

        process_table[next].remaining--;

        if (process_table[next].remaining <= 0) {
            kill(process_table[next].pid, SIGKILL);
            waitpid(process_table[next].pid, NULL, 0);
            process_table[next].finished = 1;
            printf("[Scheduler] Finished process %d\n", process_table[next].pid);
            running_process = -1;
        }

        sleep(1); // simulate time step
    }

    printf("[Scheduler] All processes completed.\n");
    return 0;
}
