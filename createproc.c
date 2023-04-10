#include <stdio.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
	LPCSTR procname = "cmd.exe";
	LPSTR commandline = NULL;

	STARTUPINFOA si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	CreateProcessA(NULL,"cmd.exe",NULL,NULL,0,0,NULL,NULL,&si,&pi);
	return 0;
}