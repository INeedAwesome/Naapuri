#pragma once

#include "Platform/Win32/IApplication.h"

namespace NaapEngine {

	class NAAP_API Simulation : public Win32::IApplication
	{
	public:
		Simulation();
		~Simulation();

		virtual void PreInitialize() override;

	private:

	};

}