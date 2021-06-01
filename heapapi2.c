#include <stdio.h>
#include <Windows.h>
#include <string.h>

int main() {
    int heap_size;
    char data_to_store[2000];
    char choice[20];
    int* current_heap = GetProcessHeap(); // Getting the Handle of default Heap.

    printf("How much heap do you want to allocate? (int bytes): ");
    scanf("%d", &heap_size);

    int* heap = HeapAlloc(current_heap, HEAP_ZERO_MEMORY, heap_size); // Allocating heap of the user supplied size. Filled with zero by default.
    printf("The handle of heap of this program is %x\n", current_heap);

    printf("Enter the data you want to store in the heap: ");
    scanf("%s", &data_to_store);
    memmove(heap, (const void*)data_to_store, strlen(data_to_store)); // Moving the user supplied data into the allocated heap.
    
    printf("The data stored in heap is: %s\n", heap);

    int freed = HeapFree(current_heap, 0, heap); // Free()'ing the heap.

    if (freed) {
        printf("The memory has been freed successfully!\n");
    } else {
        printf("Was not able to free heap!!");
        exit(1);
    }
    
    return 0;
}