#include <fcntl.h>
#include <io.h>
#include <cctype>
#include "EncryptionTester.h"

int main()
{
	if (!_setmode(_fileno(stdout), _O_U16TEXT)) return 0;
	EncryptionTester a = EncryptionTester();
	a.Run_Test();
};