#pragma once
#include <vector>
#include "GEX.h"

class cwstring : public std::wstring
{
public:
	cwstring(std::wstring strT = L"") : std::wstring(strT) {};
	cwstring(wchar_t wchar) : std::wstring(&wchar) {};
	cwstring(std::vector<GEX> vec);

	operator uint64_t();

	wchar_t at(uint64_t k);
};