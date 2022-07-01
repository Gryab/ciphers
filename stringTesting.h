#pragma once
void testCorrectness(std::string reference, std::string toCheck, unsigned int startFrom = -1) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (++startFrom < toCheck.size())
	{
		SetConsoleTextAttribute(hConsole, 15);
		if (toCheck.at(startFrom) != reference.at(startFrom % reference.size()))
		{
			SetConsoleTextAttribute(hConsole, 12);
		}
		std::cout << toCheck.at(startFrom);
	}
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << '\n' + reference + '\n';
	SetConsoleTextAttribute(hConsole, 7);
}
void countCorrectness(std::string reference, std::string toCheck, unsigned int startFrom = -1) {
	unsigned int i = 0;
	while (++startFrom < toCheck.size())
	{
		if (toCheck.at(startFrom) != reference.at((startFrom + i) % reference.size()))
		{
			i++;
		}
	}
	std::cout << '\n' + i + '\n';
}