#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames[MAX_FRAMES];
    int references[MAX_FRAMES];
    int i, j;

    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        references[i] = -1;
    }

    for (i = 0; i < sizeof(incomingStream) / sizeof(incomingStream[0]); i++) {
        int found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == incomingStream[i]) {
                found = 1;
                references[j] = i;
                break;
            }
        }

        if (!found) {
            int minIndex = 0;
            int minValue = 999999;
            for (j = 0; j < MAX_FRAMES; j++) {
                if (references[j] < minValue) {
                    minIndex = j;
                    minValue = references[j];
                }
            }

            frames[minIndex] = incomingStream[i];
            references[minIndex] = i;
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
