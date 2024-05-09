#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total head movement
int calculateTotalHeadMovement(int diskQueue[], int diskSize, int initialHeadPosition) {
    int totalHeadMovement = 0;
    int currentHeadPosition = initialHeadPosition;

    // Traverse the disk queue
    for (int i = 0; i < diskSize; i++) {
        // Calculate the absolute difference between the current head position and the next request
        totalHeadMovement += abs(currentHeadPosition - diskQueue[i]);
        // Update the current head position
        currentHeadPosition = diskQueue[i];
    }

    return totalHeadMovement;
}

int main() {
    int diskSize, initialHeadPosition;

    printf("Enter the size of the disk queue: ");
    scanf("%d", &diskSize);

    int* diskQueue = (int*)malloc(diskSize * sizeof(int));

    printf("Enter the disk queue: ");
    for (int i = 0; i < diskSize; i++) {
        scanf("%d", &diskQueue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initialHeadPosition);

    int totalHeadMovement = calculateTotalHeadMovement(diskQueue, diskSize, initialHeadPosition);

    printf("Total head movement using FCFS: %d\n", totalHeadMovement);

    free(diskQueue);

    return 0; // 85  55 180 150 55      45


}

