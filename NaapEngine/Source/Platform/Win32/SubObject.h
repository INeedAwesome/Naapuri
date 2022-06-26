#pragma once

namespace Win32 {

	class NAAP_API SubObject
	{
	public:
		SubObject(std::wstring Class, std::wstring Title, HICON hIcon);
		~SubObject();

		HWND GetHandle() { return m_Handle; } 

		virtual void RegisterNewClass();
		virtual void Initialize() = 0;

	protected:
		static LRESULT CALLBACK SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static LRESULT AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		virtual LRESULT CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

		virtual LRESULT MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;


		std::wstring m_Class;
		std::wstring m_Title;

		HICON m_hIcon;

		HWND m_Handle;
	};



}