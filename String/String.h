#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define DEL "-------------------------------------------------\n"

//class Binary;

////////////////////////////////////////////////////////////////////////////////////////
////////////		CLASS DECLARATION - объявление класса		////////////////////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

//class Binary
//{
//	char* str10;
//	int size10;
//
//public:
//
//
//
//	const char* get_str10()const
//	{
//		return str10;
//	}
//
//	char* get_str10()
//	{
//		return str10;
//	}
//
//	int get_size10()const
//	{
//		return size10;
//	}
//
//
//	//		Constructors
//
//	explicit Binary(int size = 80)
//	 {
//		this->size10 = size;
//		this->str10 = new char[size] {};
//		cout << (size == 80 ? "Default" : "Size") << "Constructor: \t" << this << endl;
//	}
//
//	Binary(const char* str10)
//	{
//		this->size10 = strlen(str10) + 1;
//		this->str10 = new char[size10] {};
//		strcpy(this->str10, str10);			//String copy	
//		//strcpy_s(this->str, size, str);
//		cout << "Constructor: \t\t" << this << endl;
//	}
//
//	Binary(const Binary& other)
//	{
//		this->size10 = other.size10;
//		this->str10 = new char[size10] {};
//		strcpy(this->str10, other.str10);
//		cout << "CopyConstractor:\t" << this << endl;
//	}
//
//	~Binary()
//	{
//		delete[] this->str10;
//		cout << "Destructor: \t\t" << this << endl;
//	}
//
//
//	//		Methods
//
//	void print()const
//	{
//		cout << "str10: \t" << str10 << endl;
//		cout << "size10 \t" << size10 << endl;
//	}
//};

class String
{
	char* str;		//Указатель на строоку в динамической памяти
	int size;		//Размер строки

public:

	const char* get_str()const;

	char* get_str();

	int get_size()const;


	//		Constructors

	explicit String(int size = 80);

	String(const char* str);

	String(const String& other);

	String(String&& other);

	~String();


	//		Operators

	String& operator=(const String& other);

	String& operator=(String&& other);

	String& operator+=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	//		Methods

	void print()const;
};

////////////		CLASS DECLARATION END		////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
