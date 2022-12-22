#include <fcntl.h>
#include <io.h>
#include <cctype>
#include "EncryptionTester.h"
#include "RoundHashedEncryptotron.h"

int main()
{
	if (!_setmode(_fileno(stdout), _O_U16TEXT)) return 0;
	EncryptionTester a = EncryptionTester();
	a.Run_Test();
	/*RoundHashedEncryptotron a = RoundHashedEncryptotron();
	RoundHashedEncryptotron b = RoundHashedEncryptotron();
	Encryptor c = Encryptor(L"key");
	a.setStr(L"abc");
	a.changeKey(L"key");
	//b.setStr(a.encrypt(7));
	b.changeKey(L"key");
	std::wcout << a.setStr(a.encrypt(7)).encrypt(7);
	a.setStr(L"abc");
	std::wcout << a.encrypt(7);*/
};