#include "cwstring.h"

cwstring::cwstring(std::vector<GEX> vec) { 
	for (uint64_t i = -1; ++i < vec.size();) __super::append(vec.at(i)); 
};

cwstring::operator uint64_t() {
	uint64_t n = 0, i = -1;
	for (; ++i < __super::length();) n += ((uint64_t)__super::at(i) - 32);
	return n;
};

wchar_t cwstring::at(uint64_t k) { return __super::at(k % __super::length()); };