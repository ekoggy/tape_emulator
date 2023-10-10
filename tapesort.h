#pragma once
#include <IOTape.h>
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>



class TapeSort
{
/// FIELDS
public:
	IOTape io_interface;

/// METHODS
public:
	TapeSort(std::string input_tape_path, std::string output_tape_path);
	~TapeSort();
	void sort();
private:
	void merge(std::string src1, std::string src2, std::string dest);
	void distribute();
};
/*
#define _MY_STRING_H_
#ifdef _MY_STRING_H_

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

class MyString
{
	char *string_;
	int len_;
	int volume_;
	void enlarge_to_fit();

public:
	MyString();
	MyString(const char* string);
	MyString(const char* string, int size);
	MyString(int amount, char string);
	MyString(std::string str);
	MyString(const  MyString& other);
	MyString(MyString&& other);

	~MyString()
	{
		delete[] this->string_;
	}

	MyString operator+(const MyString& other)const;// const;
	MyString operator+(const char* str)const;
	MyString operator+(const std::string str)const;

	void operator=(const MyString& other);
	void operator=(const char* str);
	void operator=(const std::string str);
	void operator=(char symbol);

	void operator+=(const MyString& other);
	void operator+=(const char* str);
	void operator+=(const std::string str);
	void operator+=(const char symbol);

	char operator[](int)const;

	bool operator>(const MyString& other)const;
	bool operator<(const MyString& other)const;
	bool operator>=(const MyString& other)const;
	bool operator<=(const MyString& other)const;
	bool operator!=(const MyString& other)const;
	bool operator==(const MyString& other)const;

	const char* c_str()const;
	const char* data()const;

	int lenght()const;
	int size()const;

	bool empty()const;

	int capacity()const;
	void shrink_to_fit();

	void clear();

	friend std::ostream& operator<< (std::ostream& out, const MyString& mystring);
	friend std::istream& operator>>(std::istream& out, MyString& mystring);

	void insert(int index, int count, char symbol);
	void insert(int index, const char* str);
	void insert(int index, const char* str, int count);
	void insert(int index, std::string str);
	void insert(int index, std::string str, int count);

	void erase(int index, int count);

	void append(int amount, char symbol);
	void append(const char* str);
	void append(const char* str, int index, int amount);
	void append(std::string str);
	void append(std::string str, int index, int amount);

	void replace(int index, int count , const char* str);
	void replace(int index, int count, std::string str);

	MyString substr(int index)const;
	MyString substr(int index, int count)const;

	int find(const char* str)const;
	int find(const char* str, int index)const;
	int find(std::string str)const;
	int find(std::string str, int index)const;
};

#endif // _MY_STRING_H_

*/
