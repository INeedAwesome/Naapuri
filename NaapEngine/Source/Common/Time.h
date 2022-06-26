#pragma once
#include <string>
#include "NaapEngine.h"

namespace Time { 

	std::wstring NAAP_API GetTime(bool stripped = false);

	std::wstring NAAP_API GetDate(bool stripped = false);
	
	std::wstring NAAP_API GetDateTimeString(bool stripped = false);
}