#pragma once
#include <cassert>
#include <windows.h>
#include "logger.h"
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

	RoundHashedEncryptotron obj = RoundHashedEncryptotron(keys[0]);

	bool charCorrectness(wchar_t toCheck, UINT32 lookAt);

	bool isCharEqual(wchar_t toCheck, UINT32 lookAt);

	bool correct();

	bool incorrect();

	void setTextColour(UINT8 colour);
	
	void testInstance();

	void testWithOtherKey();

	std::wstring genExplanatoryStr();

	void success();
};