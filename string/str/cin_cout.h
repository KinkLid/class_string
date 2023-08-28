#pragma once
#include "String.h"

std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

//kostili - razmer 255 char
std::istream& operator>>(std::istream& in, String& s) {
	String ss = "";
	char* c = new char[255];
	in >> c;
	ss.push_back(c);
	s = ss;
	return in;
}
