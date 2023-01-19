#pragma once
#include <bitset>
#include <iostream>
#include "IDmanip.h"
#include "IEncryptor.h"

class Encryptor : public IEncryptor
{
public:
	enum encryptionType {XOR = 1, CAESAR = 2};

	Encryptor(const std::wstring& key);
	void* changeKey(const std::wstring& key) override;
	void* changeIdentifier(const std::wstring& identifier) override;

	std::wstring cipherXOR(std::wstring phrase);
	std::wstring caesar(std::wstring phrase);
	
	std::wstring encrypt(const std::wstring& phrase, uint64_t encType) override;

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