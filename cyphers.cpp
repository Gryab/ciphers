#include <windows.h>
#include <fcntl.h>
#include <io.h>
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
	_setmode(_fileno(stdout), _O_U16TEXT);
	Run_XOR_Test();
};