#pragma once
#include <iostream>
class logger
{
public:
	static void log(std::wstring value);
	
	static void log(wchar_t value);
	
	static void log(int64_t value);
	
	static void log(long double value);

	void log(std::wstring arr[], std::wstring sep);
};