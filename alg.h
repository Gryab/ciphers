#pragma once
wchar_t gexToInt(std::wstring gex) {
	wchar_t res = 0;
	for (int i = -1; ++i < 4;) res += gex[i] * pow(16, i) - L'!';
	return res;
}