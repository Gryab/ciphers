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
	Encryptor a(L"my_key");
	assert(showCorrectness(orig, a.cipher(a.cipher(orig))));
	std::wcout << L"\nASCII string with cyrillic key\n";
	a = Encryptor(L"мой_ключ");
	assert(showCorrectness(orig, a.cipher(a.cipher(orig))));
	std::wcout << L"\nCyrillic string with ASCII key\n";
	orig = L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯяЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏѐёђѓєѕіїјљњћќѝўџѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿҀҁ҂◌҃◌҄◌҅◌҆◌҇◌҈◌҉ҊҋҌҍҎҏ";
	a = Encryptor(L"my_key");
	assert(showCorrectness(orig, a.cipher(a.cipher(orig))));
	std::wcout << L"\nCyrillic string with cyrillyc key\n";
	a = Encryptor(L"мой_ключ");
	assert(showCorrectness(orig, a.cipher(a.cipher(orig))));
	std::wcout << L"\nSecond part of cyrillic string with ASCII key\n";
	orig = L"ҐґҒғҔҕҖҗҘҙҚқҜҝҞҟҠҡҢңҤҥҦҧҨҩҪҫҬҭҮүҰұҲҳҴҵҶҷҸҹҺһҼҽҾҿӀӁӂӃӄӅӆӇӈӉӊӋӌӍӎӏӐӑӒӓӔӕӖӗӘәӚӛӜӝӞӟӠӡӢӣӤӥӦӧӨөӪӫӬӭӮӯӰӱӲӳӴӵӶӷӸӹӺӻӼӽӾӿ";
	a = Encryptor(L"my_key");
	assert(showCorrectness(orig, a.cipher(a.cipher(orig))));
	std::wcout << L"\nSecond part of cyrillic string with cyrillic key\n";
	a = Encryptor(L"мой_ключ");
	assert(showCorrectness(orig, a.cipher(a.cipher(orig))));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	success(hConsole);
}