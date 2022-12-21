#pragma once
#include <cassert>
#include <windows.h>
#include <iostream>
#include "XORcipher.h"

class EncryptionTester
{
public:
	EncryptionTester() { return; };
	void Run_Test();
	bool showCorrectness(std::wstring toCheck, UINT32 startFrom);
private:
	const std::wstring strs[3] = {L" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|};~@ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïð",
							L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯяЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏѐёђѓєѕіїјљњћќѝўџѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿҀҁ҂◌҃◌҄◌҅◌҆◌҇◌҈◌҉ҊҋҌҍҎҏ",
							L"ҐґҒғҔҕҖҗҘҙҚқҜҝҞҟҠҡҢңҤҥҦҧҨҩҪҫҬҭҮүҰұҲҳҴҵҶҷҸҹҺһҼҽҾҿӀӁӂӃӄӅӆӇӈӉӊӋӌӍӎӏӐӑӒӓӔӕӖӗӘәӚӛӜӝӞӟӠӡӢӣӤӥӦӧӨөӪӫӬӭӮӯӰӱӲӳӴӵӶӷӸӹӺӻӼӽӾӿ"};

	const std::wstring keys[2] = {L"my_key", L"мой_ключ"};

	void incrementStrAndKeyCounters();

	bool isCharCorrect(wchar_t toCheck, UINT32 startFrom);

	bool selectedKey = 1;

	UINT8 selectedStr = 2;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void setTextColour(UINT8 colour);

	Encryptor obj = Encryptor(L"my_key");

	void success();

	void testWithOtherKey();

	void testInstance();

	std::wstring genExplanatoryStr();
};