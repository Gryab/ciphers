#include "EncryptionTester.h"
//------------------------console colour changer------------------------
void EncryptionTester::setTextColour(const UINT8 &colour = 7) {
	SetConsoleTextAttribute(hConsole, colour);
};
//----------------------------------matching the strings--------------------------------------
bool EncryptionTester::showCorrectness(const std::wstring &toCheck, UINT64 startFrom = -1) {
	bool flag = 1;
	while (++startFrom < toCheck.length()) {
		flag = charCorrectness(toCheck.at(startFrom), startFrom);
		wprintf(L"%c",toCheck.at(startFrom));
	};
	setTextColour();
	wprintf(L"\n%ls\n", (strs[selectedStr]).c_str());
	return flag;
};

bool EncryptionTester::charCorrectness(const wchar_t& toCheck, const UINT64& lookAt) {
	return isCharEqual(toCheck, lookAt) ? correct() : incorrect();
};

bool EncryptionTester::isCharEqual(const wchar_t& toCheck, const UINT64& lookAt) {
	return strs[selectedStr].at(lookAt) == toCheck;
};

bool EncryptionTester::correct() {
	setTextColour(2);
	return 1;
};

bool EncryptionTester::incorrect() {
	setTextColour(12);
	return 0;
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
	wprintf(L"%ls", genExplanatoryStr().c_str());
	obj.changeKey(keys[selectedKey]);
	testInstance();
};

std::wstring EncryptionTester::genExplanatoryStr() {
	return std::wstring(L"\n" + (std::wstring)(selectedStr ? L"Cyrillic" : L"ASCII") + L" string with " + (selectedKey ? L"cyrillic" : L"ASCII") + L" key\n");
};

void EncryptionTester::testInstance() {
	assert(showCorrectness(obj.encrypt(obj.encrypt(strs[selectedStr], 7), 7)));
};

//-----------------------(can be removed)----------------------
void EncryptionTester::success() {
	setTextColour(3);
	wprintf(L"\nnoice!");
	setTextColour();
};