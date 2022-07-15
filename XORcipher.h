#pragma once
#include <string>
#include <regex>
#include <iterator>
#include <vector>
#include <iostream>

class XORcipher
{
private:
	std::vector<bool> toBits(unsigned char ch);
	std::vector<bool> XOR(std::vector<bool> bin1, std::vector<bool> bin2);
	char fromBits(std::vector<bool> bin);
	std::string toGex(std::vector<bool> bin);
public:
	XORcipher() {return;};
	std::string XORstr(std::string key, std::string phrase);
	std::string XORGex(std::string key, std::string phrase);
};