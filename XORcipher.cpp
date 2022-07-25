#include "XORcipher.h"

cbitset cbitset::operator^ (cbitset another) { 
	cbitset res; 
	for (char i = -1; ++i < lastBitPos + 1;) res[i] = __super::at(i) ^ another.at(i);
	return res; 
}
cbitset cbitset::operator^= (cbitset another) { 
	__super::operator=(*this ^ another); 
	return *this; 
}
cbitset::operator wchar_t() {
	wchar_t res = __super::at(lastBitPos);
	for (char i = -1; ++i < lastBitPos;) res += __super::at(i) << (lastBitPos - i);
	return res;
}

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
	unsigned long long i = -1;
	while (++i < phrase.size()) gex.push_back(GEX(phrase.at(i)) ^ GEX(myKey.at(i)));
	return gex;
}
std::wstring XOR::XORstrToGexAsStr(cwstring phrase) {
	cwstring gex(gexIdentifier);
	unsigned long long i = -1;
	std::vector<GEX> vec = XORstrToGexAsVec(phrase);
	while (++i < phrase.size()) gex += (std::wstring)vec.at(i);
	return (std::wstring)gex;
}
std::wstring XOR::XORgexToStr(cwstring phrase) {
	cwstring str;
	unsigned long long i = -1;
	while (++i < (phrase.size() >> 1)) str += (wchar_t)GEX(phrase.substr(i << 1, 2)) ^ GEX(myKey.at(i));
	return (std::wstring)str;
}