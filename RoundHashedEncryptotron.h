#pragma once
#include "Encryptor.h"

class RoundHashedEncryptotron
{
public:
	RoundHashedEncryptotron() {};

	RoundHashedEncryptotron changeKey(std::wstring sKey);

	RoundHashedEncryptotron setStr(std::wstring phrase);

	std::wstring encrypt(uint64_t rounds);

private:
	std::wstring key = L"key";
	std::wstring str;
	Encryptor obj = Encryptor(key);
	bool position = 0;
	void alternateFunctions();
	void transformKey(std::wstring sKey);
	void cycle();
	std::wstring cycleThrough(uint64_t rounds);
};