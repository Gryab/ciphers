#include "RoundHashedEncryptotron.h"

RoundHashedEncryptotron RoundHashedEncryptotron::changeKey(std::wstring sKey) {
	transformKey(sKey);
	obj.changeKey(key);
	return *this;
};

void RoundHashedEncryptotron::transformKey(std::wstring sKey) {
	while (key.length() < str.length()) {
		key = obj.changeKey(key).cipherXOR(sKey + key).substr(1); 
	};
};

RoundHashedEncryptotron RoundHashedEncryptotron::setStr(std::wstring phrase) {
	str = phrase;
	return *this;
};

std::wstring RoundHashedEncryptotron::encrypt(uint64_t rounds) {
	str = obj.caesar(str);
	return cycleThrough(rounds);
};

std::wstring RoundHashedEncryptotron::cycleThrough(uint64_t rounds) {
	while (--rounds) {
		cycle();
	};
	return str;
};

void RoundHashedEncryptotron::cycle() {
	str = obj.caesar(obj.cipherXOR(str));
};

void RoundHashedEncryptotron::alternateFunctions() {
	position ^= 1;
};