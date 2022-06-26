#include "NaapEngine.h"
#include "SubObject.h"

namespace Win32 {

	SubObject::SubObject(std::wstring ClassName, std::wstring classTitle, HICON icon)
		: m_Class(ClassName), m_Title(classTitle), m_hIcon(icon)
	{
	}

	SubObject::~SubObject()
	{
	}
	void SubObject::RegisterNewClass()
	{
		WNDCLASSEX windowClass;
		windowClass.cbSize = sizeof(WNDCLASSEX); // initializes the windowClass
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;

		windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		windowClass.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(46, 46, 46)));
		windowClass.hIcon = m_hIcon;
		windowClass.hIconSm = m_hIcon;

		windowClass.lpszClassName = m_Class.c_str(); // unique window class name
		windowClass.lpszMenuName = nullptr; // menu at the top

		windowClass.hInstance = HInstance();
		windowClass.lpfnWndProc = SetupMessageHandler;

		RegisterClassEx(&windowClass);
	}

	LRESULT SubObject::SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Win32::SubObject* const pWnd = static_cast<Win32::SubObject*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32::SubObject::AssignMessageHandler));
			return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	LRESULT SubObject::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32::SubObject* const pWnd = reinterpret_cast<Win32::SubObject*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
	}

	LRESULT SubObject::CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

}