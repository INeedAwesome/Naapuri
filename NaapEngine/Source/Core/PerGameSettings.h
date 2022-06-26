#include "NaapEngine.h"

class NAAP_API PerGameSettings
{
public:
	PerGameSettings();
	~PerGameSettings();

	static WCHAR* GetGameName() { return instance->gameName; }
	static void SetGameName(UINT id) { LoadString(HInstance(), id, instance->gameName, MAX_NAME_STRING); }

	static WCHAR* GetShortName() { return instance->shortName; }
	static void SetShortName(UINT id) { LoadString(HInstance(), id, instance->shortName, MAX_NAME_STRING); }
	
	static HICON GetMainIcon() { return instance->mainIcon; }
	static void SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* GetBootTime() { return instance->bootTime; }

	static WCHAR* GetSplashURL() { return instance->m_SplashURL; }
	static void SetSplashURL(UINT id) { LoadString(HInstance(), id, instance->m_SplashURL, MAX_NAME_STRING); }


private:
	static PerGameSettings* instance;
	static PerGameSettings* GetInstance() { return instance; }

	WCHAR gameName[MAX_NAME_STRING];
	WCHAR shortName[MAX_NAME_STRING];
	HICON mainIcon;
	WCHAR bootTime[MAX_NAME_STRING];
	WCHAR m_SplashURL[MAX_NAME_STRING];
	

};
