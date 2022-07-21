#pragma once
#include <cassert>

void success(HANDLE hConsole) {
	SetConsoleTextAttribute(hConsole, 2);
	std::wcout << L"\nnoice!";
	SetConsoleTextAttribute(hConsole, 7);
}

bool showCorrectness(std::wstring reference, std::wstring toCheck, unsigned int startFrom = -1) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool flag = 1;
	while (++startFrom < toCheck.size())
	{
		SetConsoleTextAttribute(hConsole, 15);
		if (toCheck.at(startFrom) != reference.at(startFrom))
		{
			SetConsoleTextAttribute(hConsole, 12);
			flag = 0;
		}
		std::wcout << toCheck.at(startFrom);
	}
	SetConsoleTextAttribute(hConsole, 2);
	std::wcout << '\n' << reference << '\n';
	SetConsoleTextAttribute(hConsole, 7);
	return flag;
}

void Run_XOR_Test() {
	std::wcout << L"ASCII string with ASCII key\n";
	std::wstring orig = L" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~@ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïð";
	std::wstring key = L"my_key";
	assert(showCorrectness(orig, XORgexToStr(XORstrToGexAsVec(orig, key), key)));
	std::wcout << L"\nASCII string with cyrillic key\n";
	key = L"мой_ключ";
	assert(showCorrectness(orig, XORgexToStr(XORstrToGexAsVec(orig, key), key)));
	std::wcout << L"\nCyrillic string with ASCII key\n";
	orig = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯяЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏѐёђѓєѕіїјљњћќѝўџѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿҀҁ҂◌҃◌҄◌҅◌҆◌҇◌҈◌҉ҊҋҌҍҎҏ";
	key = L"my_key";
	assert(showCorrectness(orig, XORgexToStr(XORstrToGexAsVec(orig, key), key)));
	std::wcout << L"\nCyrillic string with cyrillyc key\n";
	key = L"мой_ключ";
	assert(showCorrectness(orig, XORgexToStr(XORstrToGexAsVec(orig, key), key)));
	std::wcout << L"\nSecond part of cyrillic string with ASCII key\n";
	orig = L"ҐґҒғҔҕҖҗҘҙҚқҜҝҞҟҠҡҢңҤҥҦҧҨҩҪҫҬҭҮүҰұҲҳҴҵҶҷҸҹҺһҼҽҾҿӀӁӂӃӄӅӆӇӈӉӊӋӌӍӎӏӐӑӒӓӔӕӖӗӘәӚӛӜӝӞӟӠӡӢӣӤӥӦӧӨөӪӫӬӭӮӯӰӱӲӳӴӵӶӷӸӹӺӻӼӽӾӿ";
	key = L"my_key";
	assert(showCorrectness(orig, XORgexToStr(XORstrToGexAsVec(orig, key), key)));
	std::wcout << L"\nSecond part of cyrillic string with cyrillic key\n";
	key = L"мой_ключ";
	assert(showCorrectness(orig, XORgexToStr(XORstrToGexAsVec(orig, key), key)));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	success(hConsole);
}