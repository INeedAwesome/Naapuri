#include <Windows.h>

#define MAX_NAME_STRING 256

#define HInstance() GetModuleHandle(NULL)

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

int WindowWidth;
int WindowHeight;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, PSTR, int) 
{ 
	/*  Initialize global variables  */
	wcscpy_s(WindowClass, TEXT("Naapuri"));
	wcscpy_s(WindowTitle, TEXT("Naapuri"));
	WindowWidth = 1366;
	WindowHeight = 768;

	/*  Create a window class  */

	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX); // initializes the windowClass
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;

	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	windowClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	windowClass.hIconSm = LoadIcon(0, IDI_APPLICATION);

	windowClass.lpszClassName = WindowClass; // unique window class name
	windowClass.lpszMenuName = nullptr; // menu at the top

	windowClass.hInstance = HInstance();
	windowClass.lpfnWndProc = DefWindowProc;

	RegisterClassEx(&windowClass);

	/*  Create and Display our window  */
	 
	HWND windowHandle = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!windowHandle)
	{
		MessageBox(0, L"Failed to create window!", 0, 0);
		return 1;
	}

	ShowWindow(windowHandle, SW_SHOW);

	/*  Listen for Message events  */

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}