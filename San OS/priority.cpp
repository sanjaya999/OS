#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 4

struct process {
    int id;
    int burst_time;
    int priority;
};

void priority_scheduling(struct process *processes, int num_processes) {
    int waiting_times[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        waiting_times[i] = 0;
    }

    int remaining_burst_times[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        remaining_burst_times[i] = processes[i].burst_time;
    }

    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes != num_processes) {
        int highest_priority_index = -1;
        int highest_priority = MAX_PROCESSES + 1;

        for (int i = 0; i < num_processes; i++) {
            if (remaining_burst_times[i] > 0 && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }

        remaining_burst_times[highest_priority_index]--;

        for (int i = 0; i < num_processes; i++) {
            if (i != highest_priority_index && remaining_burst_times[i] > 0) {
                waiting_times[i]++;
            }
        }

        current_time++;

        if (remaining_burst_times[highest_priority_index] == 0) {
            completed_processes++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d waiting time: %d\n", processes[i].id, waiting_times[i]);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    processes[0].id = 0;
    processes[0].burst_time = 5;
    processes[0].priority = 1;
    processes[1].id = 1;
    processes[1].burst_time = 10;
    processes[1].priority = 2;
    processes[2].id = 2;
    processes[2].burst_time = 2;
    processes[2].priority = 3;

    priority_scheduling(processes, sizeof(processes) / sizeof(struct process));

    return 0;
}
