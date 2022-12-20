#pragma once
#include "cwstring.h"

class Encryptor
{
public:
	Encryptor(std::wstring key);
	Encryptor changeIdentifier(std::wstring identifier);

	std::wstring cipher(std::wstring phrase);
	
	std::vector<GEX> XORstrToGexAsVec(cwstring phrase);
private:
	std::wstring gexIdentifier = L"gexInput";
	cwstring myKey;
	uint64_t iterator = -1;

	std::wstring getIdentifier(std::wstring phrase);
	std::wstring removeIdentifier(std::wstring phrase);

	bool isGex(std::wstring phrase);

	std::wstring XORstrToGexAsStr(cwstring phrase);
	std::wstring XORgexToStr(cwstring phrase);
};