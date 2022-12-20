#include "cwstring.h"

cwstring::cwstring(std::vector<GEX> vec) { for (uint64_t i = -1; ++i < vec.size();) __super::append(vec.at(i)); }

wchar_t cwstring::at(uint64_t k) { return __super::at(k % __super::length()); }