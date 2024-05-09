#include <stdio.h>

void best_fit(int blockSize[], int m, int processSize[], int n) {
    // Stores block id of the block allocated to a process
    int allocation[n];

    // Initialize all blocks as not allocated
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; 
    }

    // Pick each process and find suitable blocks according to best-fit algorithm
    for (int i = 0; i < n; i++) {
        // Find the best fit block for the current process 
        int bestIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1) {
                    bestIndex = j;
                } else if (blockSize[bestIndex] > blockSize[j]) {
                    bestIndex = j;
                }
            }
        }

        // If a block is found, allocate it to the process
        if (bestIndex != -1) {
            allocation[i] = bestIndex;

            // Reduce available memory in this block
            blockSize[bestIndex] -= processSize[i];
        }
    }

    // Output the allocation results
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    // Example usage
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    best_fit(blockSize, m, processSize, n);

    return 0;
}

