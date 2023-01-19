#pragma once
#include "Encryptor.h"

class RoundHashedEncryptotron : public IEncryptor
{
public:
	RoundHashedEncryptotron(const std::wstring& key);

	void* changeKey(const std::wstring &sKey) override;

	void* changeIdentifier(const std::wstring& identifier) override;

	std::wstring encrypt(const std::wstring& phrase, uint64_t rounds) override;

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
	std::wstring cycleThrough(uint64_t& rounds);
	RoundHashedEncryptotron useKey();
};