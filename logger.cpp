#include "logger.h"
void logger::log(std::wstring value) {
	std::wcout << value;
};

void logger::log(wchar_t value) {
	std::wcout << value;
};

void logger::log(int64_t value) {
	std::wcout << value;
};

void logger::log(long double value) {
	std::wcout << value;
};