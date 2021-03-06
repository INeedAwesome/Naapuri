#include "NaapEngine.h"
#include "SplashScreen.h"

#include "Platform/Win32/Win32Utils.h"

namespace SplashScreen {

#define WM_OUTPUT_MESSAGE (WM_USER + 0x0001)

	SplashWindow* m_SplashWindow;

	void Open()
	{
		if (m_SplashWindow != nullptr)
			return;
		m_SplashWindow = new SplashWindow(); 
	}

	void Close()
	{

	}

	void AddMessage(const WCHAR* message)
	{
		PostMessage(m_SplashWindow->GetHandle(), WM_OUTPUT_MESSAGE, (WPARAM) message, 0);
	}
}

SplashWindow::SplashWindow()
	: Win32::Window(L"SplashScreen", L"SplashScreen", NULL, 500, 600)
{
	wcscpy_s(m_outputMessage, L"SplashScreen starting...");
	Win32::Window::RegisterNewClass();
	Win32::Window::Initialize();
}

SplashWindow::~SplashWindow()
{
}

LRESULT SplashWindow::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_PAINT:
		{
			HBITMAP hbitmap;
			HDC hdc, hmemdc;
			PAINTSTRUCT ps;

			hdc = BeginPaint(hwnd, &ps);
			Win32::Utils::AddBitmap(PerGameSettings::GetSplashURL(), hdc, 0, 0);

			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(255, 255, 255));	

			if (Engine::GetMode() != Engine::EngineMode::RELEASE) {		

				std::wstring engineModeText = Engine::EngineModeToString() + L" Mode";	
				SetTextAlign(hdc, TA_RIGHT);
				TextOut(hdc, m_Width - 15, 15, engineModeText.c_str(), wcslen(engineModeText.c_str()));		
			}

			SetTextAlign(hdc, TA_CENTER);
			TextOut(hdc, m_Width / 2, m_Height - 30, m_outputMessage, wcslen(m_outputMessage));
			EndPaint(hwnd, &ps);
		}
		break;
		case WM_OUTPUT_MESSAGE:
		{
			WCHAR* msg = (WCHAR*)wParam;
			wcscpy_s(m_outputMessage, msg);
			RedrawWindow(GetHandle(), NULL, NULL, RDW_INVALIDATE);
			return 0;
		}
	}

	return CommonMessageHandler(hwnd, message, wParam, lParam);
}

