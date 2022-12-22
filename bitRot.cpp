#include "bitRot.h"

wchar_t rotl(wchar_t n, uint64_t s) {
	return (n << s) | (n >> (16 - s));
}
wchar_t rotr(wchar_t n, uint64_t s) {
	return (n >> s) | (n << (16 - s));
}