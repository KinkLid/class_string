#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class String {
	size_t size_ = 0;
	size_t cap_ = 1; // capasity
	char* str_ = nullptr;
	
public:
	
	String();

	explicit String(const char* const&);
	String(const String&);
	String(String&&);

	size_t size() const;
	size_t size();

	//ne fact chto pravilno
	char* begin();
	char* end();
	bool empty();

	String& operator=(const String&);
	String& operator=(const char*);
	String& operator=(String&&);
	String& operator+=(const String&);
	String operator+(const String&);
	String operator*(int);
	char& operator[](size_t) const;

	void push_back(const char*);


	~String();
	//friend istream& operator>>(istream& in, String& s);
};
/*
ostream& operator<<(ostream& os, const String& s) {
	for (size_t i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

//hz rabotaet li
istream& operator>>(istream& in, String& s) {
	in >> s;
	return in;
}*/
