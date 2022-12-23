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
	/*RoundHashedEncryptotron a = RoundHashedEncryptotron(L"key");
	RoundHashedEncryptotron b = RoundHashedEncryptotron(L"key");
	Encryptor c = Encryptor(L"key");
	a.changeKey(L"key");
	b.changeKey(L"key");
	std::wcout << a.encrypt(a.encrypt(L"abc", 7), 7);
	std::wcout << "\n" << b.encrypt(a.encrypt(L"abc", 7), 7);*/
};