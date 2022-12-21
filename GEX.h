#pragma once
#include <string>
#include <bitset>

class GEX
{
private:
	const wchar_t gex0 = 1024U;
	const uint16_t gexBase = 256U;
	wchar_t Gvalue[3]{ gex0, gex0 };
public:
	GEX(wchar_t ch);
	GEX(std::wstring Fvalue);

	operator std::wstring();
	operator wchar_t();

	GEX operator= (GEX another);
	GEX operator^ (GEX another);
	GEX operator^= (GEX another);
};