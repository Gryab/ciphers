#include "EncryptionTester.h"

void EncryptionTester::setTextColour(UINT8 colour = 7) {
	SetConsoleTextAttribute(hConsole, colour);
};

void EncryptionTester::success() {
	setTextColour(3);
	std::wcout << L"\nnoice!";
	setTextColour();
};

bool EncryptionTester::isCharCorrect(wchar_t toCheck, UINT32 startFrom) {
	if (toCheck != strs[selectedStr].at(startFrom))
	{
		setTextColour(12);
		return 0;
	};
	setTextColour(2);
	return 1;
};

bool EncryptionTester::showCorrectness(std::wstring toCheck, UINT32 startFrom = -1) {
	bool flag = 1;
	while (++startFrom < toCheck.length()) {
		flag = isCharCorrect(toCheck.at(startFrom), startFrom);
		std::wcout << toCheck.at(startFrom);
	};
	setTextColour();
	std::wcout << '\n' << strs[selectedStr] << '\n';
	setTextColour();
	return flag;
};

void EncryptionTester::testWithOtherKey() {
	obj.changeKey(keys[selectedKey]);
	testInstance();
};

std::wstring EncryptionTester::genExplanatoryStr() {
	return std::wstring(L"\n" + (std::wstring)(selectedStr ? L"Cyrillic" : L"ASCII") + L" string with " + (selectedKey? L"cyrillic" : L"ASCII") + L" key\n");
};

void EncryptionTester::testInstance() {
	assert(showCorrectness(obj.cipherXOR(obj.cipherXOR(strs[selectedStr]))));
};

void EncryptionTester::incrementStrAndKeyCounters() {
	selectedStr = (selectedStr + !(selectedKey ^= 1)) % 3;
};

void EncryptionTester::Run_Test() {
	do {
		incrementStrAndKeyCounters();
		std::wcout << genExplanatoryStr();
		testWithOtherKey();
	} while (selectedStr + selectedKey < 3);
	success();
};