#pragma once
#include <iostream>
#include <cstring>

class String {
	size_t size_ = 0;
	size_t capacity_ = 1; // capasity
	char* str_ = nullptr;
	
public:
	
	String();

	explicit String(const char* const&);
	String(const String&);
	String(String&&);
	String(std::string&);

	size_t size() const;
	size_t cap();

	//ne fact chto pravilno
	char* begin();
	char* end();
	bool empty();

	char& operator[](size_t) const;
	String& operator+=(const String&);
	String operator*=(int a);

	void swap(String&);

	String& operator=(String);
	String& operator=(const char*);
	String& operator=(String&&);
	friend String operator+(String, const String&);
	friend String operator*(String, int);

	void push_back(const char*);
	void push_back(char);
	String sub(size_t, size_t);
	size_t find(const char* c);


	~String();
	friend std::istream& operator>>(std::istream&, String&);
};

