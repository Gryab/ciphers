#pragma once
#include <cassert>
#include <windows.h>
#include <iostream>
#include "RoundHashedEncryptotron.h"

class EncryptionTester
{
public:
	EncryptionTester() { return; };
	void Run_Test();
	bool showCorrectness(std::wstring toCheck, UINT32 startFrom);
private:
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const std::wstring strs[3] = {L" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|};~@ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïð",
							L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯяЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏѐёђѓєѕіїјљњћќѝўџѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿҀҁ҂◌҃◌҄◌҅◌҆◌҇◌҈◌҉ҊҋҌҍҎҏ",
							L"ҐґҒғҔҕҖҗҘҙҚқҜҝҞҟҠҡҢңҤҥҦҧҨҩҪҫҬҭҮүҰұҲҳҴҵҶҷҸҹҺһҼҽҾҿӀӁӂӃӄӅӆӇӈӉӊӋӌӍӎӏӐӑӒӓӔӕӖӗӘәӚӛӜӝӞӟӠӡӢӣӤӥӦӧӨөӪӫӬӭӮӯӰӱӲӳӴӵӶӷӸӹӺӻӼӽӾӿ"};
	const std::wstring keys[2] = {L"my_key", L"мой_ключ"};

	bool selectedKey = 1;

	UINT8 selectedStr = 2;

	void incrementStrAndKeyCounters();

	Encryptor obj = Encryptor(keys[0]);

	bool isCharCorrect(wchar_t toCheck, UINT32 lookAt);

	void setTextColour(UINT8 colour);
	
	void testInstance();

	void testWithOtherKey();

	std::wstring genExplanatoryStr();

	void success();
};