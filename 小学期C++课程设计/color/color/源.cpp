#include <windows.h> 
#include <winnt.h> 
#include <stdio.h> 

int main()
{
	HANDLE consolehwnd;
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0;
	SetConsoleTextAttribute(consolehwnd, i);
	printf("i am dadalili!\n");
	for (i = 1; i<255;i++ )
	{
		SetConsoleTextAttribute(consolehwnd, i);
		printf("i am dadalili!");
	}
	SetConsoleTextAttribute(consolehwnd, 255);
	system("pause");
	return 0;
}