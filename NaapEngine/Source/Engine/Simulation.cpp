#include "NaapEngine.h"
#include "Simulation.h"
#include "Engine/SplashScreen.h"

NaapEngine::Simulation::Simulation()
{
}

NaapEngine::Simulation::~Simulation()
{
}

void NaapEngine::Simulation::PreInitialize()
{
	Logger::PrintLog(L"Starting Application...");
	Logger::PrintLog(L"Name: %s", PerGameSettings::GetGameName());
	Logger::PrintLog(L"Boot time: %s", Time::GetDateTimeString().c_str());
	Logger::PrintLog(L"Engine mode: %s", Engine::EngineModeToString().c_str());
	Logger::PrintLog(L"Done! ");
	Logger::PrintDebugSeperator();

	SplashScreen::Open();
}
