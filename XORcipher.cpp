#include "XORcipher.h"

GEX GEX::operator= (GEX another) { 
	*this->Gvalue = another;
	return *this; 
}
GEX GEX::operator^= (GEX another) {
	*this = *this ^ another;
	return *this;
}

std::vector<GEX> XOR::XORstrToGexAsVec(cwstring phrase) {
	std::vector<GEX> gex;
	uint64_t i = -1;
	while (++i < phrase.size()) gex.push_back(GEX(phrase.at(i)) ^ GEX(myKey.at(i)));
	return gex;
}
std::wstring XOR::XORstrToGexAsStr(cwstring phrase) {
	cwstring gex(gexIdentifier);
	uint64_t i = -1;
	std::vector<GEX> vec = XORstrToGexAsVec(phrase);
	while (++i < phrase.size()) gex += (std::wstring)vec.at(i);
	return (std::wstring)gex;
}
std::wstring XOR::XORgexToStr(cwstring phrase) {
	cwstring str;
	uint64_t i = -1;
	while (++i < (phrase.size() >> 1)) str += (wchar_t)GEX(phrase.substr(i << 1, 2)) ^ GEX(myKey.at(i));
	return (std::wstring)str;
}