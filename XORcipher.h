#pragma once
#include <string>
#include <regex>
#include <iterator>
#include <iostream>

class XORcipher
{
private:
	bool* toBits(unsigned char ch);
	bool* XOR(bool bin1[16], bool bin2[16]);
	char fromBits(bool bin[16]);
	std::string toGex(bool bin[16]);
public:
	XORcipher() {return;};
	std::string XORstr(std::string key, std::string phrase);
	std::string XORGex(std::string key, std::string phrase);
};