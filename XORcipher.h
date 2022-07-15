#pragma once
#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <bitset>
#include "alg.h"

std::bitset<16> toBits(wchar_t ch) {
	return std::bitset<16>(ch);
}
std::bitset<16> XOR(std::bitset<16> bin1, std::bitset<16> bin2) {
	return bin1 ^ bin2;
}
wchar_t fromBits(std::bitset<16> bin) {
	return (wchar_t)bin.to_ulong();
}

std::wstring XOR(std::wstring phrase, std::wstring key = L"key") {
	std::wstring res = L"";
	unsigned int i = -1;
	while (phrase.size() > ++i) res += (wchar_t)fromBits(XOR(toBits(phrase[i]), toBits(key[i % key.length()])));
	return (std::wstring)res;
}