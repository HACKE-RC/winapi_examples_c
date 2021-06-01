#include <stdio.h>
#include <Windows.h>

int main() {
    int* heap_handle = HeapCreate(0, 0, 16);

    if (heap_handle == NULL) {
        printf("Was not able to create heap!!\nError code: %d\n", GetLastError());
        exit(GetLastError());
    }

    printf("The handle of heap created is %x\n", heap_handle);
    int* heap = HeapAlloc(heap_handle, HEAP_ZERO_MEMORY, 8);
    printf("The base address of heap allocated is %x\n", heap_handle);

    memmove(heap, (const void*)"Hello heap!", 11);
    printf("The data stored in heap is: %s\n", heap);

    int freed = HeapFree(heap_handle, 0, heap);

    if (freed) {
        printf("The memory has been freed successfully!\n");
    } else {
        printf("Was not able to free heap!!");
        exit(1);
    }

    return 0;
}