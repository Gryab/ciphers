#include "EncryptionTester.h"
//------------------------console colour changer------------------------
void EncryptionTester::setTextColour(UINT8 colour = 7) {
	SetConsoleTextAttribute(hConsole, colour);
};
//----------------------------------matching the strings--------------------------------------
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

bool EncryptionTester::isCharCorrect(wchar_t toCheck, UINT32 lookAt) {
	if (toCheck != strs[selectedStr].at(lookAt))
	{
		setTextColour(12);
		return 0;
	};
	setTextColour(2);
	return 1;
};
//--------------------------------------------different testing conditions logic-------------------------------------------
void EncryptionTester::Run_Test() {
	do {
		incrementStrAndKeyCounters();
		testWithOtherKey();
	} while (selectedStr + selectedKey < 3);
	success();
};

void EncryptionTester::incrementStrAndKeyCounters() {
	selectedStr = (selectedStr + !(selectedKey ^= 1)) % 3;
};

void EncryptionTester::testWithOtherKey() {
	std::wcout << genExplanatoryStr();
	obj.changeKey(keys[selectedKey]);
	testInstance();
};

std::wstring EncryptionTester::genExplanatoryStr() {
	return std::wstring(L"\n" + (std::wstring)(selectedStr ? L"Cyrillic" : L"ASCII") + L" string with " + (selectedKey ? L"cyrillic" : L"ASCII") + L" key\n");
};

void EncryptionTester::testInstance() {
	assert(showCorrectness(obj.cipherXOR(obj.cipherXOR(strs[selectedStr]))));
};

//-----------------------(can be removed)----------------------
void EncryptionTester::success() {
	setTextColour(3);
	std::wcout << L"\nnoice!";
	setTextColour();
};