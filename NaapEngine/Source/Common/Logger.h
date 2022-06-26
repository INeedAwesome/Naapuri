#pragma once
#include "NaapEngine.h"
#include <string>

class NAAP_API Logger
{
public:
	Logger();
	~Logger();

	static void PrintLog(const WCHAR* fmt, ...);

	static std::wstring LogDirectory();

	static std::wstring LogFile();

	static Logger* GetInstance() { return instance; }

	static void PrintDebugSeperator();

	/* Check to see if MTail is already Running */
	static bool IsMTailRunning();

	/* Start MTail Application */
	static void StartMTail();


private:
	static Logger* instance;

};