#pragma once
#include <vector>

class cbitset : public std::vector<bool>
{
private:
	const char lastPosOfBit = 15;
public:
	cbitset(wchar_t ch) : std::vector<bool>(16) { for (char i = -1; ++i < lastPosOfBit + 1; ch >>= 1) __super::operator[](lastPosOfBit - i) = ch % 2; };
	cbitset(std::vector<bool> bin) : std::vector<bool>(16) { __super::assign(bin.begin(), bin.end()); };
	cbitset() : std::vector<bool>() { __super::assign(16, 0); };

	bool at(unsigned long long k) { return __super::at(k % __super::size()); }

	cbitset operator^ (cbitset another) { cbitset res; for (char i = -1; ++i < lastPosOfBit + 1;) res[i] = __super::at(i) ^ another.at(i); return res; }
	cbitset operator^= (cbitset another) { __super::operator=(*this ^ another); return *this; }

	operator wchar_t() {
		wchar_t res = __super::at(lastPosOfBit);
		for (char i = -1; ++i < lastPosOfBit;) res += __super::at(i) << (lastPosOfBit - i);
		return res;
	}

	operator std::vector<bool>() { return std::vector<bool>(__super::begin(), __super::end()); }
};

class GEX
{
private:
	const unsigned short gex0 = 1024U;
	const unsigned short gexBase = 256U;
	wchar_t Gvalue[3]{gex0, gex0};
public:
	GEX(wchar_t ch) { Gvalue[0] += ch % gexBase, Gvalue[1] += ch / gexBase; }
	GEX(std::wstring Fvalue) { Gvalue[0] = Fvalue[0], Gvalue[1] = Fvalue[1]; }

	operator std::wstring() { return Gvalue; }
	operator wchar_t() { return (Gvalue[1] - gex0) * gexBase + Gvalue[0] - gex0; }

	GEX operator= (GEX another) { *this->Gvalue = another; }
	GEX operator^ (GEX another) { return GEX(cbitset(*this) ^ cbitset(another)); }
	GEX operator^= (GEX another) {
		*this = *this ^ another;
		return *this;
	}
};

class cwstring : public std::wstring
{
public:
	cwstring(std::wstring strT = L"") : std::wstring(strT) {};
	cwstring(wchar_t wchar) : std::wstring(&wchar) {};
	cwstring(std::vector<GEX> vec) { for (unsigned long long i = -1; ++i < vec.size();) __super::append(vec.at(i)); };

	wchar_t at(unsigned long long k) { return __super::at(k % __super::length()); }
};

class XOR
{
public:
	XOR(std::wstring key = L"key") { myKey = key; }
	XOR changeIdentifier(std::wstring identifier) { gexIdentifier = identifier; }

	std::wstring cipher(std::wstring phrase) { return phrase.substr(0, gexIdentifier.length()) == gexIdentifier ? XORgexToStr(phrase.substr(gexIdentifier.length())) : XORstrToGexAsStr(phrase); }
	
	std::vector<GEX> XORstrToGexAsVec(cwstring phrase) {
		std::vector<GEX> gex;
		unsigned long long i = -1;
		while (++i < phrase.size()) gex.push_back(GEX(phrase.at(i)) ^ GEX(myKey.at(i)));
		return gex;
	}

private:
	std::wstring gexIdentifier = L"gexInput";
	cwstring myKey;

	std::wstring XORstrToGexAsStr(cwstring phrase) {
		cwstring gex(gexIdentifier);
		unsigned long long i = -1;
		std::vector<GEX> vec = XORstrToGexAsVec(phrase);
		while (++i < phrase.size()) gex += (std::wstring)vec.at(i);
		return (std::wstring)gex;
	}

	std::wstring XORgexToStr(cwstring phrase) {
		cwstring str;
		unsigned long long i = -1;
		while (++i < (phrase.size() >> 1)) str += (wchar_t)GEX(phrase.substr(i << 1, 2)) ^ GEX(myKey.at(i));
		return (std::wstring)str;
	}
};