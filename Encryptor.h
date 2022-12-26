#pragma once
#include <bitset>
#include <iostream>
#include "IDmanip.h"

class Encryptor
{
public:
	Encryptor(std::wstring key);
	Encryptor changeKey(std::wstring key);
	Encryptor changeIdentifier(std::wstring identifier);

	std::wstring cipherXOR(std::wstring phrase);
	std::wstring caesar(std::wstring phrase);
	
	std::vector<GEX> xorStrToGexAsVec(cwstring phrase);
private:
	std::wstring gexIdentifier = L"gexInput"; 
	cwstring myKey;
	uint64_t iterator = -1;

	std::wstring xorStrToGexAsStr(cwstring phrase);
	std::wstring xorGEXToStr(cwstring phrase);

	cwstring caesarStrToGexAsStr(cwstring phrase);
	cwstring caesarGEXToStr(cwstring phrase);
};