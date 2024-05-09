#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

int main() {
    int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Changed page reference sequence

    int pageFaults = 0;
    int frames[MAX_FRAMES];
    int futureReference[MAX_FRAMES];
    int i, j;

    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        futureReference[i] = -1;
    }

    for (i = 0; i < sizeof(incomingStream) / sizeof(incomingStream[0]); i++) {
        int found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == incomingStream[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int minIndex = 0;
            int minValue = 999;
            for (j = 0; j < MAX_FRAMES; j++) {
                if (futureReference[j] < minValue) {
                    minIndex = j;
                    minValue = futureReference[j];
                }
            }

            frames[minIndex] = incomingStream[i];
            futureReference[minIndex] = i + 1;
            pageFaults++;
        }

        printf("Incoming: %d Frames: ", incomingStream[i]);
        for (j = 0; j < MAX_FRAMES; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", pageFaults);

    return 0;
}
