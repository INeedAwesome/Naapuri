#pragma once

class NAAP_API OEngine;

namespace Engine {

	enum EngineMode : int
	{
		NONE, DEBUG, RELEASE, EDITOR, SERVER
	};

	extern OEngine naapEngine;


	void NAAP_API SetMode(EngineMode mode);
	std::wstring NAAP_API EngineModeToString();
	EngineMode NAAP_API GetMode();
}

class NAAP_API OEngine
{
public:
	OEngine();
	~OEngine();

	Engine::EngineMode GetEngineMode();
	void SetEngineMode(Engine::EngineMode mode);

private:

	Engine::EngineMode engineMode;

};