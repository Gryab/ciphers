#include "XORcipher.h"

Encryptor::Encryptor(std::wstring key = L"key") { myKey = (cwstring)key; }

std::wstring Encryptor::cipher(std::wstring phrase) { iterator = -1; return isGex(phrase) ? XORgexToStr(removeIdentifier(phrase)) : XORstrToGexAsStr(phrase); }
//-----------------------------------Identifying GEX----------------------------------------------------------
Encryptor Encryptor::changeIdentifier(std::wstring identifier) { gexIdentifier = identifier; return *this; }

std::wstring Encryptor::getIdentifier(std::wstring phrase) { return phrase.substr(0, gexIdentifier.length()); }

std::wstring Encryptor::removeIdentifier(std::wstring phrase) { return phrase.substr(gexIdentifier.length()); }

bool Encryptor::isGex(std::wstring phrase) { return getIdentifier(phrase) == gexIdentifier; }

std::vector<GEX> Encryptor::XORstrToGexAsVec(cwstring phrase) {
	std::vector<GEX> gex;
	while (++iterator < phrase.size()) gex.push_back(GEX(phrase.at(iterator)) ^ GEX(myKey.at(iterator)));
	return gex;
}
std::wstring Encryptor::XORstrToGexAsStr(cwstring phrase) {
	cwstring gex(gexIdentifier);
	std::vector<GEX> vec = XORstrToGexAsVec(phrase);
	while (++iterator < phrase.size()) gex += (std::wstring)vec.at(iterator);
	return (std::wstring)gex;
}
std::wstring Encryptor::XORgexToStr(cwstring phrase) {
	cwstring str;
	while (++iterator < (phrase.size() >> 1)) str += (wchar_t)GEX(phrase.substr(iterator << 1, 2)) ^ GEX(myKey.at(iterator));
	return (std::wstring)str;
}