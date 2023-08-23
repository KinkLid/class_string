#pragma once
#include "String.h"

std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

//ne rabotaet
std::istream& operator>>(std::istream& in, const char* c) {
	in >> c;
	String s(c);
	return in;
}
