#include "NaapEngine.h"
#include <fstream>
#include <Shlobj.h>
#include <cstdio>
#include <tlhelp32.h>

Logger* Logger::instance;

Logger::Logger()
{
	instance = this;
}

Logger::~Logger()
{
}

void Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);
	std::wstring string = buf;
	string.append(L"\n");
	OutputDebugString(string.c_str());
	//														  yymmddHHMMss
	// example file & location = %appdata%/Naapuri/Log/Naapuri250622230750/

	std::wfstream outfile;
	//			 File url        mode to open
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios::app);

	if (outfile.is_open())
	{
		std::wstring s = buf;
		outfile << L"[" << Time::GetDateTimeString() << L"] " << s << L"\r\n";
		outfile.close();
	}
	else
	{
		MessageBox(0, L"Unable to open log file...", L"Log Error", MB_OK | MB_ICONWARNING);
	}

	
}

std::wstring Logger::LogDirectory()
{
	WCHAR path[1024];
	WCHAR* appdataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &appdataLocal);
	wcscpy_s(path, appdataLocal);
	wcscat_s(path, L"\\");
	wcscat_s(path, PerGameSettings::GetGameName());
	CreateDirectory(path, NULL);
	wcscat_s(path, L"\\Log");
	CreateDirectory(path, NULL);
	return path;

}

std::wstring Logger::LogFile()
{
	WCHAR file[1024];
	wcscpy_s(file, PerGameSettings::GetGameName());
	wcscat_s(file, PerGameSettings::GetBootTime());
	wcscat_s(file, L".log");
	return file;
}

void Logger::PrintDebugSeperator()
{
	std::wstring s = L"\n------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		outfile.close();
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

/* Private class to check to see if MTail is already running - So we don't open multiple copies during debug */
bool Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!_wcsicmp(entry.szExeFile, L"mTAIL.exe"))
				exists = true;

	CloseHandle(snapshot);
	return exists;
}

/* Start MTail from Project or Build Directory - Depends on where ran from */
void Logger::StartMTail()
{
	if (IsMTailRunning()) {
		Logger::PrintLog(L"--MTail failed to start - Already Running\n");
		return;
	}

	Logger::PrintLog(L"--Starting MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTAIL.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}