#include "NaapEngine.h"

#include "IApplication.h"

extern IApplication* entryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, PSTR, int)
{
	
	auto entryApp = entryApplication();

	PerGameSettings gameSettings;
	entryApp->setupPerGameSettings();

	Logger logger;
	entryApp->initialize();

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
			entryApp->update();
			

		}
	}
	

	return 0;
}