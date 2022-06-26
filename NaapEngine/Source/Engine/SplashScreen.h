#pragma once

#include "Platform/Win32/Window.h"

namespace SplashScreen {

	void NAAP_API Open();
	void NAAP_API Close();
	void NAAP_API AddMessage(const WCHAR* message);

}

class NAAP_API SplashWindow : public Win32::Window
{
public:
	SplashWindow();
	~SplashWindow();

	virtual LRESULT MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;


private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};
