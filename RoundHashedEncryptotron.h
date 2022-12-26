#pragma once
#include "Encryptor.h"

class RoundHashedEncryptotron
{
public:
	RoundHashedEncryptotron(std::wstring key);

	RoundHashedEncryptotron changeKey(std::wstring sKey);

	RoundHashedEncryptotron changeIdentifier(std::wstring identifier);

	std::wstring encrypt(std::wstring phrase, uint64_t rounds);

private:
	uint64_t requieredKeyLength();
	std::wstring key = L"key";
	std::wstring temp_key = L"";
	std::wstring str;
	std::wstring gexIdentifier = L"gexInput";
	Encryptor obj = Encryptor(key);
	void transformKey();
	void cycle();
	void cycleKey();
	std::wstring cycleThrough(uint64_t rounds);
	RoundHashedEncryptotron useKey();
};