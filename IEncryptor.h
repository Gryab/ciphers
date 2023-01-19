#pragma once
#include <string>

__interface IEncryptor {
public:
	virtual std::wstring encrypt(const std::wstring& phrase, uint64_t num) = 0;
	virtual void* changeKey(const std::wstring &sKey) = 0;
	virtual void* changeIdentifier(const std::wstring& identifier) = 0;
};