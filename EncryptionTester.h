#pragma once
#include <cassert>
#include <windows.h>
#include "RoundHashedEncryptotron.h"

class EncryptionTester
{
public:
	void Run_Test();
	bool showCorrectness(const std::wstring &toCheck, UINT64 startFrom);
private:
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const std::wstring strs[3] = {L" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|};~@ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïð",
							L"АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯяЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏѐёђѓєѕіїјљњћќѝўџѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿҀҁ҂◌҃◌҄◌҅◌҆◌҇◌҈◌҉ҊҋҌҍҎҏ",
							L"ҐґҒғҔҕҖҗҘҙҚқҜҝҞҟҠҡҢңҤҥҦҧҨҩҪҫҬҭҮүҰұҲҳҴҵҶҷҸҹҺһҼҽҾҿӀӁӂӃӄӅӆӇӈӉӊӋӌӍӎӏӐӑӒӓӔӕӖӗӘәӚӛӜӝӞӟӠӡӢӣӤӥӦӧӨөӪӫӬӭӮӯӰӱӲӳӴӵӶӷӸӹӺӻӼӽӾӿ"};
	const std::wstring keys[2] = {L"my_key", L"мой_ключ"};

	bool selectedKey = 1;

	UINT8 selectedStr = 2;

	void incrementStrAndKeyCounters();

	IEncryptor &obj = *(IEncryptor*)(new RoundHashedEncryptotron(keys[0]));

	bool charCorrectness(const wchar_t &toCheck, const UINT64 &lookAt);

	bool isCharEqual(const wchar_t& toCheck, const UINT64& lookAt);

	bool correct();

	bool incorrect();

	void setTextColour(const UINT8 &colour);
	
	void testInstance();

	void testWithOtherKey();

	std::wstring genExplanatoryStr();

	void success();
};