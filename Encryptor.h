﻿#pragma once
#include <bitset>
#include <iostream>
#include "cwstring.h"

class Encryptor
{
public:
	Encryptor(std::wstring key);
	Encryptor changeKey(std::wstring key);
	Encryptor changeIdentifier(std::wstring identifier);

	std::wstring cipherXOR(std::wstring phrase);
	std::wstring caesar(std::wstring phrase);
	
	std::vector<GEX> XORstrToGexAsVec(cwstring phrase);
private:
	std::wstring gexIdentifier = L"gexInput"; 
	cwstring myKey;
	uint64_t iterator = -1;

	bool isGex(std::wstring phrase);
	std::wstring getIdentifier(std::wstring phrase);
	std::wstring withoutIdentifier(std::wstring phrase);

	std::wstring XORstrToGexAsStr(cwstring phrase);
	std::wstring XORgexToStr(cwstring phrase);

	cwstring caesarStrToGexAsStr(cwstring phrase);
	cwstring caesarGEXToStr(cwstring phrase);
};