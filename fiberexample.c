#include <stdio.h>
#include <windows.h>

// fiber function
void fiber_function(void* lpParam)
{
    // Print a message
    printf("Fiber created\n");
    printf("For educational purposes only*\n");
    // Converting back into the main thread as fiber will not return to the main thread by itself
    SwitchToFiber(lpParam);

}

// main function
int main()
{
    // Converting thread to fiber
    LPVOID Context = ConvertThreadToFiber(NULL);
    // Creating fiber
    LPVOID lpFiber = CreateFiber(0, (LPFIBER_START_ROUTINE)fiber_function, Context);
    // Switching to fiber (executing fiber function)
    SwitchToFiber(lpFiber);
    // Printing a message
    printf("Fiber returned\n");
    // Deleting fiber
    DeleteFiber(lpFiber);
    // Return success
    printf("Exiting...\n");
    return 0;
}




