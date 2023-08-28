#include "String.h"


String::String() = default;

String::String(const char* const& str) : size_(strlen(str)), capacity_(size_ + 1), str_(new char[capacity_]) {
	memcpy(str_, str, capacity_);
}

//copy
String::String(const String& s) : size_(s.size_), capacity_(size_ + 1), str_(new char[capacity_]) {
	memcpy(str_, s.str_, capacity_);
}
//move
String::String(String&& s) : size_(s.size_), capacity_(size_ + 1), str_(s.str_) {
	s.size_ = 0;
	s.capacity_ = 1;
	s.str_ = nullptr;
}

String::String(std::string& s) : size_(s.size()), capacity_(size_ + 1), str_(new char[capacity_]) {
	memcpy(str_, s.c_str(), capacity_);
}

size_t String::size() const { return size_; }
size_t String::cap() { return capacity_; }

//ne fact chto pravilno
char* String::begin() { return str_; }
char* String::end() { return str_ + size_; }

bool String::empty() { return size_; }

char& String::operator[](size_t i) const {
	if (i >= 0 && i < size_)
		return str_[i];
	std::cout << "daleko ti polez, drug";
	char a = ' ';
	return a;
}

String String::operator*=(int a) {
	String s;
	s.size_ = size_ * a;
	s.capacity_ = s.size_ + 1;
	s.str_ = new char[s.capacity_];
	for (int i = 0; i < a; ++i) {
		memcpy(s.str_ + size_ * i, str_, size_);
	}
	*this = s;
	return *this;
}

String& String::operator+=(const String& s) {
	capacity_ = (size_ + s.size_) + 1;
	char* ss = new char[capacity_];
	memcpy(ss, str_, size_);
	memcpy(ss + size_ + 1, s.str_, s.size_);
	delete[] str_;
	size_ += s.size_;
	str_ = ss;
	return *this;
}

void String::swap(String& s) {
	std::swap(size_, s.size_);
	std::swap(str_, s.str_);
	std::swap(capacity_, s.capacity_);
}

String& String::operator=(String s) {
	swap(s);
	return *this;
}

String& String::operator=(const char* str) {
	delete[] str_;
	size_ = strlen(str);
	capacity_ = size_ + 1;
	str_ = new char[capacity_];
	memcpy(str_, str, size_);
	return *this;
}

String& String::operator=(String&& s) {
	swap(s);
	s.size_ = 0;
	s.capacity_ = 1;
	s.str_ = nullptr;
	return *this;
}



String operator+(String s_, const String& s) {
	s_ += s;
	return s_;
}



String operator*(String s, int a) {
	s *= a;
	return s;
}



	void String::push_back(const char* c) {
		if (strlen(c) + size_ >= capacity_) {
			while (strlen(c) + size_ >= capacity_) {
				capacity_ *= 2;
			}
			char* str = new char[capacity_];
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
		if (size_ >= capacity_ - 1) {
			capacity_ *= 2;
			char* str = new char[capacity_];
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

size_t String::find(const char* c) {
	for (size_t i = 0; i < size_; ++i) {
		if (c[0] == str_[i]) {

		}
	}
	return 0;
}


String::~String() {
	delete[] str_;
}
//friend istream& operator>>(istream& in, String& s);


