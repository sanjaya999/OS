#include <stdio.h>

struct memory_block {
    int size;
    int is_free;
};

void first_fit_memory_allocation(struct memory_block *memory_blocks, int num_blocks, int process_size) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (memory_blocks[i].is_free && memory_blocks[i].size >= process_size) {
            memory_blocks[i].is_free = false;
            break;
        }
    }

    if (i == num_blocks) {
        printf("Not enough memory available.\n");
    } else {
        printf("Process allocated to memory block %d.\n", i + 1); // Changed from i to i + 1
    }
}

int main() {
    struct memory_block memory_blocks[] = {
        {100, true},
        {300, true}, // Changed size from 200 to 300
        {200, true},
        {400, true},
        {500, true},
    };

    first_fit_memory_allocation(memory_blocks, sizeof(memory_blocks) / sizeof(memory_blocks[0]), 250);

    return 0;
}
