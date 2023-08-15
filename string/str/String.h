#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class String {
	size_t size_ = 0;
	char* str_ = nullptr;
public:
	String() = default;

	explicit String(const char* const& str) : size_(strlen(str)), str_(new char[size_ + 1]) {
		memcpy(str_, str, size_ + 1);
	}

	//copy
	String(const String& s) : size_(s.size_), str_(new char[size_ + 1]) {
		memcpy(str_, s.str_, size_ + 1);
	}
	//move
	String(String&& s) : size_(s.size_), str_(s.str_) {
		s.size_ = 0;
		s.str_ = nullptr;
	}

	size_t size() const { return size_; }
	size_t size() { return size_; }

	//хз на сколько это правильно
	char* begin() { return str_; }
	char* end() { return str_ + size_ + 1; }

	bool empty() { return size_; }

	String& operator=(const String& s) {
		delete[] str_;
		size_ = s.size_;
		str_ = new char[size_ + 1];
		memcpy(str_, s.str_, size_ + 1);
		return *this;
	}

	String& operator=(const char* str) {
		delete[] str_;
		size_ = strlen(str);
		str_ = new char[size_ + 1];
		memcpy(str_, str, size_ + 1);
		return *this;
	}

	String& operator=(String&& s) {
		delete[] str_;
		size_ = s.size_;
		str_ = s.str_;
		s.size_ = 0;
		s.str_ = nullptr;
		return *this;
	}

	String& operator+=(const String& s) {
		char* ss = new char[size_ + s.size_ + 1];
		memcpy(ss + size_, s.str_, size_ + 1);
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
		s.str_ = new char[s.size_];
		for (int i = 0; i < a; ++i) {
			memcpy(s.str_ + 1 * i, str_, size_);
		}
		return s;
	}

	char& operator[](int i) const {
		if (i >= 0 && i < size_)
			return str_[i];
		std::cout << "daleko ti polez, drug";
		char a = 0;
		return a;
	}



	~String() {
		delete[] str_;
	}

};

ostream& operator<<(ostream& os, const String& s) {
	for (int i = 0; i < s.size(); ++i) {
		os << s[i];
	}
	return os;
}

//гига не уверен на счет этого
istream& operator>>(istream& in, String& s) {
	in >> s;
	return in;
}