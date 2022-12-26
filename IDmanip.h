#pragma once
#include "cwstring.h"
class IDmanip
{
public:
	static std::wstring getID(std::wstring str, std::wstring id);

	static bool hasID(std::wstring str, std::wstring id);

	static std::wstring noID(std::wstring str, std::wstring id);
};