#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
public:
	Application();
	~Application();

private:
	void setupPerGameSettings();
	void initialize();
	void update();

};