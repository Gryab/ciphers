#pragma once
#include <vector>

std::vector<bool> toBits(wchar_t ch) {
	std::vector<bool> res{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char i = -1; ++i < 16; ch /= 2)res[15 - i] = ch % 2;
	return res;
}

std::vector<bool> XORbin(std::vector<bool> bin1, std::vector<bool> bin2) {
	for (char i = -1; ++i < 16;) bin1[i] = bin1[i] ^ bin2[i];
	return bin1;
}

wchar_t fromBits(std::vector<bool> bin) {
	wchar_t res = bin[15];
	for (char i = -1; ++i < 15;) res += bin[i] << (15 - i);
	return res;
}

wchar_t fromGex(std::wstring str) {
	return (str[1] - L'Ѐ') * 256 + str[0] - L'Ѐ';
}

class GEX
{
private:
	std::wstring value = L"ЀЀ";
public:
	GEX(wchar_t ch) {
		value[0] += ch % 256;
		value[1] += ch / 256;
	}

	operator std::wstring() {
		return value;
	}

	operator wchar_t() {
		return fromGex(value);
	}
};

std::vector<GEX> XORstrToGexAsVec(std::wstring phrase, std::wstring key = L"key") {
	std::vector<GEX> vec;
	unsigned long long i = -1;
	while (phrase.size() > ++i) vec.push_back(GEX(fromBits(XORbin(toBits(phrase[i]), toBits(key[i % key.length()])))));
	return vec;
}

std::wstring XORstrToGexAsStr(std::wstring phrase, std::wstring key = L"key") {
	std::wstring vec = L"";
	unsigned long long i = -1;
	while (phrase.size() > ++i) vec += (std::wstring)GEX(fromBits(XORbin(toBits(phrase[i]), toBits(key[i % key.length()]))));
	return vec;
}

std::wstring XORgexToStr(std::wstring phrase, std::wstring key = L"key") {
	std::wstring res = L"";
	unsigned long long i = -1;
	while ((phrase.size() >> 1) > ++i) res += (wchar_t)fromBits(XORbin(toBits(fromGex(phrase.substr(i << 1, 2))), toBits(key[i % key.length()])));
	return (std::wstring)res;
}

std::wstring XORgexToStr(std::vector<GEX> vec, std::wstring key = L"key") {
	std::wstring res = L"";
	unsigned long long i = -1;
	while (vec.size() > ++i) res += (wchar_t)fromBits(XORbin(toBits(vec.at(i)), toBits(key[i % key.length()])));
	return (std::wstring)res;
}