#pragma once
#include <string>
#include <iterator>
#include <vector>
#include <iostream>

class XORcipher
{
private:
	std::vector<bool> toBits(unsigned char ch);
	std::vector<bool> XOR(std::vector<bool> bin1, std::vector<bool> bin2);
	wchar_t fromBits(std::vector<bool> bin);
	std::wstring toGex(std::vector<bool> bin);
public:
	XORcipher() {return;};
	std::wstring XORstr(std::wstring key, std::wstring phrase);
	std::wstring XORGex(std::wstring key, std::wstring phrase);
};