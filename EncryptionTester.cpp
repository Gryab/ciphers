#include "EncryptionTester.h"
//------------------------console colour changer------------------------
void EncryptionTester::setTextColour(UINT8 colour = 7) {
	SetConsoleTextAttribute(hConsole, colour);
};
//----------------------------------matching the strings--------------------------------------
bool EncryptionTester::showCorrectness(std::wstring toCheck, UINT32 startFrom = -1) {
	bool flag = 1;
	while (++startFrom < toCheck.length()) {
		flag = charCorrectness(toCheck.at(startFrom), startFrom);
		logger::log(toCheck.at(startFrom));
	};
	setTextColour();
	logger::log(L'\n' + strs[selectedStr] + L'\n');
	return flag;
};

bool EncryptionTester::charCorrectness(wchar_t toCheck, UINT32 lookAt) {
	return isCharEqual(toCheck, lookAt) ? correct() : incorrect();
};

bool EncryptionTester::isCharEqual(wchar_t toCheck, UINT32 lookAt) {
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
	logger::log(genExplanatoryStr());
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
	logger::log(L"\nnoice!");
	setTextColour();
};