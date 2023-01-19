#include "bitRot.h"

wchar_t rotl(const wchar_t& n, const uint64_t& s) {
	return (n << s) | (n >> (16 - s));
};
wchar_t rotr(const wchar_t& n, const uint64_t& s) {
	return (n >> s) | (n << (16 - s));
};