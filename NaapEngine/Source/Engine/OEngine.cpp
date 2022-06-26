#include "NaapEngine.h"

namespace Engine {

	OEngine naapEngine;

	void Engine::SetMode(EngineMode mode)
	{
		naapEngine.SetEngineMode(mode);
	}

	EngineMode Engine::GetMode()
	{
		return naapEngine.GetEngineMode();
	}

	std::wstring Engine::EngineModeToString()
	{
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG: return L"Debug";
		case EngineMode::RELEASE: return L"Release";
		case EngineMode::SERVER: return L"Server";
		case EngineMode::EDITOR: return L"Editor";
		default:
			return L"None";
		}
	return L"None";
	}

}

OEngine::OEngine()
{
#ifdef _DEBUG
	engineMode = Engine::EngineMode::DEBUG;
#else
	engineMode = Engine::EngineMode::RELEASE;
#endif
}

OEngine::~OEngine()
{
}

Engine::EngineMode OEngine::GetEngineMode()
{
	return engineMode;
}

void OEngine::SetEngineMode(Engine::EngineMode mode)
{
	engineMode = mode;
}
