#include "NaapEngine.h"

#include "IApplication.h"
#include "Common/CmdLineArgs.h"


extern Win32::IApplication* entryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
	
	auto entryApp = entryApplication();

	PerGameSettings gameSettings;
	entryApp->SetupPerGameSettings();

	Logger logger;
	entryApp->PreInitialize();
	CmdLineArgs::ReadArguments();   

	//SplashScreen::AddMessage(L"Starting application...");

	entryApp->Initialize();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			entryApp->Update();
			

		}
	}
	

	return 0;
}