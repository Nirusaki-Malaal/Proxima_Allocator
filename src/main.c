// Proxima Allocator menu front end
#include "pool.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define MENU "====================================\n         PROXIMA ALLOCATOR\n        Pool Allocator v1.0\n====================================\n\n  1. Allocate Chunk\n  2. Free Chunk\n  3. View Stats\n  4. Reset Pool\n  5. Exit\n\n====================================\n  Select an option: "

int main(void) {
    printf("What Size of chunks you want and also how many chunks you want ?\n");
    size_t size_chunk, no_chunk;
    scanf("%zu %zu", &size_chunk, &no_chunk); // initalizing the size of chunks and no. of chunks

    // free list doesn't matter
    const size_t heap_size = size_chunk * no_chunk;

    printf("%s", MENU);
    unsigned char *ptr = pool_create(heap_size);

    if (ptr == MAP_FAILED) {
        printf("Unable to create mmap ");
        return -1;
    }

    while (1) {
        size_t choice;
        int print = scanf("%zu", &choice);
        if (print == EOF) {
            goto exit_menu;
        } else if (print != 1) {
            int ch; // if the choice is invalid
            while ((ch = getchar()) != '\n' && ch != EOF) {
                // flushses the input buffer
            }
            printf("[ERROR] Invalid Unsupported Input\n");
            continue;
        }
        printf("%zu\n", choice);
        switch (choice) {
            case 1:
                printf("How Many Chunks You Want Size of each chunk is %zu (In bytes)\n", size_chunk);
                size_t chunks;
                int result = scanf("%zu", &chunks);
                if (result == EOF) {
                    goto exit_menu;
                }
                if (result != 1) {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {
                        // flushes the input buffer
                    }
                    printf("[ERROR] Invalid Unsupported Input\n");
                    break;
                }

                unsigned char *allocated_ptr = allocate(ptr, chunks, no_chunk, size_chunk);
                allocated_ptr != NULL ? printf("\n[*] Allocated Successfully\n%p\n", (void *)allocated_ptr) : printf("[ERROR] No Free Chunks Left\n");
                break;
            case 2:
                size_t free_chunk;
                scanf("%zu", &free_chunk);
                free_alloc(free_chunk, no_chunk) != 0 ? printf("Invalid Input\n") : printf("Freed Succesfully");
                break;
            case 3:
                stats(size_chunk, no_chunk);
                break;
            case 4:
                reset();
                printf("\nReset Successful\n");
                break;
            case 5:
                printf("\n");
                goto exit_menu;
            default:
                printf("\nInvalid Input Try Again\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {
                    // flushses the input buffer
                }
                break;
        }
        printf("%s", MENU);
    }

exit_menu: // better code
    if (pool_destroy(ptr, heap_size) != 0) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
