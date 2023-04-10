#include <stdio.h>
#include <windows.h>

// Function to create a thread
int EthicalFunction(LPVOID lpParam)
{
    // Print a message
    printf("Thread created\n");
    printf("For educational purposes only*\n");
    // Return success
    return 0;
}

int main()
{
    // Create a thread
    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)EthicalFunction, NULL, 0, NULL);
    // Wait for thread to finish
    WaitForSingleObject(hThread, INFINITE);
    printf("Thread returned\n");
    printf("Exiting...\n");
    // Close thread handle
    CloseHandle(hThread);
    // Return success
    return 0;
}