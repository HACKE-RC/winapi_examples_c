#include <iostream>
#include <windows.h>
#include <Shlwapi.h>
using namespace std;

int main(int argc, char const *argv[])
{
    char NPath[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, NPath);
    PathStripToRoot((LPWSTR)NPath);
    cout << NPath << endl; 
    return 0;
}
