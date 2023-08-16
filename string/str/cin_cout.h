#pragma once
#include "String.h"

ostream& operator<<(ostream& os, const String& s) {
	for (size_t i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

//ne rabotaet
istream& operator>>(istream& in, const char* c) {
	in >> c;
	String s(c);
	return in;
}
