#include <stdio.h>
#include <memoryapi.h>

int main(){
    int *pointer_to_memory = VirtualAlloc(NULL, 8, MEM_COMMIT, PAGE_READWRITE);
    printf("The base address of allocated memory is: 0x%d\n", pointer_to_memory);
    memmove(pointer_to_memory, (const void*)"1337", 4);
    printf("The data which is stored in the memory is %s", pointer_to_memory);
    VirtualFree(pointer_to_memory, 8, MEM_DECOMMIT);
}