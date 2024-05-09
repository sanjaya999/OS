#include <stdio.h>

int main() {
    int i, n, time_quantum, total = 0, count = 0, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        temp[i] = bt[i];
    }
    printf("\nProcess\t\tTurnaround Time\t\tWaiting Time\n");
    for(total = 0, i = 0; count != n; ) {
        if(temp[i] <= time_quantum && temp[i] > 0) {
            total += temp[i];
            temp[i] = 0;
            count++;
            tat = total - at[i];
            wt = tat - bt[i];
            printf("P%d\t\t\t%d\t\t\t%d\n", i+1, tat, wt);
        }
        else if(temp[i] > 0) {
            temp[i] -= time_quantum;
            total += time_quantum;
        }
        if(temp[i] == 0 && count != n) {
            count++;
            tat = total - at[i];
            wt = tat - bt[i];
            printf("P%d\t\t\t%d\t\t\t%d\n", i+1, tat, wt);
        }
        if(i == n-1)
            i = 0;
        else if(at[i+1] <= total)
            i++;
        else
            i = 0;
    }
    for(i = 0; i < n; i++) {
        avg_wt += tat - bt[i];
        avg_tat += tat - at[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);
    return 0;
}
