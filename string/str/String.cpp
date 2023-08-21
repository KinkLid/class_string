#include "String.h"


	String::String() = default;

	String::String(const char* const& str) : size_(strlen(str)), cap_(size_ * 2), str_(new char[cap_]) {
		memcpy(str_, str, cap_);
	}

	//copy
	String::String(const String& s) : size_(s.size_), cap_(size_ * 2), str_(new char[cap_]) {
		memcpy(str_, s.str_, cap_);
	}
	//move
	String::String(String&& s) : size_(s.size_), cap_(size_ * 2), str_(s.str_) {
		s.size_ = 0;
		s.cap_ = 1;
		s.str_ = nullptr;
	}

	size_t String::size() const { return size_; }
	size_t String::size() { return size_; }

	//ne fact chto pravilno
	char* String::begin() { return str_; }
	char* String::end() { return str_ + size_; }

	bool String::empty() { return size_; }

	String& String::operator=(const String& s) {
		delete[] str_;
		size_ = s.size_;
		cap_ = s.cap_;
		str_ = new char[cap_];
		memcpy(str_, s.str_, size_);
		return *this;
	}

	String& String::operator=(const char* str) {
		delete[] str_;
		size_ = strlen(str);
		cap_ = size_ * 2;
		str_ = new char[cap_];
		memcpy(str_, str, size_);
		return *this;
	}

	String& String::operator=(String&& s) {
		delete[] str_;
		size_ = s.size_;
		cap_ = s.cap_;
		str_ = s.str_;
		s.size_ = 0;
		s.cap_ = 1;
		s.str_ = nullptr;
		return *this;
	}

	String& String::operator+=(const String& s) {
		cap_ = (size_ + s.size_) * 2;
		char* ss = new char[cap_];
		memcpy(ss, str_, size_);
		memcpy(ss + size_ + 1, s.str_, s.size_);
		delete[] str_;
		size_ = size_ + s.size_;
		str_ = ss;
		return *this;
	}

	String String::operator+(const String& s) {
		String ss = *this;
		ss += s;
		return ss;
	}

	String String::operator*(int a) {
		String s;
		s.size_ = size_ * a;
		s.cap_ = s.size_ * 2;
		s.str_ = new char[s.cap_];
		for (int i = 0; i < a; ++i) {
			memcpy(s.str_ + 1 * i, str_, size_);
		}
		return s;
	}

	char& String::operator[](size_t i) const {
		if (i >= 0 && i <= size_)
			return str_[i];
		std::cout << "daleko ti polez, drug";
		char a = ' ';
		return a;
	}

	void String::push_back(const char* c) {
	if(strlen(c) + size_ >= cap_)
		while (strlen(c) + size_ >= cap_) {
			cap_ *= 2;
			char* str = new char[cap_];
			memcpy(str, str_, size_);
			memcpy(str + size_, c, strlen(c));
			delete[] str_;
			str_ = str;
		}
	else {
		memcpy(str_ + size_, c, strlen(c));
	}
	size_ += strlen(c);
}

void String::push_back(char c) {
	if (size_ >= cap_ - 1) {
		cap_ *= 2;
		char* str = new char[cap_];
		memcpy(str, str_, size_);
		str[size_] = c;
		delete[] str_;
		str_ = str;
	}
	else {
		str_[size_] = c;
	}
	size_ += 1;
}

	String String::sub(size_t begin, size_t end) {
		String s;
		s.size_ = end - begin + 1;
		s.str_ = new char[s.size_];
		memcpy(s.str_, str_ + begin - 1, s.size_);
		return s;
	}


	String::~String() {
		delete[] str_;
	}
	//friend istream& operator>>(istream& in, String& s);

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
