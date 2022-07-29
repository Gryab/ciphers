#pragma once
#include <vector>
#include <string>
#include <bitset>

class GEX
{
private:
	const uint16_t gex0 = 1024U;
	const uint16_t gexBase = 256U;
	wchar_t Gvalue[3]{gex0, gex0};
public:
	GEX(wchar_t ch) { Gvalue[0] += ch % gexBase, Gvalue[1] += ch / gexBase; }
	GEX(std::wstring Fvalue) { Gvalue[0] = Fvalue[0], Gvalue[1] = Fvalue[1]; }

	operator std::wstring() { return Gvalue; }
	operator wchar_t() { return (Gvalue[1] - gex0) * gexBase + Gvalue[0] - gex0; }

	GEX operator= (GEX another);
	GEX operator^ (GEX another) { return GEX((std::bitset<16>( *this) ^ std::bitset<16>(another)).to_ulong()); }
	GEX operator^= (GEX another);
};

class cwstring : public std::wstring
{
public:
	cwstring(std::wstring strT = L"") : std::wstring(strT) {};
	cwstring(wchar_t wchar) : std::wstring(&wchar) {};
	cwstring(std::vector<GEX> vec) { for (uint64_t i = -1; ++i < vec.size();) __super::append(vec.at(i)); };

	wchar_t at(uint64_t k) { return __super::at(k % __super::length()); }
};

class XOR
{
public:
	XOR(std::wstring key = L"key") { myKey = key; }
	XOR changeIdentifier(std::wstring identifier) { gexIdentifier = identifier; }

	std::wstring cipher(std::wstring phrase) { return isGex(phrase) ? XORgexToStr(removeIdentifier(phrase)) : XORstrToGexAsStr(phrase); }
	
	std::vector<GEX> XORstrToGexAsVec(cwstring phrase);
private:
	std::wstring gexIdentifier = L"gexInput";
	cwstring myKey;

	std::wstring getIdentifier(std::wstring phrase) { return phrase.substr(0, gexIdentifier.length()); };
	std::wstring removeIdentifier(std::wstring phrase) { return phrase.substr(gexIdentifier.length()); };

	bool isGex(std::wstring phrase) { return getIdentifier(phrase) == gexIdentifier; }

	std::wstring XORstrToGexAsStr(cwstring phrase);
	std::wstring XORgexToStr(cwstring phrase);
};