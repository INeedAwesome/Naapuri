#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
}

Application::~Application()
{
}

void Application::setupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PER_GAME_NAME);
	PerGameSettings::SetShortName(IDS_SHORT_NAME);
	PerGameSettings::SetMainIcon(IDI_MAIN_ICON);
	
}

void Application::initialize()
{
	Logger::StartMTail();
	Logger::PrintLog(L"Starting Application...");
	Logger::PrintLog(L"Name: %s", PerGameSettings::GetGameName());
	Logger::PrintLog(L"Boot time: %s", Time::GetDateTimeString().c_str());
	Logger::PrintLog(L"Done! ");
	Logger::PrintDebugSeperator();
	
}

void Application::update()
{
	//Logger::PrintLog(L"loop");
}
