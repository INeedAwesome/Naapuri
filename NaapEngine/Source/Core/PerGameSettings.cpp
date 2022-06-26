#include "NaapEngine.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;

	wcscpy_s(this->gameName, L"undefined");
	wcscpy_s(this->shortName, L"undefined");
	wcscpy_s(this->bootTime, Time::GetDateTimeString(true).c_str());
	wcscpy_s(this->m_SplashURL, L"..\\NaapEngine\\Assets\\Images\\OlympusSplash.bmp");
}

PerGameSettings::~PerGameSettings()
{
}
