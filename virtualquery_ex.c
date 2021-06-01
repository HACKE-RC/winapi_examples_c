#include <Windows.h>
#include <stdio.h>

int main()
{
	MEMORY_BASIC_INFORMATION info;
	int ret;
    const void* location;
    int *vm = VirtualAlloc(NULL, 8, MEM_COMMIT, PAGE_READONLY);
    memmove(vm, (const void*)"1337", 4);
    
    
    printf("Address of memory returned by VirtualAlloc is %lu\n", vm);
    printf("Enter the memory address that you want to query: ");
    scanf("%lu", &location);


    ret = VirtualQuery(location, &info, sizeof(info));
	if (!ret) {
		printf("VirtualQuery failed\n");
        printf("The error code for the last error was %d", GetLastError());
		return 1;
	}
    
    printf("Protection type : ");
	switch (info.AllocationProtect)
    {
    case PAGE_EXECUTE_READ:
        printf("EXECUTE + READ\n");
        break;
    case PAGE_READWRITE:
        printf("READ + WRITE\n");
        break;
    case PAGE_READONLY:
        printf("READ\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    printf("Region State : ");
    switch (info.State)
    {
    case MEM_COMMIT:
        printf("Committed");
        break;
    case MEM_FREE:
        printf("Free");
        break;
    case MEM_RESERVE:
        printf("Reserve");
        break;
    default:
        printf("Unknown");
        break;
    }

	return 0;
}