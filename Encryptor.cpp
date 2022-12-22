#include "Encryptor.h"
#include "bitRot.h"

//------------------key and constructor-------------------------------------------------------------

Encryptor::Encryptor(std::wstring key = L"key") {
	myKey = (cwstring)key;
};
Encryptor Encryptor::changeKey(std::wstring key) { 
	myKey = (cwstring)key; 
	return *this; 
};

//-----------------------------------Identifying GEX----------------------------------------------------------

Encryptor Encryptor::changeIdentifier(std::wstring identifier) { 
	gexIdentifier = identifier; return *this; 
};

std::wstring Encryptor::getIdentifier(std::wstring phrase) { 
	return phrase.substr(0, gexIdentifier.length()); 
};

std::wstring Encryptor::withoutIdentifier(std::wstring phrase) { 
	return phrase.substr(gexIdentifier.length()); 
};

bool Encryptor::isGex(std::wstring phrase) { 
	return getIdentifier(phrase) == gexIdentifier; 
};

//==================================================Enciphering in XOR=============================================================================

std::wstring Encryptor::cipherXOR(std::wstring phrase) { 
	iterator = -1; 
	return isGex(phrase) ? XORgexToStr(withoutIdentifier(phrase)) : XORstrToGexAsStr(phrase);
};

std::vector<GEX> Encryptor::XORstrToGexAsVec(cwstring phrase) {
	std::vector<GEX> gex = {};
	while (++iterator < phrase.size()) gex.push_back(GEX(phrase.at(iterator)) ^ GEX(myKey.at(iterator)));
	return gex;
};

std::wstring Encryptor::XORstrToGexAsStr(cwstring phrase) {
	cwstring gex(gexIdentifier);
	while (++iterator < phrase.size()) gex += (std::wstring)(GEX(phrase.at(iterator)) ^ GEX(myKey.at(iterator)));
	return (std::wstring)gex;
};

std::wstring Encryptor::XORgexToStr(cwstring phrase) {
	cwstring str;
	while (++iterator < (phrase.size() >> 1)) str += (wchar_t)GEX(phrase.substr(iterator << 1, 2)) ^ GEX(myKey.at(iterator));
	return (std::wstring)str;
};

//===========================================================Enciphering in Caesar=============================================================================

cwstring Encryptor::caesarStrToGexAsStr(cwstring phrase) {
	cwstring str(gexIdentifier);
	while (++iterator < phrase.size()) { str += (std::wstring)GEX(rotl((uint16_t)GEX(phrase.at(iterator)), (uint64_t)myKey % 16)); };
	return str;
};

cwstring Encryptor::caesarGEXToStr(cwstring phrase) {
	cwstring str(L"");
	while (++iterator < (phrase.size() >> 1)) { str += (wchar_t)GEX((wchar_t)rotr((uint16_t)GEX(phrase.substr(iterator << 1, 2)), ((uint64_t)myKey % 16))); };
	return str;
};

std::wstring Encryptor::caesar(std::wstring phrase) {
	iterator = -1;
	return isGex(phrase) ? caesarGEXToStr(withoutIdentifier(phrase)) : caesarStrToGexAsStr(phrase);
};