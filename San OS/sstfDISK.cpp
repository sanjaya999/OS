#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    // Simple implementation of bubble sort 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, head;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n], distance[n], total_seek_time = 0;
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Calculate distances from head to each request
    for (int i = 0; i < n; i++) {
        distance[i] = abs(head - requests[i]); 
    }

    // SSTF Logic
    int current_pos = head; 
    int visited[n] = {0}; // Keep track of visited requests 

    for (int i = 0; i < n; i++) {
        int shortest_index = -1;
        int shortest_distance = INT_MAX;

        // Find the closest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < shortest_distance) {
                shortest_index = j;
                shortest_distance = distance[j];
            }
        }

        // Update total seek time and mark as visited
        total_seek_time += shortest_distance;
        visited[shortest_index] = 1;

        // Update the current position to the newly serviced request
        current_pos = requests[shortest_index]; 
    }

    printf("Total seek time: %d\n", total_seek_time);

    return 0;
}

