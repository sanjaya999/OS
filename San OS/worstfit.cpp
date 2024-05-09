#include <stdio.h>

struct memory_block {
    int size;
    bool is_free;
};

void worst_fit_memory_allocation(struct memory_block *memory_blocks, int num_blocks, int process_size) {
    // Find the largest free block suitable for the process
    int worst_fit_index = -1;
    int worst_fit_size = 0; 

    for (int i = 0; i < num_blocks; i++) {
        if (memory_blocks[i].is_free && 
            memory_blocks[i].size >= process_size && 
            memory_blocks[i].size > worst_fit_size) {

            worst_fit_index = i;
            worst_fit_size = memory_blocks[i].size;
        }
    }

    // Handle allocation or insufficient memory
    if (worst_fit_index == -1) {
        printf("Not enough memory available.\n");
    } else {
        memory_blocks[worst_fit_index].is_free = false;
        printf("Process allocated to memory block %d.\n", worst_fit_index);
    }
}

int main() {
    struct memory_block memory_blocks[] = {
        {100, true},
        {500, true},
        {200, true},
        {300, true},
        {600, true}
    };
    int num_blocks = sizeof(memory_blocks) / sizeof(memory_blocks[0]);

    // Example usage: Try allocating a process of size 212
    worst_fit_memory_allocation(memory_blocks, num_blocks, 212); 

    return 0;
}

