#include "Naapuri.h"

#include "NaapEngine.h"
#include "Engine/Simulation.h"
#include "Platform/Win32/WinEntry.h"

class Naapuri : public NaapEngine::Simulation
{
public:
	Naapuri();
	~Naapuri();

private:
	void SetupPerGameSettings();
	virtual void Initialize();
	void Update();

};

ENTRYAPP(Naapuri)

Naapuri::Naapuri()
{
}

Naapuri::~Naapuri()
{
}

void Naapuri::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PER_GAME_NAME);
	PerGameSettings::SetShortName(IDS_SHORT_NAME);
	PerGameSettings::SetMainIcon(IDI_MAIN_ICON);
	PerGameSettings::SetSplashURL(IDS_SPLASH_URL);
}

void Naapuri::Initialize()
{
}

void Naapuri::Update()
{
}
