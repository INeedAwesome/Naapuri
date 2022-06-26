#include "NaapEngine.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;

	wcscpy_s(this->gameName, L"undefined");
	wcscpy_s(this->shortName, L"undefined");
	wcscpy_s(this->bootTime, Time::GetDateTimeString(true).c_str());
}

PerGameSettings::~PerGameSettings()
{
}
