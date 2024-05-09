#include <stdio.h>

int main() {
    // Process names: P0, P1, P2, P3, P4
    int n = 5; // Number of processes
    int m = 4; // Number of resources

    // Allocation Matrix
    int alloc[5][4] = {
        {1, 2, 1, 1}, // P0
        {2, 0, 1, 0}, // P1
        {1, 0, 3, 1}, // P2
        {1, 1, 0, 0}, // P3
        {0, 1, 0, 1}  // P4
    };

    // MAX Matrix
    int max[5][4] = {
        {3, 3, 2, 2}, // P0
        {3, 2, 2, 2}, // P1
        {3, 1, 5, 2}, // P2
        {2, 2, 0, 2}, // P3
        {1, 3, 2, 2}  // P4
    };

    // Available Resources
    int avail[4] = {1, 2, 2, 1};

    int f[n], ans[n], ind = 0;

    for (int k = 0; k < n; k++) {
        f[k] = 0;
    }

    int need[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }

    return 0;
}

