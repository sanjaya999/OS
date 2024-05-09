#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, seek = 0, max, diff;

    printf("Enter the max range of disk: ");
    scanf("%d", &max);

    printf("Enter the size of queue request: ");
    scanf("%d", &n);

    printf("Enter the queue of disk positions to be read: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    queue[n] = head;

    // Sort the queue in ascending order
    for (i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            if (queue[j] > queue[j + 1]) {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    // Find the index of the head position in the sorted queue
    int index = 0;
    for (i = 0; i <= n; i++) {
        if (queue[i] == head) {
            index = i;
            break;
        }
    }

    // Perform C-SCAN

    // Moving towards the right end
    for (i = index; i < n; i++) {
        diff = abs(queue[i] - head);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[i], diff);
        head = queue[i];
    }

    // Move to the max range
    seek += max - head;
    printf("Disk head moves from %d to %d with seek %d\n", head, max, max - head);
    head = max;

    // Move to the left end
    seek += max;
    printf("Disk head moves from %d to %d with seek %d\n", max, 0, max);
    head = 0;

    // Moving towards the right end again
    for (i = 0; i < index; i++) {
        diff = abs(queue[i] - head);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[i], diff);
        head = queue[i];
    }

    printf("\nTotal seek time: %d\n", seek);
    float avg = seek / (float)n;
    printf("Average seek time: %f\n", avg);

    return 0;
}

