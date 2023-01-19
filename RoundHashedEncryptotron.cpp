#include "RoundHashedEncryptotron.h"

//==============================constructors and setters========================================

RoundHashedEncryptotron::RoundHashedEncryptotron(const std::wstring& key) { changeKey(key); };

void* RoundHashedEncryptotron::changeKey(const std::wstring &sKey) {
	temp_key = sKey;
	return this;
};

void* RoundHashedEncryptotron::changeIdentifier(const std::wstring& identifier) {
	gexIdentifier = identifier;
	return this;
};

//==============encryption rounds===================================================

std::wstring RoundHashedEncryptotron::encrypt(const std::wstring& phrase, uint64_t rounds) {
	str = phrase;
	useKey();
	str = obj.caesar(str);
	return cycleThrough(rounds);
};

std::wstring RoundHashedEncryptotron::cycleThrough(uint64_t &rounds) {
	while (--rounds) {
		cycle();
	};
	return str;
};

void RoundHashedEncryptotron::cycle() {
	str = obj.caesar(obj.cipherXOR(str));
};

//==============================key transformation==========================

RoundHashedEncryptotron RoundHashedEncryptotron::useKey() {
	transformKey();
	obj.changeKey(key);
	return *this;
};

void RoundHashedEncryptotron::transformKey() {
	while (key.length() < requieredKeyLength()) {
		cycleKey();
	};
};

uint64_t RoundHashedEncryptotron::requieredKeyLength() {
	return hasID(str, gexIdentifier) ? noID(str, gexIdentifier).length() >> 1 : str.length();
};

void RoundHashedEncryptotron::cycleKey() {
	key = (*((Encryptor*)(obj.changeKey(key)))).cipherXOR(temp_key + key).substr(1);
};