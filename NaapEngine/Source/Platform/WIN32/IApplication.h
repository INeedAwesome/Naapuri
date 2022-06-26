#pragma once
#include "NaapEngine.h"

#define ENTRYAPP(x) IApplication* entryApplication() { return new x; }

class NAAP_API IApplication
{
public:
	IApplication();
	virtual ~IApplication() {};

	virtual void setupPerGameSettings() = 0;
	virtual void initialize() = 0;
	virtual void update() = 0;

private:
};

IApplication* entryApplication();