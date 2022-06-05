#include <windows.h>
#include "XORcipher.h"
char toSameCase(char toTransform, char toPickFrom) {
	return toupper(toPickFrom) == toPickFrom ? toupper(toTransform) : tolower(toTransform);
};

std::string caesar(int step, std::string phrase, unsigned int startFrom = -1) {
	while (phrase.size() > ++startFrom) phrase[startFrom] = phrase[startFrom] + step % 26;
	return phrase; 
};

void testCorrectness(std::string reference, std::string toCheck, unsigned int startFrom = -1) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (++startFrom < toCheck.size())
	{
		SetConsoleTextAttribute(hConsole, 15);
		if (toCheck[startFrom] != reference[startFrom % reference.size()])
		{
			SetConsoleTextAttribute(hConsole, 12);
		}
		std::cout << toCheck[startFrom];
	}
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << '\n' + reference + '\n';
	SetConsoleTextAttribute(hConsole, 7);
}
void countCorrectness(std::string reference, std::string toCheck, unsigned int startFrom = -1) {
	int i = 0;
	while (++startFrom < toCheck.size())
	{
		if (toCheck[startFrom] != reference[(startFrom + i) % reference.size()])
		{
			i++;
		}
	}
	std::cout << '\n' + i + '\n';
}

int main()
{
	const std::string orig = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\n@";
	const std::string key = "key";
	XORcipher th = XORcipher();
	testCorrectness(orig, th.XORGex(key, th.XORstr(key, orig)));
	std::cout << '\n' << th.XORstr(key, orig);
};