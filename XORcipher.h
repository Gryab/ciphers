#pragma once
#include <vector>

const char lastPosOfBit = 15;
const unsigned short gex0 = 1024U;
const unsigned short gexBase = 256U;

std::vector<bool> toBits(wchar_t ch) {
	std::vector<bool> res{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char i = -1; ++i < lastPosOfBit + 1; ch >>= 1)res[lastPosOfBit - i] = ch % 2;
	return res;
}

std::vector<bool> XORbin(std::vector<bool> bin1, std::vector<bool> bin2) {
	for (char i = -1; ++i < 16;) bin1[i] = bin1[i] ^ bin2[i];
	return bin1;
}

wchar_t fromBits(std::vector<bool> bin) {
	wchar_t res = bin[lastPosOfBit];
	for (char i = -1; ++i < lastPosOfBit;) res += bin[i] << (lastPosOfBit - i);
	return res;
}

class GEX
{
private:

	wchar_t Gvalue[3]{gex0, gex0};

public:

	GEX(wchar_t ch) {
		Gvalue[0] += ch % gexBase, Gvalue[1] += ch / gexBase;
	}

	GEX(std::wstring Fvalue) {
		Gvalue[0] = Fvalue[0], Gvalue[1] = Fvalue[1];
	}

	GEX(std::vector<bool> bin) {
		wchar_t ch = (wchar_t)GEX(fromBits(bin));
		Gvalue[0] += ch % gexBase, Gvalue[1] += ch / gexBase;
	}

	operator std::wstring() {
		return Gvalue;
	}

	operator wchar_t() {
		return (Gvalue[1] - gex0) * gexBase + Gvalue[0] - gex0;
	}

	GEX operator^ (GEX another) {
		return GEX(fromBits(XORbin(toBits(*this), toBits(another))));
	}

	GEX operator^= (GEX another) {
		*this = *this ^ another;
		return *this;
	}
};

class cwstring
{
public:
	cwstring(std::wstring strT = L"") { str = strT; };

	wchar_t at(unsigned long long i) { return str[i%str.length()]; }

	size_t size() { return str.size(); }
	size_t length() { return str.length(); }
	
	std::wstring substr(size_t pos, size_t len) { return str.substr(pos, len); }

	std::wstring::iterator begin() { return str.begin(); }
	std::wstring::iterator end() { return str.end(); }

	cwstring clear() { 
		str.clear();
		return *this; 
	}
	cwstring erase(size_t pos = 0, size_t len = 0) {
		str.erase(pos, len);
		return *this;
	}

	operator std::wstring() { return str; }

	cwstring operator= (std::wstring another) {
		str = another;
		return *this;
	}

	cwstring operator= (wchar_t another) {
		clear();
		str[0] = another;
		return *this;
	}

	cwstring operator= (cwstring another) {
		str = (std::wstring)another;
		return *this;
	}

	cwstring operator+ (std::wstring another) { return cwstring(str + another); }

	cwstring operator+ (wchar_t another) { return cwstring(str + another); }

	cwstring operator+ (cwstring another) { return cwstring(str + another.str); }

	cwstring operator+= (std::wstring another) {
		str += another;
		return *this;
	}
	
	cwstring operator+= (wchar_t another) {
		str += another;
		return *this;
	}

	cwstring operator+= (cwstring another) {
		str += another.str;
		return *this;
	}
private:
	std::wstring str;
};

std::vector<GEX> XORstrToGexAsVec(cwstring phrase, cwstring key = cwstring(L"key")) {
	std::vector<GEX> gex;
	unsigned long long i = -1;
	while (phrase.size() > ++i) gex.push_back(GEX(phrase.at(i)) ^ GEX(key.at(i)));
	return gex;
}

std::wstring XORstrToGexAsStr(cwstring phrase, cwstring key = cwstring(L"key")) {
	cwstring gex;
	unsigned long long i = -1;
	while (phrase.size() > ++i) gex += (std::wstring)(GEX(phrase.at(i)) ^ GEX(key.at(i)));
	return gex;
}

std::wstring XORgexToStr(cwstring phrase, cwstring key = cwstring(L"key")) {
	cwstring str;
	unsigned long long i = -1;
	while ((phrase.size() >> 1) > ++i) str += (wchar_t)GEX(phrase.substr(i << 1, 2)) ^ GEX(key.at(i));
	return (std::wstring)str;
}

std::wstring XORgexToStr(std::vector<GEX> vec, cwstring key = cwstring(L"key")) {
	cwstring str;
	unsigned long long i = -1;
	while (vec.size() > ++i) str += (wchar_t)(vec.at(i) ^ GEX(key.at(i)));
	return (std::wstring)str;
}