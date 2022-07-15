#include "XORcipher.h"
#include "alg.h"

std::vector<bool> XORcipher::toBits(unsigned char ch) {
	std::vector<bool> res{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char i = -1; ++i < 16; ch >>= 1)res[15 - i] = ch % 2;
	return res;
};
std::vector<bool> XORcipher::XOR(std::vector<bool> bin1, std::vector<bool> bin2) {
	char i = -1;
	for (; ++i < 16;)bin1[i] = bin1[i] ^ bin2[i];
	return bin1;
};
wchar_t XORcipher::fromBits(std::vector<bool> bin) {
	wchar_t ch = bin[15], i = -1;
	for (; ++i < 15;) ch += (1 << 15 - i) * bin[i];
	return ch;
};
std::wstring XORcipher::toGex(std::vector<bool> bin) {
	std::wstring res = L"!!!!";
	unsigned char ch = fromBits(bin);
	for (char i = -1; ++i < 4; ch /= 16)
	{
		res[i] += ch % 16;
	}
	return res;
};
std::wstring XORcipher::XORGex(std::wstring key, std::wstring phrase) {
	std::wstring res = L"";
	unsigned int i = -1;
	while (phrase.size() >> 2 > ++i) res += fromBits(XOR(toBits(gexToInt(phrase.substr(i << 2, 4))), toBits(key[i % key.size()])));
	return res;
};
std::wstring XORcipher::XORstr(std::wstring key, std::wstring phrase) {
	std::wstring res = L"";
	unsigned int i = -1;
	while (phrase.size() > ++i) res += toGex(XOR(toBits(phrase[i]), toBits(key[i % key.length()])));
	return res;
}