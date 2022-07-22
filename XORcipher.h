#pragma once
#include <vector>

const char lastPosOfBit = 15;
const unsigned short gex0 = 1024U;
const unsigned short gexBase = 256U;
const std::wstring gexStringIdentifier = L"gexInput";

std::vector<bool> toBits(wchar_t ch) {
	std::vector<bool> res{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char i = -1; ++i < lastPosOfBit + 1; ch >>= 1)res[lastPosOfBit - i] = ch % 2;
	return res;
}

std::vector<bool> XORbin(std::vector<bool> bin1, std::vector<bool> bin2) {
	for (char i = -1; ++i < lastPosOfBit + 1;) bin1[i] = bin1[i] ^ bin2[i];
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

class cwstring : public std::wstring
{
public:
	cwstring(std::wstring strT = L"") : std::wstring(strT) {};
	cwstring(wchar_t wchar) : std::wstring(&wchar) {};
	cwstring(std::vector<GEX> vec) { for (unsigned long long i = -1; ++i < vec.size();) __super::append(vec.at(i)); };

	wchar_t at(unsigned long long k) { return __super::at(k % __super::length()); }
};

std::vector<GEX> XORstrToGexAsVec(cwstring phrase, cwstring key = cwstring(L"key")) {
	std::vector<GEX> gex;
	unsigned long long i = -1;
	while (++i < phrase.size()) gex.push_back(GEX(phrase.at(i)) ^ GEX(key.at(i)));
	return gex;
}

std::wstring XORstrToGexAsStr(cwstring phrase, cwstring key = cwstring(L"key")) {
	cwstring gex(gexStringIdentifier);
	unsigned long long i = -1;
	std::vector<GEX> vec = XORstrToGexAsVec(phrase, key);
	while (++i < phrase.size()) gex += (std::wstring)vec.at(i);
	return (std::wstring)gex;
}

std::wstring XORgexToStr(cwstring phrase, cwstring key = cwstring(L"key")) {
	cwstring str;
	unsigned long long i = -1;
	while (++i < (phrase.size() >> 1)) str += (wchar_t)GEX(phrase.substr(i << 1, 2)) ^ GEX(key.at(i));
	return (std::wstring)str;
}

std::wstring XOR(std::wstring phrase, std::wstring key = L"key") {
	std::wstring identifier = phrase.substr(0, gexStringIdentifier.length());
	return identifier == gexStringIdentifier ? XORgexToStr(phrase.substr(gexStringIdentifier.length()), key) : XORstrToGexAsStr(phrase, key);
}