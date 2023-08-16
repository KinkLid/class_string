#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class String {
	size_t size_ = 0;
	size_t cap_ = 1; // capasity
	char* str_ = nullptr;
	
public:
	
	String() = default;

	explicit String(const char* const& str) : size_(strlen(str)), cap_(size_ * 2),  str_(new char[cap_]) {
		memcpy(str_, str, cap_);
	}

	//copy
	String(const String& s) : size_(s.size_), cap_(size_ * 2), str_(new char[cap_]) {
		memcpy(str_, s.str_, cap_);
	}
	//move
	String(String&& s) : size_(s.size_), cap_(size_ * 2), str_(s.str_) {
		s.size_ = 0;
		s.cap_ = 1;
		s.str_ = nullptr;
	}

	size_t size() const { return size_; }
	size_t size() { return size_; }

	//ne fact chto pravilno
	char* begin() { return str_; }
	char* end() { return str_ + size_; }

	bool empty() { return size_; }

	String& operator=(const String& s) {
		delete[] str_;
		size_ = s.size_;
		cap_ = s.cap_;
		str_ = new char[cap_];
		memcpy(str_, s.str_, size_);
		return *this;
	}

	String& operator=(const char* str) {
		delete[] str_;
		size_ = strlen(str);
		cap_ = size_ * 2;
		str_ = new char[cap_];
		memcpy(str_, str, size_);
		return *this;
	}

	String& operator=(String&& s) {
		delete[] str_;
		size_ = s.size_;
		cap_ = s.cap_;
		str_ = s.str_;
		s.size_ = 0;
		s.cap_ = 1;
		s.str_ = nullptr;
		return *this;
	}

	String& operator+=(const String& s) {
		cap_ = (size_ + s.size_) * 2;
		char* ss = new char[cap_];
		memcpy(ss, str_, size_);
		memcpy(ss + size_ + 1, s.str_, s.size_);
		delete[] str_;
		size_ = size_ + s.size_;
		str_ = ss;
		return *this;
	}

	String operator+(const String& s) {
		String ss = *this;
		ss += s;
		return ss;
	}

	String operator*(int a) {
		String s;
		s.size_ = size_ * a;
		s.cap_ = s.size_ * 2;
		s.str_ = new char[s.cap_];
		for (int i = 0; i < a; ++i) {
			memcpy(s.str_ + 1 * i, str_, size_);
		}
		return s;
	}

	char& operator[](size_t i) const {
		if (i >= 0 && i <= size_)
			return str_[i];
		std::cout << "daleko ti polez, drug";
		char a = ' ';
		return a;
	}

	void push_back(const char* c) {
		if (strlen(c) + size_ >= cap_){
			cap_ *= 2;
			char* str = new char[cap_];
			memcpy(str, str_, size_);
			memcpy(str + size_ + 1, c, strlen(c));
			delete[] str_;
			str_ = str;
			size_ += strlen(c);
		}

	}


	~String() {
		delete[] str_;
	}
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
