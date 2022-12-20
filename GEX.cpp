#include "GEX.h"
//----------------------------Constructors-------------------------------------
GEX::GEX(wchar_t ch) { Gvalue[0] += ch % gexBase, Gvalue[1] += ch / gexBase; }

GEX::GEX(std::wstring Fvalue) { Gvalue[0] = Fvalue[0], Gvalue[1] = Fvalue[1]; }
//----------------------------------Casts-------------------------------------
GEX::operator std::wstring() { return Gvalue; };

GEX::operator wchar_t() { return (Gvalue[1] - gex0) * gexBase + Gvalue[0] - gex0; }
//---------------------------------Operators----------------------------------
GEX GEX::operator= (GEX another) {
	*this->Gvalue = another;
	return *this;
}

GEX GEX::operator^ (GEX another) {
	return GEX((std::bitset<16>(*this) ^ std::bitset<16>(another)).to_ulong());
}

GEX GEX::operator^= (GEX another) {
	*this = *this ^ another;
	return *this;
}