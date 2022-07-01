﻿#include <windows.h>
#include "XORcipher.h"
#include "stringTesting.h"
char toSameCase(char toTransform, char toPickFrom) {
	return toupper(toPickFrom) == toPickFrom ? toupper(toTransform) : tolower(toTransform);
};

std::string caesar(int step, std::string phrase, unsigned int startFrom = -1) {
	while (phrase.size() > ++startFrom) phrase[startFrom] = phrase[startFrom] + step % 26;
	return phrase;
};

int main()
{
	const std::string orig = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\n@";
	const std::string key = "key";
	XORcipher th = XORcipher();
	testCorrectness(orig, th.XORGex(key, th.XORstr(key, orig)));
	std::cout << '\n' << th.XORstr(key, orig);
};