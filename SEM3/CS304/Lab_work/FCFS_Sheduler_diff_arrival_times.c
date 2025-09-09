#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

#define MIN 1
#define MAX 5
#define MAX_PROCESSES 5

volatile sig_atomic_t work_done_flag = 0;

void sigusr1_handler(int sig) {
    work_done_flag = 1;
}

typedef struct {
    pid_t pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int started;
    int finished;
    int start_time;
    int finish_time;
} process_struct;

void child_process_work(int burst) {
    sigset_t waitset;
    sigemptyset(&waitset);
    sigaddset(&waitset, SIGCONT);

    printf("[Child %d] Starting work for %d seconds\n", getpid(), burst);
    fflush(stdout);

    for (int i = 0; i < burst; i++) {
        int sig;
        sigwait(&waitset, &sig);

        printf("[Child %d] Working 1 second (sec %d)\n", getpid(), i + 1);
        fflush(stdout);

        sleep(1);
        kill(getppid(), SIGUSR1);
    }

    printf("[Child %d] Finished work\n", getpid());
    fflush(stdout);
    exit(0);
}

int main() {
    // Setup signal handler for SIGUSR1 from children
    struct sigaction sa;
    sa.sa_handler = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    process_struct processes[MAX_PROCESSES];
    int proc_count = 0;
    int completed = 0;
    int tick = 0;

    int next_arrival = (rand() % (MAX - MIN + 1)) + MIN;

    int current_proc = -1;

    // Block SIGUSR1 and save old mask
    sigset_t mask, oldmask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    while (completed < MAX_PROCESSES) {
        // Check if new process arrives this tick
        if (proc_count < MAX_PROCESSES && tick == next_arrival) {
            int burst = (rand() % (MAX - MIN + 1)) + MIN;

            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            if (pid == 0) {
                // Child
                child_process_work(burst);
            }

            // Parent: record process info and stop child immediately
            processes[proc_count].pid = pid;
            processes[proc_count].arrival_time = tick;
            processes[proc_count].burst_time = burst;
            processes[proc_count].remaining_time = burst;
            processes[proc_count].started = 0;
            processes[proc_count].finished = 0;
            processes[proc_count].start_time = -1;
            processes[proc_count].finish_time = -1;

            kill(pid, SIGSTOP);

            printf("[Time %d] Process %d arrived (pid %d) with burst %d\n",
                   tick, proc_count + 1, pid, burst);

            proc_count++;
            next_arrival = tick + (rand() % 3 + 1); // next arrival 1-3 seconds later
        }

        // Find shortest remaining time process that arrived and unfinished
        int shortest_idx = -1;
        int shortest_time = 1e9;

        for (int i = 0; i < proc_count; i++) {
            if (!processes[i].finished && processes[i].arrival_time <= tick && 
                processes[i].remaining_time < shortest_time) {
                shortest_time = processes[i].remaining_time;
                shortest_idx = i;
            }
        }

        if (shortest_idx == -1) {
            // No process ready: CPU idle
            printf("[Time %d] CPU Idle\n", tick);
            sleep(1);
            tick++;
            continue;
        }

        // Preempt if needed
        if (current_proc != shortest_idx) {
            if (current_proc != -1) {
                kill(processes[current_proc].pid, SIGSTOP);
                printf("[Time %d] Process %d paused, remaining %d\n",
                       tick, current_proc + 1, processes[current_proc].remaining_time);
            }
            current_proc = shortest_idx;
            if (!processes[current_proc].started) {
                processes[current_proc].start_time = tick;
                processes[current_proc].started = 1;
            }
            kill(processes[current_proc].pid, SIGCONT);
            printf("[Time %d] Process %d started/resumed\n", tick, current_proc + 1);
        }

        // Wait for child's 1 second work done signal (SIGUSR1)
        work_done_flag = 0;
        while (!work_done_flag) {
            sigsuspend(&oldmask);
        }

        processes[current_proc].remaining_time--;
        tick++;

        // Check if process finished
        if (processes[current_proc].remaining_time == 0) {
            kill(processes[current_proc].pid, SIGKILL);
            waitpid(processes[current_proc].pid, NULL, 0);
            processes[current_proc].finished = 1;
            processes[current_proc].finish_time = tick;

            printf("[Time %d] Process %d finished\n", tick, current_proc + 1);

            completed++;
            current_proc = -1;
        }
    }

    // Print summary
    printf("\nAll processes finished:\n");
    printf("Proc\tArrival\tBurst\tStart\tFinish\tTurnaround\tWaiting\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        int turnaround = processes[i].finish_time - processes[i].arrival_time;
        int waiting = turnaround - processes[i].burst_time;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\t%d\n",
               i + 1,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].start_time,
               processes[i].finish_time,
               turnaround,
               waiting);
    }

    return 0;
}
