/*
	Author: INeedAwesome
	Licence: MIT
	Date: 2022.06.24
*/

#include "pch.h"

#pragma region GlobalVariables 

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

int WindowWidth;
int WindowHeight;

HICON hIcon;
#pragma endregion

#pragma region PreDeclerations

void initializeVariables();
LRESULT WindowsProcess(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
void createWindowsClass();
bool initializeWindow();
void windowMessageLoop();

#pragma endregion

int CALLBACK WinMain(HINSTANCE, HINSTANCE, PSTR, int) 
{ 
	initializeVariables();
	createWindowsClass();

	if (!initializeWindow())
		return 1;

	windowMessageLoop();
	
	return 0;
}

void windowMessageLoop() 
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}  
	}
}

bool initializeWindow() 
{
	HWND windowHandle = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!windowHandle)
	{
		MessageBox(0, L"Failed to create window!", 0, 0);
		return false;
	}

	ShowWindow(windowHandle, SW_SHOW);
	return true;
}

void createWindowsClass() 
{ 
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX); // initializes the windowClass
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;

	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	windowClass.hIcon = hIcon;
	windowClass.hIconSm = hIcon;

	windowClass.lpszClassName = WindowClass; // unique window class name
	windowClass.lpszMenuName = nullptr; // menu at the top

	windowClass.hInstance = HInstance();
	windowClass.lpfnWndProc = WindowsProcess;

	RegisterClassEx(&windowClass);
}

LRESULT CALLBACK WindowsProcess(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		break;
	}

	return DefWindowProc(hwnd, message, wparam, lparam);
}

void initializeVariables()
{
	LoadString(HInstance(), IDS_PER_GAME_NAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOW_CLASS, WindowClass, MAX_NAME_STRING);

	wcscpy_s(WindowClass, TEXT("Naapuri"));
	wcscpy_s(WindowTitle, TEXT("Naapuri"));
	WindowWidth = 1366;
	WindowHeight = 768;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAIN_ICON));
}