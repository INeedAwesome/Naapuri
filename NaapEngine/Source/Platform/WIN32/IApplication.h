#pragma once
#include "NaapEngine.h"

#define ENTRYAPP(x) Win32::IApplication* entryApplication() { return new x; }

namespace Win32 {

	class NAAP_API IApplication
	{
	public:
		IApplication();
		virtual ~IApplication() {};

		virtual void SetupPerGameSettings() = 0;
		virtual void PreInitialize() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;

	private:
	};

	IApplication* entryApplication();
}