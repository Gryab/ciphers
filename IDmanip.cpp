#include "IDmanip.h"
std::wstring IDmanip::getID(std::wstring str, std::wstring id) {
	return str.substr(0, id.length());
};

bool IDmanip::hasID(std::wstring str, std::wstring id) {
	return getID(str, id) == id;
};

std::wstring IDmanip::noID(std::wstring str, std::wstring id) {
	return str.substr(id.length());
};