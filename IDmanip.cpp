#include "IDmanip.h"
std::wstring getID(std::wstring str, std::wstring id) {
	return str.substr(0, id.length());
};

bool hasID(std::wstring str, std::wstring id) {
	return getID(str, id) == id;
};

std::wstring noID(std::wstring str, std::wstring id) {
	return str.substr(id.length());
};