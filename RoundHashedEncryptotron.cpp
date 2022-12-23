#include "RoundHashedEncryptotron.h"
//==============================constructors and setters========================================
RoundHashedEncryptotron::RoundHashedEncryptotron(std::wstring key) { changeKey(key); };

RoundHashedEncryptotron RoundHashedEncryptotron::changeKey(std::wstring sKey) {
	temp_key = sKey;
	return *this;
};

RoundHashedEncryptotron RoundHashedEncryptotron::changeIdentifier(std::wstring identifier) {
	gexIdentifier = identifier;
	return *this;
};

//==============encryption rounds===================================================

std::wstring RoundHashedEncryptotron::encrypt(std::wstring phrase, uint64_t rounds) {
	str = phrase;
	useKey();
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
	return isGex() ? withoutIdentifier().length() / 2 : str.length();
};

void RoundHashedEncryptotron::cycleKey() {
	key = obj.changeKey(key).cipherXOR(temp_key + key).substr(1);
};

//============================GEX=======================================

bool RoundHashedEncryptotron::isGex() {
	return (getIdentifier() == gexIdentifier);
};

std::wstring RoundHashedEncryptotron::getIdentifier() {
	return str.substr(0, gexIdentifier.size());
};

std::wstring RoundHashedEncryptotron::withoutIdentifier() {
	return str.substr(gexIdentifier.size());
};