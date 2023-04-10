#include <stdio.h>
#include <windows.h>

int main()
{
    // Creating a job with default security attributes
    HANDLE hJob = CreateJobObject(NULL, "Unemployed");
    // Setting the job to terminate when all processes in it terminate
    JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = {0};
    jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
    SetInformationJobObject(hJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli));
    // Creating structures for notepad, cmd and powershell
    STARTUPINFOA si = {0};
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi = {0};
    STARTUPINFOA si1 = {0};
    si1.cb = sizeof(si1);
    PROCESS_INFORMATION pi1 = {0};

    // Creating notepad, and Windows media player in suspended state and adding them to the job and checking for errors
    if (!CreateProcessA(NULL, (LPSTR)"notepad.exe", NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi) || !CreateProcessA(NULL, (LPSTR)"dvdplay.exe", NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si1, &pi1))
    {
        printf("Error creating processes\n");
        printf("Error code: %d\n", GetLastError());
        return 1;
    }
    
    AssignProcessToJobObject(hJob, pi.hProcess);
    AssignProcessToJobObject(hJob, pi1.hProcess);

    // Resuming processes
    ResumeThread(pi.hThread);
    ResumeThread(pi1.hThread);
    printf("Job created and processes added!\n");
    
    // SLeeping for 2 minutes to let the processes run
    Sleep(60000);
    // Terminating the job
    TerminateJobObject(hJob, 0);
    // Closing handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hJob);

    // Return success
    printf("Exiting...\n");
    return 0;
}