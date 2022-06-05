#pragma once
int gexToInt(std::string gex) {
	return (gex[1] - 33) * 16 + gex[0] - 33;
}