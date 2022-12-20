#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <cctype>
#include "XORcipher.h"
#include "stringTesting.h"

int main()
{
	if (!_setmode(_fileno(stdout), _O_U16TEXT)) return 0;
	Run_XOR_Test();
};