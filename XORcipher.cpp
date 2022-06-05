#include "XORcipher.h"
#include "alg.h"

bool* XORcipher::toBits(unsigned char ch) {
	bool* res = new bool[8];
	for (char i = -1; ++i < 8; ch >>= 1)res[7 - i] = ch % 2;
	return res;
};
bool* XORcipher::XOR(bool bin1[8], bool bin2[8]) {
	char i = -1;
	for (; ++i < 8;)bin1[i] = bin1[i] ^ bin2[i];
	return bin1;
};
char XORcipher::fromBits(bool bin[8]) {
	unsigned char ch = bin[7], i = -1;
	for (; ++i < 7;) ch += (1 << 7 - i) * bin[i];
	return ch;
};
std::string XORcipher::toGex(bool bin[8]) {
	std::string res = "!!";
	unsigned char ch = fromBits(bin);
	res[0] += ch % 16;
	res[1] += ch / 16;
	return res;
};
std::string XORcipher::XORGex(std::string key, std::string phrase) {
	std::string res = "";
	unsigned int i = -1;
	while (phrase.size() >> 1 > ++i) res += fromBits(XOR(toBits(gexToInt(phrase.substr(i << 1, 2))), toBits(key[i % key.size()])));
	return res;
};
std::string XORcipher::XORstr(std::string key, std::string phrase) {
	std::string res = "";
	unsigned int i = -1;
	while (phrase.size() > ++i) res += toGex(XOR(toBits(phrase[i]), toBits(key[i % key.length()])));
	return res;
}