#pragma once
#include <vector>

std::vector<bool> toBits(wchar_t ch) {
	std::vector<bool> res{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char i = -1; ++i < 16; ch /= 2)res[15 - i] = ch % 2;
	return res;
}
std::vector<bool> XOR(std::vector<bool> bin1, std::vector<bool> bin2) {
	for (char i = -1; ++i < 16;) bin1[i] = bin1[i] ^ bin2[i];
	return bin1;
}
wchar_t fromBits(std::vector<bool> bin) {
	wchar_t res = bin[15];
	for (char i = -1; ++i < 15;) res += bin[i] << (15 - i);
	return res;
}

std::wstring XOR(std::wstring phrase, std::wstring key = L"key") {
	std::wstring res = L"";
	unsigned long long i = -1;
	while (phrase.size() > ++i) res += (wchar_t)fromBits(XOR(toBits(phrase[i]), toBits(key[i % key.length()])));
	return (std::wstring)res;
}