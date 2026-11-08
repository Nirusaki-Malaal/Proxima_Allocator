// Pool Allocator public interface
#ifndef POOL_H
#define POOL_H

#include <stddef.h>

// Create the pool memory using mmap only
// returns MAP_FAILED on error
unsigned char *pool_create(size_t heap_size);

// Release the pool memory, returns 0 on success
int pool_destroy(unsigned char *ptr, size_t heap_size);

// Grab chunks_needed chunks out of the pool
// returns NULL when no free chunks are left
unsigned char *allocate(unsigned char *ptr, size_t chunks_needed, size_t no_chunk, size_t chunk_size);

// Give free_chunk chunks back to the pool
// returns 0 on success, 1 on invalid input
int free_alloc(int free_chunk, size_t no_chunk);

// Reset the pool back to empty
void reset(void);

// Print the pool statistics
void stats(size_t size_chunk, size_t no_chunk);

#endif // POOL_H
