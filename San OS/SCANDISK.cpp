#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, seek=0, max;

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

    // Sort the queue in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (queue[j] > queue[j + 1]) {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    int start = 0;
    for (i = 0; i < n; i++) {
        if (queue[i] >= head) {
            start = i;
            break;
        }
    }

    printf("Disk head moves from %d to %d with seek %d\n", head, queue[start], abs(head - queue[start]));
    seek += abs(head - queue[start]);
    head = queue[start];

    printf("Disk head moves in a SCAN fashion:\n");
    for (i = start; i < n; i++) {
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[i], abs(head - queue[i]));
        seek += abs(head - queue[i]);
        head = queue[i];
    }

    printf("Disk head moves from %d to %d with seek %d\n", head, max, abs(head - max));
    seek += abs(head - max);
    head = max;

    for (i = start - 1; i >= 0; i--) {
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[i], abs(head - queue[i]));
        seek += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\nTotal seek time: %d\n", seek);
    float avg = (float) seek / n;
    printf("Average seek time: %f\n", avg);

    return 0;
}

