#include "UI.h"

void UI::print(string s)
{
	for (int i = 0; i < s.length(); i++) {
		Sleep(10);
		cout << s[i];
	}
}

void UI::setColor(int forgC)
{
	// Function to set the foreground color of the command line interface
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		// Mask out all but the background attribute, and add in the forgournd     color
		wColor = (csbi.wAttributes & 0xF0) + (forgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}
