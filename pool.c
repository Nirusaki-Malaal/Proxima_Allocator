// Pool Allocator Implementation in C using mmap's only
#include "pool.h"

#include <stdio.h>
#include <sys/mman.h>

size_t used = 0; // counter maintaing the blocks used;

// Create the pool memory using mmap only
unsigned char *pool_create(size_t heap_size) {
    return mmap(NULL, heap_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
}

// Release the pool memory
int pool_destroy(unsigned char *ptr, size_t heap_size) {
    return munmap(ptr, heap_size);
}

void reset(void) {
    used = 0;
}

void stats(size_t size_chunk, size_t no_chunk) {
    printf("Total Chunks        : %zu\n", no_chunk);
    printf("Size of Each Chunk  : %zu\n", size_chunk);
    printf("Chunks Used         : %zu\n", used);
    printf("Chunks Free         : %zu\n", no_chunk - used);
}

int free_alloc(int free_chunk, size_t no_chunk) {
    if (used >= free_chunk) {
        used -= free_chunk;
        return 0;
    }
    return 1;
}

unsigned char *allocate(unsigned char *ptr, size_t chunks_needed, size_t no_chunk, size_t chunk_size) {
    if (chunks_needed > no_chunk - used) {
        return NULL;
    }
    unsigned char *new_ptr = ptr + used * chunk_size;
    used += chunks_needed;
    return new_ptr;
}
